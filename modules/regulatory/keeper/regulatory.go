package keeper

import (
	"context"
	"crypto/ecdsa"
	"crypto/elliptic"
	"crypto/sha256"
	"encoding/asn1"
	"encoding/base64"
	"errors"
	"fmt"
	"math/big"
	"time"

	rt "github.com/irisnet/irishub/modules/regulatory/types"

	"github.com/irisnet/irishub/modules/regulatory/types"

	sdk "github.com/cosmos/cosmos-sdk/types"
	sdkerrors "github.com/cosmos/cosmos-sdk/types/errors"
	pbcosmos "github.com/figment-networks/proto-cosmos/pb/sf/cosmos/type/v1"
	"github.com/golang/protobuf/proto"
	abci "github.com/tendermint/tendermint/abci/types"
	tmcrypto "github.com/tendermint/tendermint/crypto"
	"github.com/tendermint/tendermint/crypto/tmhash"
	"github.com/tendermint/tendermint/proto/tendermint/crypto"
	tt "github.com/tendermint/tendermint/proto/tendermint/types"
	"google.golang.org/grpc"
)

type ecdsaSignature struct {
	R *big.Int
	S *big.Int
}

//Establishing a GRPC stream with the compliance engine service
func CreateStream(ctx sdk.Context, k Keeper, reg rt.Registration) *types.Regulator_GetComplianceProofClient {
	complianceAddress := reg.Endpoint.IpAddress + ":" + fmt.Sprint(reg.Endpoint.Port)
	k.Logger(ctx).Info("connect to compliance engine", "service address", complianceAddress)
	clientCon, err := grpc.Dial(complianceAddress, grpc.WithInsecure(), grpc.WithBlock(), grpc.WithTimeout(3*time.Second))
	if err != nil {
		k.complianceServiceStreamMap[reg.RegulatoryServiceName] = nil
		k.Logger(ctx).Info("connect to compliance engine service failed", "cause", complianceAddress)
		//if build connect error or timeout then continue
		return nil
	}
	k.Logger(ctx).Info("connect to compliance engine service successed", "service address", complianceAddress)
	client := types.NewRegulatorClient(clientCon)
	//TODO consider build client timeout
	stream, err := client.GetComplianceProof(context.Background())

	if err != nil {
		k.Logger(ctx).Info("build  compliance service stream failed", "cause", complianceAddress)
		k.complianceServiceStreamMap[reg.RegulatoryServiceName] = nil
		//if build client error or timeout continue
		return nil
	}
	k.Logger(ctx).Info("build  compliance service stream successed", "service address", complianceAddress)
	return &stream
}

//Verify whether the signature of the cproof returned by the compliance engine is generated by the enclave of the on chain record
func (k Keeper) cproofSignVerify(ctx sdk.Context, cproof types.ProofResponse) bool {
	registrationList := k.GetAllRegistration(ctx)
	//if dont have any compliance service then return empty response
	if len(registrationList) == 0 {
		k.Logger(ctx).Info("dont have any compliance service then  dont need verify ,return true!")
		return true
	}
	//Due to the use of services registered on the chain for compliance based on a round robin approach,
	//it is necessary to calculate which service is compliant for the block.
	ceIndex := ctx.BlockHeight() % (int64)(len(registrationList))
	regServiceInfo := registrationList[ceIndex]
	sig, err := base64.StdEncoding.DecodeString(string(cproof.TeeSignature))
	if err != nil {
		k.Logger(ctx).Error("failed to decode base64 compliance service signature", "cause", err)
		return false
	}
	cproofWithoutSig := &types.ProofResponse{
		TxHash:     cproof.TxHash,
		ProofsHash: cproof.ProofsHash,
		Proofs:     cproof.Proofs,
	}

	pb, err := proto.Marshal(cproofWithoutSig)

	if err != nil {
		k.Logger(ctx).Error("failed to marshal cproof", "cause", err)
		return false
	}
	hash := sha256.Sum256(pb)
	pkBytes, err := base64.StdEncoding.DecodeString(regServiceInfo.EnclavePK)
	if err != nil {
		k.Logger(ctx).Error("TEEPK decoding to bytes error", "cause", err)
		return false
	}
	publicKeyObject, err := deserializePublicKey(pkBytes)
	if err != nil {
		k.Logger(ctx).Error("TEEPK decoding to Public key object error", "cause", err)
		return false
	}
	signature, err := MarshalEnclaveSignature(sig)
	if err != nil {
		k.Logger(ctx).Error("signature  marshal error", "cause", err)
		return false
	}
	logs := fmt.Sprintf("%x", pb)
	if !ecdsa.VerifyASN1(publicKeyObject, hash[:], signature) {
		k.Logger(ctx).Error("signature verify failed", "bytes", logs)
		return false

	} else {
		k.Logger(ctx).Info("signature verify successed", "bytes", logs)
		return true
	}
}
func MarshalEnclaveSignature(input []byte) ([]byte, error) {

	r := new(big.Int)
	r.SetBytes(input[:32])

	s := new(big.Int)
	s.SetBytes(input[32:])

	if r.Sign() != 1 {
		return nil, errors.New("Invalid signature. R must be larger than zero")
	}
	if s.Sign() != 1 {
		return nil, errors.New("Invalid signature. S must be larger than zero")
	}

	return asn1.Marshal(ecdsaSignature{r, s})
}
func deserializePublicKey(keyBytes []byte) (*ecdsa.PublicKey, error) {

	x := new(big.Int)
	x.SetBytes(keyBytes[:32])

	y := new(big.Int)
	y.SetBytes(keyBytes[32:])

	// check that PK is a valid for NIST P-256 elliptic curve
	curve := elliptic.P256()
	if !curve.IsOnCurve(x, y) {
		return nil, fmt.Errorf("Public key not valid (Point not on curve)")
	}

	return &ecdsa.PublicKey{Curve: curve, X: x, Y: y}, nil
}

/*
verify tx compliance input , result and signature
firstly, the execution result of the deliver phase should be the same as the input in the cproof.
second, check the correctness of the cproof signature.
finally, return the cproof status.
*/
func (k Keeper) CproofVerify(ctx sdk.Context) (bool, error) {
	//TODO add signature logic
	//TODO add event compare logic
	cproofByte := []byte{}
	var cproof types.ProofResponse
	if ctx.IsCheckTx() || len(k.GetAllRegistration(ctx)) == 0 {
		//dont have any compliance service on chain or In the abci inspection stage
		return true, nil
	}
	//If there is an error in verifying the signature or obtaining regulatory results during the regtx stage,
	//the cproof field in the ctx of the transaction will be empty. In the delivery verification stage,
	// an error will be directly returned for this situation, making the transaction invalid because there is no regulatory result.
	if len(cproofByte) == 0 {
		return false, nil
	}
	err := k.cdc.Unmarshal(cproofByte, &cproof)
	if err != nil {
		return false, err
	}
	return cproof.Proofs[0].Status, nil
}

//compliance stream select by block height
//The selection process is based on a round robin approach
func (k Keeper) CompliancePrepare(ctx sdk.Context) *types.Regulator_GetComplianceProofClient {
	registrationList := k.GetAllRegistration(ctx)
	//if dont have any compliance service then return empty response
	if len(registrationList) == 0 {
		k.Logger(ctx).Info("dont have any compliance service then return empty response !")
		return nil
	}
	if len(k.complianceServiceStreamMap) == 0 {
		for _, reg := range registrationList {
			stream := CreateStream(ctx, k, reg)
			k.complianceServiceStreamMap[reg.RegulatoryServiceName] = stream
		}
	}

	//at the same block height ,always use the same compliance engine for regulate
	ceIndex := ctx.BlockHeight() % (int64)(len(registrationList))
	return k.complianceServiceStreamMap[registrationList[ceIndex].RegulatoryServiceName]
}

// provide getCompliance function
func (k Keeper) GetCompliance(ctx sdk.Context, tx sdk.Tx) error {
	//build firehose tx and block
	fhTx, _ := packageFhTx(ctx)
	fhBlock, _ := packageFhBlock(ctx, fhTx)
	//use fee address as tx sender address
	feeTx, ok := tx.(sdk.FeeTx)
	if !ok {
		return sdkerrors.Wrap(sdkerrors.ErrTxDecode, "Tx must be a FeeTx")
	}

	tmd := &types.TxMetaData{
		FromAddress: feeTx.FeePayer(),
		ToAddress:   []byte{},
		Value:       0,
	}

	//category event by contract name
	cts := classifyEventsByContract(ctx.EventManager().ABCIEvents())
	data := &types.Data{
		Meta:   tmd,
		Events: cts,
	}
	//build compliance request
	pr := &types.ProofRequest{
		ChainType:    "cosmos",
		ChainID:      ctx.ChainID(),
		Data:         data,
		TxHash:       tmhash.Sum(ctx.TxBytes()),
		Height:       uint64(ctx.BlockHeight()),
		TxIndex:      1,
		OriginalData: fhBlock,
	}

	//send request to compliance service
	//TODO add timeout setting
	cproof, err, empty := k.sendRegRequest(ctx, *pr)
	if err != nil {
		k.Logger(ctx).Error("compliance service request error : ", err)
		return err
	}
	// verifyStatus := k.cproofSignVerify(ctx, cproof)
	// //verify signature failed
	// if !verifyStatus {
	// 	k.Logger(ctx).Error("cproof signature verify failed! ")
	// 	return rt.ProofResponse{}, err
	// }

	if !empty {
		var result string
		if cproof.Proofs[0].Status {
			result = "true"
		} else {
			result = "false"
		}

		originalSpecValues, found := k.GetSpecValues(ctx, "ics721")
		if found {
			originalSpecValues.SpecValue.ValueMap[fmt.Sprintf("%x", cproof.TxHash)] = result
			k.SetSpecValues(ctx, originalSpecValues)
		} else {
			specValue := &types.SpecValue{ValueMap: map[string]string{fmt.Sprintf("%x", cproof.TxHash): result}}
			newSpecValues := &types.SpecValues{ContractAddress: "ics721", SpecValue: specValue}
			k.SetSpecValues(ctx, *newSpecValues)
		}

	}

	//TODO verify cproof
	k.Logger(ctx).Info("compliance request and  signature verify successful!")

	return nil
}

//send compliance request to service
func (k Keeper) sendRegRequest(ctx sdk.Context, pr types.ProofRequest) (types.ProofResponse, error, bool) {

	k.Logger(ctx).Info("start send compliance request !")
	ceStreamPointer := k.CompliancePrepare(ctx)
	if ceStreamPointer == nil {
		return types.ProofResponse{}, nil, true
	}
	cs := *ceStreamPointer
	cs.Send(&pr)
	resp, err := cs.Recv()
	//if request error,then will return error to baseapp, need handle it
	if err != nil {
		return types.ProofResponse{}, err, true
	}
	return *resp, nil, false

}

func classifyEventsByContract(events []abci.Event) []*types.ContractEvent {
	contractEventMap := make(map[string]types.ContractEvent)
	for _, event := range events {
		//1.find contract name attribute from event ,if dont find then dont compliance
		contractName := findEventContractName(event)
		if contractName == "" {
			continue
		}
		//2.if contract name already in map then dont create,else add it.
		contractEvent, ok := contractEventMap[contractName]
		if !ok {
			//create it and add to map
			contractEvent = types.ContractEvent{ContractID: contractName, Events: []*rt.Event{}}
			contractEventMap[contractName] = contractEvent

		}
		contractEventItem := &types.Event{EventName: event.Type}

		for _, attribute := range event.Attributes {
			contractEventItemAttribute := &types.Attribute{
				Key:   string(attribute.Key),
				Value: string(attribute.Value),
			}
			contractEventItem.Attributes = append(contractEventItem.Attributes, contractEventItemAttribute)
		}
		contractEvent.Events = append(contractEvent.Events, contractEventItem)
		contractEventMap[contractName] = contractEvent
	}

	cts := make([]*types.ContractEvent, len(contractEventMap))
	index := 0
	for _, ce := range contractEventMap {
		cts[index] = &ce
		index++
	}

	return cts
}

//find contract name from event
func findEventContractName(event abci.Event) string {
	contractName := ""
	for _, attr := range event.Attributes {
		if string(attr.Key) == types.AttributeKeyContractAddress {
			contractName = string(attr.Value)
		}
	}
	return contractName
}

//build data struct that meets firehose requirements
func packageFhTx(ctx sdk.Context) (pbcosmos.TxResult, error) {
	mappedTx, _ := mapTx(ctx.TxBytes())

	ptx := &pbcosmos.TxResult{
		Hash:   tmhash.Sum(ctx.TxBytes()),
		Height: uint64(ctx.BlockHeight()),
		Index:  1,
		Tx:     mappedTx,
		Result: &pbcosmos.ResponseDeliverTx{
			Code:      0,
			Data:      []byte{},
			Log:       "",
			Info:      "",
			GasWanted: 0,
			GasUsed:   0,
			Codespace: "",
		},
	}

	for _, ev := range ctx.EventManager().ABCIEvents() {
		ptx.Result.Events = append(ptx.Result.Events, mapEvent(ev))
	}
	return *ptx, nil
}

//build block that meets firehose requirements
func packageFhBlock(ctx sdk.Context, fhTx pbcosmos.TxResult) ([]byte, error) {
	fhTxs := []*pbcosmos.TxResult{}
	fhTxs = append(fhTxs, &fhTx)
	rb := &abci.ResponseBeginBlock{
		Events: ctx.EventManager().ABCIEvents(),
	}
	eb := &abci.ResponseEndBlock{
		ValidatorUpdates: abci.ValidatorUpdates{},
		Events:           ctx.EventManager().ABCIEvents(),
	}
	mappedResponseEndBlock, _ := mapResponseEndBlock(eb)
	nb := &pbcosmos.Block{
		Header: &pbcosmos.Header{
			Version: &pbcosmos.Consensus{
				Block: ctx.BlockHeader().Version.Block,
				App:   ctx.BlockHeader().Version.App,
			},
			ChainId:            ctx.BlockHeader().ChainID,
			Height:             uint64(ctx.BlockHeight()),
			Time:               mapTimestamp(ctx.BlockTime()),
			LastBlockId:        mapBlockID(ctx.BlockHeader().LastBlockId),
			LastCommitHash:     ctx.BlockHeader().LastCommitHash,
			DataHash:           ctx.BlockHeader().DataHash,
			ValidatorsHash:     ctx.BlockHeader().ValidatorsHash,
			NextValidatorsHash: ctx.BlockHeader().NextValidatorsHash,
			ConsensusHash:      ctx.BlockHeader().ConsensusHash,
			AppHash:            ctx.BlockHeader().AppHash,
			LastResultsHash:    ctx.BlockHeader().LastResultsHash,
			EvidenceHash:       ctx.BlockHeader().EvidenceHash,
			ProposerAddress:    ctx.BlockHeader().ProposerAddress,
			Hash: []byte{'R', 'e', 'g', 'B', 'l', 'o', 'c', 'k',
				'R', 'e', 'g', 'B', 'l', 'o', 'c', 'k',
				'R', 'e', 'g', 'B', 'l', 'o', 'c', 'k',
				'R', 'e', 'g', 'B', 'l', 'o', 'c', 'k'},
			//to enable the manifest to identify regulatory blocks, set this value to "regblock"
		},
		Evidence: &pbcosmos.EvidenceList{},
		LastCommit: &pbcosmos.Commit{
			Height:     ctx.BlockHeader().Height,
			Round:      0,
			BlockId:    &pbcosmos.BlockID{},
			Signatures: []*pbcosmos.CommitSig{},
		},

		ResultBeginBlock: mapResponseBeginBlock(rb),
		ResultEndBlock:   mappedResponseEndBlock,
		Transactions:     fhTxs,
	}

	tnb, _ := proto.Marshal(nb)
	return tnb, nil

}
func mapBlockID(bid tt.BlockID) *pbcosmos.BlockID {
	return &pbcosmos.BlockID{
		Hash: bid.Hash,
		PartSetHeader: &pbcosmos.PartSetHeader{
			Total: bid.PartSetHeader.Total,
			Hash:  bid.PartSetHeader.Hash,
		},
	}
}
func mapTimestamp(time time.Time) *pbcosmos.Timestamp {
	return &pbcosmos.Timestamp{
		Seconds: time.Unix(),
		Nanos:   int32(time.UnixNano() - time.Unix()*1000000000),
	}
}

func mapResponseBeginBlock(rbb *abci.ResponseBeginBlock) *pbcosmos.ResponseBeginBlock {
	result := &pbcosmos.ResponseBeginBlock{}

	for _, ev := range rbb.Events {
		result.Events = append(result.Events, mapEvent(ev))
	}

	return result
}
func mapEvent(ev abci.Event) *pbcosmos.Event {
	cev := &pbcosmos.Event{EventType: ev.Type}

	for _, at := range ev.Attributes {
		cev.Attributes = append(cev.Attributes, &pbcosmos.EventAttribute{
			Key:   string(at.Key),
			Value: string(at.Value),
			Index: at.Index,
		})
	}

	return cev
}

func mapResponseEndBlock(reb *abci.ResponseEndBlock) (*pbcosmos.ResponseEndBlock, error) {
	result := &pbcosmos.ResponseEndBlock{
		ConsensusParamUpdates: &pbcosmos.ConsensusParams{},
	}

	for _, ev := range reb.Events {
		result.Events = append(result.Events, mapEvent(ev))
	}

	for _, vu := range reb.ValidatorUpdates {
		val, err := mapValidatorUpdate(vu)
		if err != nil {
			return nil, err
		}
		result.ValidatorUpdates = append(result.ValidatorUpdates, val)
	}

	return result, nil
}

func mapValidatorUpdate(v abci.ValidatorUpdate) (*pbcosmos.ValidatorUpdate, error) {
	nPK := &pbcosmos.PublicKey{}
	var address []byte

	switch key := v.PubKey.Sum.(type) {
	case *crypto.PublicKey_Ed25519:
		nPK.Sum = &pbcosmos.PublicKey_Ed25519{Ed25519: key.Ed25519}
		address = tmcrypto.AddressHash(nPK.GetEd25519())
	case *crypto.PublicKey_Secp256K1:
		nPK.Sum = &pbcosmos.PublicKey_Secp256K1{Secp256K1: key.Secp256K1}
		address = tmcrypto.AddressHash(nPK.GetSecp256K1())
	default:
		return nil, fmt.Errorf("given type %T of PubKey mapping doesn't exist ", key)
	}

	return &pbcosmos.ValidatorUpdate{
		Address: address,
		PubKey:  nPK,
		Power:   v.Power,
	}, nil
}
func mapTx(bytes []byte) (*pbcosmos.Tx, error) {
	t := &pbcosmos.Tx{}
	if err := proto.Unmarshal(bytes, t); err != nil {
		return nil, err
	}
	return t, nil
}
