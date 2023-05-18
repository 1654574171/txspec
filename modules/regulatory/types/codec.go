package types

import (
	"github.com/cosmos/cosmos-sdk/codec"
	cdctypes "github.com/cosmos/cosmos-sdk/codec/types"

	sdk "github.com/cosmos/cosmos-sdk/types"
	"github.com/cosmos/cosmos-sdk/types/msgservice"
	govtypes "github.com/cosmos/cosmos-sdk/x/gov/types/v1beta1"
)

func RegisterCodec(cdc *codec.LegacyAmino) {
	cdc.RegisterConcrete(&MsgSubmitSpecValue{}, "regulatory/SubmitSpecValue", nil)
	// this line is used by starport scaffolding # 2
	cdc.RegisterConcrete(&RuleProposal{}, "cosmos-sdk/RuleProposal", nil)
	cdc.RegisterConcrete(&BindingProposal{}, "cosmos-sdk/BindingProposal", nil)
	cdc.RegisterConcrete(&RelationProposal{}, "cosmos-sdk/RelationProposal", nil)
	cdc.RegisterConcrete(&RegisterProposal{}, "cosmos-sdk/RegisterProposal", nil)
	cdc.RegisterConcrete(&SuspiciousProposal{}, "cosmos-sdk/SuspiciousProposal", nil)
	cdc.RegisterConcrete(&RewardListProposal{}, "cosmos-sdk/RewardListProposal", nil)
}

func RegisterInterfaces(registry cdctypes.InterfaceRegistry) {
	registry.RegisterImplementations((*sdk.Msg)(nil),
		&MsgSubmitSpecValue{},
	)
	// this line is used by starport scaffolding # 3
	registry.RegisterImplementations(
		(*govtypes.Content)(nil),
		&RuleProposal{},
		&BindingProposal{},
		&RelationProposal{},
		&RegisterProposal{},
		&SuspiciousProposal{},
		&RewardListProposal{},
	)
	msgservice.RegisterMsgServiceDesc(registry, &_Msg_serviceDesc)
}

var (
	Amino     = codec.NewLegacyAmino()
	ModuleCdc = codec.NewProtoCodec(cdctypes.NewInterfaceRegistry())
)
