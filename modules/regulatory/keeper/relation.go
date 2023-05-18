package keeper

import (
	"github.com/cosmos/cosmos-sdk/store/prefix"
	sdk "github.com/cosmos/cosmos-sdk/types"
	"github.com/irisnet/irishub/modules/regulatory/types"
)

// SetRelation set a specific relation in the store from its index
func (k Keeper) SetRelation(ctx sdk.Context, relation types.Relation) {
	store := prefix.NewStore(ctx.KVStore(k.storeKey), types.KeyPrefix(types.RelationKeyPrefix))
	b := k.cdc.MustMarshal(&relation)
	store.Set(types.RelationKey(
		relation.ContractAddress,
	), b)
}

// GetRelation returns a relation from its index
func (k Keeper) GetRelation(
	ctx sdk.Context,
	contractAddress string,

) (val types.Relation, found bool) {
	store := prefix.NewStore(ctx.KVStore(k.storeKey), types.KeyPrefix(types.RelationKeyPrefix))

	b := store.Get(types.RelationKey(
		contractAddress,
	))
	if b == nil {
		return val, false
	}

	k.cdc.MustUnmarshal(b, &val)
	return val, true
}

// RemoveRelation removes a relation from the store
func (k Keeper) RemoveRelation(
	ctx sdk.Context,
	contractAddress string,

) {
	store := prefix.NewStore(ctx.KVStore(k.storeKey), types.KeyPrefix(types.RelationKeyPrefix))
	store.Delete(types.RelationKey(
		contractAddress,
	))
}

// GetAllRelation returns all relation
func (k Keeper) GetAllRelation(ctx sdk.Context) (list []types.Relation) {
	store := prefix.NewStore(ctx.KVStore(k.storeKey), types.KeyPrefix(types.RelationKeyPrefix))
	iterator := sdk.KVStorePrefixIterator(store, []byte{})

	defer iterator.Close()

	for ; iterator.Valid(); iterator.Next() {
		var val types.Relation
		k.cdc.MustUnmarshal(iterator.Value(), &val)
		list = append(list, val)
	}

	return
}
