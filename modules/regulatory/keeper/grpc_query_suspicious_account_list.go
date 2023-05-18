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

func (k Keeper) SuspiciousAccountListAll(c context.Context, req *types.QueryAllSuspiciousAccountListRequest) (*types.QueryAllSuspiciousAccountListResponse, error) {
	if req == nil {
		return nil, status.Error(codes.InvalidArgument, "invalid request")
	}

	var suspiciousAccountLists []types.SuspiciousAccountList
	ctx := sdk.UnwrapSDKContext(c)

	store := ctx.KVStore(k.storeKey)
	suspiciousAccountListStore := prefix.NewStore(store, types.KeyPrefix(types.SuspiciousAccountListKeyPrefix))

	pageRes, err := query.Paginate(suspiciousAccountListStore, req.Pagination, func(key []byte, value []byte) error {
		var suspiciousAccountList types.SuspiciousAccountList
		if err := k.cdc.Unmarshal(value, &suspiciousAccountList); err != nil {
			return err
		}

		suspiciousAccountLists = append(suspiciousAccountLists, suspiciousAccountList)
		return nil
	})

	if err != nil {
		return nil, status.Error(codes.Internal, err.Error())
	}

	return &types.QueryAllSuspiciousAccountListResponse{SuspiciousAccountList: suspiciousAccountLists, Pagination: pageRes}, nil
}

func (k Keeper) SuspiciousAccountList(c context.Context, req *types.QueryGetSuspiciousAccountListRequest) (*types.QueryGetSuspiciousAccountListResponse, error) {
	if req == nil {
		return nil, status.Error(codes.InvalidArgument, "invalid request")
	}
	ctx := sdk.UnwrapSDKContext(c)

	val, found := k.GetSuspiciousAccountList(
		ctx,
		req.ContractAddress,
	)
	if !found {
		return nil, status.Error(codes.NotFound, "not found")
	}

	return &types.QueryGetSuspiciousAccountListResponse{SuspiciousAccountList: val}, nil
}
