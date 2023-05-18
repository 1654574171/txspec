package keeper

import (
	"fmt"

	"github.com/irisnet/irishub/modules/regulatory/types"

	"github.com/cosmos/cosmos-sdk/codec"
	storetypes "github.com/cosmos/cosmos-sdk/store/types"
	sdk "github.com/cosmos/cosmos-sdk/types"
	paramtypes "github.com/cosmos/cosmos-sdk/x/params/types"
	"github.com/tendermint/tendermint/libs/log"
)

type (
	Keeper struct {
		cdc                        codec.BinaryCodec
		storeKey                   storetypes.StoreKey
		memKey                     storetypes.StoreKey
		paramstore                 paramtypes.Subspace
		complianceServiceStreamMap map[string]*types.Regulator_GetComplianceProofClient
	}
)

func NewKeeper(
	cdc codec.BinaryCodec,
	storeKey,
	memKey storetypes.StoreKey,
	ps paramtypes.Subspace,

) *Keeper {
	// set KeyTable if it has not already been set
	if !ps.HasKeyTable() {
		ps = ps.WithKeyTable(types.ParamKeyTable())
	}

	return &Keeper{

		cdc:                        cdc,
		storeKey:                   storeKey,
		memKey:                     memKey,
		paramstore:                 ps,
		complianceServiceStreamMap: make(map[string]*types.Regulator_GetComplianceProofClient),
	}
}

func (k Keeper) Logger(ctx sdk.Context) log.Logger {
	return ctx.Logger().With("module", fmt.Sprintf("x/%s", types.ModuleName))
}

func (k Keeper) UpdateComplianceServiceStreamMap(stream *types.Regulator_GetComplianceProofClient, OperationType, complianceServiceName string) error {

	switch OperationType {
	case "insert", "update":
		{
			k.complianceServiceStreamMap[complianceServiceName] = stream
			return nil
		}

	case "delete":
		{
			delete(k.complianceServiceStreamMap, complianceServiceName)
			return nil
		}
	default:
		return types.ErrEntityNonExists
	}

}
