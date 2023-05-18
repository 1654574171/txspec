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

func (k Keeper) RewardListAll(c context.Context, req *types.QueryAllRewardListRequest) (*types.QueryAllRewardListResponse, error) {
	if req == nil {
		return nil, status.Error(codes.InvalidArgument, "invalid request")
	}

	var rewardLists []types.RewardList
	ctx := sdk.UnwrapSDKContext(c)

	store := ctx.KVStore(k.storeKey)
	rewardListStore := prefix.NewStore(store, types.KeyPrefix(types.RewardListKeyPrefix))

	pageRes, err := query.Paginate(rewardListStore, req.Pagination, func(key []byte, value []byte) error {
		var rewardList types.RewardList
		if err := k.cdc.Unmarshal(value, &rewardList); err != nil {
			return err
		}

		rewardLists = append(rewardLists, rewardList)
		return nil
	})

	if err != nil {
		return nil, status.Error(codes.Internal, err.Error())
	}

	return &types.QueryAllRewardListResponse{RewardList: rewardLists, Pagination: pageRes}, nil
}

func (k Keeper) RewardList(c context.Context, req *types.QueryGetRewardListRequest) (*types.QueryGetRewardListResponse, error) {
	if req == nil {
		return nil, status.Error(codes.InvalidArgument, "invalid request")
	}
	ctx := sdk.UnwrapSDKContext(c)

	val, found := k.GetRewardList(
		ctx,
		req.ContractAddress,
	)
	if !found {
		return nil, status.Error(codes.NotFound, "not found")
	}

	return &types.QueryGetRewardListResponse{RewardList: val}, nil
}
