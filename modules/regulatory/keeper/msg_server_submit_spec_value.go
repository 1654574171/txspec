package keeper

import (
	"context"

	"github.com/irisnet/irishub/modules/regulatory/types"

	sdk "github.com/cosmos/cosmos-sdk/types"
)

func (k msgServer) SubmitSpecValue(goCtx context.Context, msg *types.MsgSubmitSpecValue) (*types.MsgSubmitSpecValueResponse, error) {
	ctx := sdk.UnwrapSDKContext(goCtx)

	//cproof verify
	//TODO

	originalSpecValues, found := k.GetSpecValues(ctx, msg.ContractAddress)
	if found {
		originalSpecValues.SpecValue.ValueMap[msg.RelatedTxHash] = msg.Data
		k.SetSpecValues(ctx, originalSpecValues)
	} else {
		specValue := &types.SpecValue{ValueMap: map[string]string{msg.RelatedTxHash: msg.Data}}
		newSpecValues := &types.SpecValues{ContractAddress: msg.ContractAddress, SpecValue: specValue}
		k.SetSpecValues(ctx, *newSpecValues)
	}

	return &types.MsgSubmitSpecValueResponse{}, nil
}
