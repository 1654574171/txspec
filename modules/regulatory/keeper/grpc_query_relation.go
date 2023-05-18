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

func (k Keeper) RelationAll(c context.Context, req *types.QueryAllRelationRequest) (*types.QueryAllRelationResponse, error) {
	if req == nil {
		return nil, status.Error(codes.InvalidArgument, "invalid request")
	}

	var relations []types.Relation
	ctx := sdk.UnwrapSDKContext(c)

	store := ctx.KVStore(k.storeKey)
	relationStore := prefix.NewStore(store, types.KeyPrefix(types.RelationKeyPrefix))

	pageRes, err := query.Paginate(relationStore, req.Pagination, func(key []byte, value []byte) error {
		var relation types.Relation
		if err := k.cdc.Unmarshal(value, &relation); err != nil {
			return err
		}

		relations = append(relations, relation)
		return nil
	})

	if err != nil {
		return nil, status.Error(codes.Internal, err.Error())
	}

	return &types.QueryAllRelationResponse{Relation: relations, Pagination: pageRes}, nil
}

func (k Keeper) Relation(c context.Context, req *types.QueryGetRelationRequest) (*types.QueryGetRelationResponse, error) {
	if req == nil {
		return nil, status.Error(codes.InvalidArgument, "invalid request")
	}
	ctx := sdk.UnwrapSDKContext(c)

	val, found := k.GetRelation(
		ctx,
		req.ContractAddress,
	)
	if !found {
		return nil, status.Error(codes.NotFound, "not found")
	}

	return &types.QueryGetRelationResponse{Relation: val}, nil
}
