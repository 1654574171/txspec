package keeper

import (
	"github.com/cosmos/cosmos-sdk/store/prefix"
	sdk "github.com/cosmos/cosmos-sdk/types"
	"github.com/irisnet/irishub/modules/regulatory/types"
)

// SetRegistration set a specific registration in the store from its index
func (k Keeper) SetRegistration(ctx sdk.Context, registration types.Registration) {
	store := prefix.NewStore(ctx.KVStore(k.storeKey), types.KeyPrefix(types.RegistrationKeyPrefix))
	b := k.cdc.MustMarshal(&registration)
	store.Set(types.RegistrationKey(
		registration.RegulatoryServiceName,
	), b)
}

// GetRegistration returns a registration from its index
func (k Keeper) GetRegistration(
	ctx sdk.Context,
	regulatoryServiceName string,

) (val types.Registration, found bool) {
	store := prefix.NewStore(ctx.KVStore(k.storeKey), types.KeyPrefix(types.RegistrationKeyPrefix))

	b := store.Get(types.RegistrationKey(
		regulatoryServiceName,
	))
	if b == nil {
		return val, false
	}

	k.cdc.MustUnmarshal(b, &val)
	return val, true
}

// RemoveRegistration removes a registration from the store
func (k Keeper) RemoveRegistration(
	ctx sdk.Context,
	regulatoryServiceName string,

) {
	store := prefix.NewStore(ctx.KVStore(k.storeKey), types.KeyPrefix(types.RegistrationKeyPrefix))
	store.Delete(types.RegistrationKey(
		regulatoryServiceName,
	))
}

// GetAllRegistration returns all registration
func (k Keeper) GetAllRegistration(ctx sdk.Context) (list []types.Registration) {
	store := prefix.NewStore(ctx.KVStore(k.storeKey), types.KeyPrefix(types.RegistrationKeyPrefix))
	iterator := sdk.KVStorePrefixIterator(store, []byte{})

	defer iterator.Close()

	for ; iterator.Valid(); iterator.Next() {
		var val types.Registration
		k.cdc.MustUnmarshal(iterator.Value(), &val)
		list = append(list, val)
	}

	return
}
