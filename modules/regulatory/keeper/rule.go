package keeper

import (
	"github.com/cosmos/cosmos-sdk/store/prefix"
	sdk "github.com/cosmos/cosmos-sdk/types"
	"github.com/irisnet/irishub/modules/regulatory/types"
)

// SetRule set a specific rule in the store from its index
func (k Keeper) SetRule(ctx sdk.Context, rule types.Rule) {
	store := prefix.NewStore(ctx.KVStore(k.storeKey), types.KeyPrefix(types.RuleKeyPrefix))
	b := k.cdc.MustMarshal(&rule)
	store.Set(types.RuleKey(
		rule.RuleName,
	), b)
}

// GetRule returns a rule from its index
func (k Keeper) GetRule(
	ctx sdk.Context,
	ruleName string,

) (val types.Rule, found bool) {
	store := prefix.NewStore(ctx.KVStore(k.storeKey), types.KeyPrefix(types.RuleKeyPrefix))

	b := store.Get(types.RuleKey(
		ruleName,
	))
	if b == nil {
		return val, false
	}

	k.cdc.MustUnmarshal(b, &val)
	return val, true
}

// RemoveRule removes a rule from the store
func (k Keeper) RemoveRule(
	ctx sdk.Context,
	ruleName string,

) {
	store := prefix.NewStore(ctx.KVStore(k.storeKey), types.KeyPrefix(types.RuleKeyPrefix))
	store.Delete(types.RuleKey(
		ruleName,
	))
}

// GetAllRule returns all rule
func (k Keeper) GetAllRule(ctx sdk.Context) (list []types.Rule) {
	store := prefix.NewStore(ctx.KVStore(k.storeKey), types.KeyPrefix(types.RuleKeyPrefix))
	iterator := sdk.KVStorePrefixIterator(store, []byte{})

	defer iterator.Close()

	for ; iterator.Valid(); iterator.Next() {
		var val types.Rule
		k.cdc.MustUnmarshal(iterator.Value(), &val)
		list = append(list, val)
	}

	return
}
