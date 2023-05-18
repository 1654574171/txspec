package keeper

import (
	"github.com/cosmos/cosmos-sdk/store/prefix"
	sdk "github.com/cosmos/cosmos-sdk/types"
	"github.com/irisnet/irishub/modules/regulatory/types"
)

// SetSpecValues set a specific specValues in the store from its index
func (k Keeper) SetSpecValues(ctx sdk.Context, specValues types.SpecValues) {
	store := prefix.NewStore(ctx.KVStore(k.storeKey), types.KeyPrefix(types.SpecValuesKeyPrefix))
	b := k.cdc.MustMarshal(&specValues)
	store.Set(types.SpecValuesKey(
		specValues.ContractAddress,
	), b)
}

// GetSpecValues returns a specValues from its index
func (k Keeper) GetSpecValues(
	ctx sdk.Context,
	contractAddress string,

) (val types.SpecValues, found bool) {
	store := prefix.NewStore(ctx.KVStore(k.storeKey), types.KeyPrefix(types.SpecValuesKeyPrefix))

	b := store.Get(types.SpecValuesKey(
		contractAddress,
	))
	if b == nil {
		return val, false
	}

	k.cdc.MustUnmarshal(b, &val)
	return val, true
}

// RemoveSpecValues removes a specValues from the store
func (k Keeper) RemoveSpecValues(
	ctx sdk.Context,
	contractAddress string,

) {
	store := prefix.NewStore(ctx.KVStore(k.storeKey), types.KeyPrefix(types.SpecValuesKeyPrefix))
	store.Delete(types.SpecValuesKey(
		contractAddress,
	))
}

// GetAllSpecValues returns all specValues
func (k Keeper) GetAllSpecValues(ctx sdk.Context) (list []types.SpecValues) {
	store := prefix.NewStore(ctx.KVStore(k.storeKey), types.KeyPrefix(types.SpecValuesKeyPrefix))
	iterator := sdk.KVStorePrefixIterator(store, []byte{})

	defer iterator.Close()

	for ; iterator.Valid(); iterator.Next() {
		var val types.SpecValues
		k.cdc.MustUnmarshal(iterator.Value(), &val)
		list = append(list, val)
	}

	return
}
