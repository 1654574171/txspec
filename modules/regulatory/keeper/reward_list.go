package keeper

import (
	"github.com/cosmos/cosmos-sdk/store/prefix"
	sdk "github.com/cosmos/cosmos-sdk/types"
	"github.com/irisnet/irishub/modules/regulatory/types"
)

// SetRewardList set a specific rewardList in the store from its index
func (k Keeper) SetRewardList(ctx sdk.Context, rewardList types.RewardList) {
	store := prefix.NewStore(ctx.KVStore(k.storeKey), types.KeyPrefix(types.RewardListKeyPrefix))
	b := k.cdc.MustMarshal(&rewardList)
	store.Set(types.RewardListKey(
		rewardList.ContractAddress,
	), b)
}

// GetRewardList returns a rewardList from its index
func (k Keeper) GetRewardList(
	ctx sdk.Context,
	contractAddress string,

) (val types.RewardList, found bool) {
	store := prefix.NewStore(ctx.KVStore(k.storeKey), types.KeyPrefix(types.RewardListKeyPrefix))

	b := store.Get(types.RewardListKey(
		contractAddress,
	))
	if b == nil {
		return val, false
	}

	k.cdc.MustUnmarshal(b, &val)
	return val, true
}

// RemoveRewardList removes a rewardList from the store
func (k Keeper) RemoveRewardList(
	ctx sdk.Context,
	contractAddress string,

) {
	store := prefix.NewStore(ctx.KVStore(k.storeKey), types.KeyPrefix(types.RewardListKeyPrefix))
	store.Delete(types.RewardListKey(
		contractAddress,
	))
}

// GetAllRewardList returns all rewardList
func (k Keeper) GetAllRewardList(ctx sdk.Context) (list []types.RewardList) {
	store := prefix.NewStore(ctx.KVStore(k.storeKey), types.KeyPrefix(types.RewardListKeyPrefix))
	iterator := sdk.KVStorePrefixIterator(store, []byte{})

	defer iterator.Close()

	for ; iterator.Valid(); iterator.Next() {
		var val types.RewardList
		k.cdc.MustUnmarshal(iterator.Value(), &val)
		list = append(list, val)
	}

	return
}
