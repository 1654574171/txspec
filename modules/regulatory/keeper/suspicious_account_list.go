package keeper

import (
	"github.com/cosmos/cosmos-sdk/store/prefix"
	sdk "github.com/cosmos/cosmos-sdk/types"
	"github.com/irisnet/irishub/modules/regulatory/types"
)

// SetSuspiciousAccountList set a specific suspiciousAccountList in the store from its index
func (k Keeper) SetSuspiciousAccountList(ctx sdk.Context, suspiciousAccountList types.SuspiciousAccountList) {
	store := prefix.NewStore(ctx.KVStore(k.storeKey), types.KeyPrefix(types.SuspiciousAccountListKeyPrefix))
	b := k.cdc.MustMarshal(&suspiciousAccountList)
	store.Set(types.SuspiciousAccountListKey(
		suspiciousAccountList.ContractAddress,
	), b)
}

// GetSuspiciousAccountList returns a suspiciousAccountList from its index
func (k Keeper) GetSuspiciousAccountList(
	ctx sdk.Context,
	contractAddress string,

) (val types.SuspiciousAccountList, found bool) {
	store := prefix.NewStore(ctx.KVStore(k.storeKey), types.KeyPrefix(types.SuspiciousAccountListKeyPrefix))

	b := store.Get(types.SuspiciousAccountListKey(
		contractAddress,
	))
	if b == nil {
		return val, false
	}

	k.cdc.MustUnmarshal(b, &val)
	return val, true
}

// RemoveSuspiciousAccountList removes a suspiciousAccountList from the store
func (k Keeper) RemoveSuspiciousAccountList(
	ctx sdk.Context,
	contractAddress string,

) {
	store := prefix.NewStore(ctx.KVStore(k.storeKey), types.KeyPrefix(types.SuspiciousAccountListKeyPrefix))
	store.Delete(types.SuspiciousAccountListKey(
		contractAddress,
	))
}

// GetAllSuspiciousAccountList returns all suspiciousAccountList
func (k Keeper) GetAllSuspiciousAccountList(ctx sdk.Context) (list []types.SuspiciousAccountList) {
	store := prefix.NewStore(ctx.KVStore(k.storeKey), types.KeyPrefix(types.SuspiciousAccountListKeyPrefix))
	iterator := sdk.KVStorePrefixIterator(store, []byte{})

	defer iterator.Close()

	for ; iterator.Valid(); iterator.Next() {
		var val types.SuspiciousAccountList
		k.cdc.MustUnmarshal(iterator.Value(), &val)
		list = append(list, val)
	}

	return
}
