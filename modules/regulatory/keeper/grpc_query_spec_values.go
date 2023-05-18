package keeper

import (
	"context"

	"github.com/cosmos/cosmos-sdk/store/prefix"
	sdk "github.com/cosmos/cosmos-sdk/types"
	"github.com/cosmos/cosmos-sdk/types/query"
	"github.com/irisnet/irishub/modules/regulatory/types"
	"google.golang.org/grpc/codes"
	"google.golang.org/grpc/status"
)

func (k Keeper) SpecValuesAll(c context.Context, req *types.QueryAllSpecValuesRequest) (*types.QueryAllSpecValuesResponse, error) {
	if req == nil {
		return nil, status.Error(codes.InvalidArgument, "invalid request")
	}

	var specValuess []types.SpecValues
	ctx := sdk.UnwrapSDKContext(c)

	store := ctx.KVStore(k.storeKey)
	specValuesStore := prefix.NewStore(store, types.KeyPrefix(types.SpecValuesKeyPrefix))

	pageRes, err := query.Paginate(specValuesStore, req.Pagination, func(key []byte, value []byte) error {
		var specValues types.SpecValues
		if err := k.cdc.Unmarshal(value, &specValues); err != nil {
			return err
		}

		specValuess = append(specValuess, specValues)
		return nil
	})

	if err != nil {
		return nil, status.Error(codes.Internal, err.Error())
	}

	return &types.QueryAllSpecValuesResponse{SpecValues: specValuess, Pagination: pageRes}, nil
}

func (k Keeper) SpecValues(c context.Context, req *types.QueryGetSpecValuesRequest) (*types.QueryGetSpecValuesResponse, error) {
	if req == nil {
		return nil, status.Error(codes.InvalidArgument, "invalid request")
	}
	ctx := sdk.UnwrapSDKContext(c)

	val, found := k.GetSpecValues(
		ctx,
		req.ContractAddress,
	)
	if !found {
		return nil, status.Error(codes.NotFound, "not found")
	}

	return &types.QueryGetSpecValuesResponse{SpecValues: val}, nil
}
