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

func (k Keeper) RuleAll(c context.Context, req *types.QueryAllRuleRequest) (*types.QueryAllRuleResponse, error) {
	if req == nil {
		return nil, status.Error(codes.InvalidArgument, "invalid request")
	}

	var rules []types.Rule
	ctx := sdk.UnwrapSDKContext(c)

	store := ctx.KVStore(k.storeKey)
	ruleStore := prefix.NewStore(store, types.KeyPrefix(types.RuleKeyPrefix))

	pageRes, err := query.Paginate(ruleStore, req.Pagination, func(key []byte, value []byte) error {
		var rule types.Rule
		if err := k.cdc.Unmarshal(value, &rule); err != nil {
			return err
		}

		rules = append(rules, rule)
		return nil
	})

	if err != nil {
		return nil, status.Error(codes.Internal, err.Error())
	}

	return &types.QueryAllRuleResponse{Rule: rules, Pagination: pageRes}, nil
}

func (k Keeper) Rule(c context.Context, req *types.QueryGetRuleRequest) (*types.QueryGetRuleResponse, error) {
	if req == nil {
		return nil, status.Error(codes.InvalidArgument, "invalid request")
	}
	ctx := sdk.UnwrapSDKContext(c)

	val, found := k.GetRule(
		ctx,
		req.RuleName,
	)
	if !found {
		return nil, status.Error(codes.NotFound, "not found")
	}

	return &types.QueryGetRuleResponse{Rule: val}, nil
}
