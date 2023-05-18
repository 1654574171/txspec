package regulatory

import (
	"github.com/irisnet/irishub/modules/regulatory/keeper"

	sdk "github.com/cosmos/cosmos-sdk/types"
	"github.com/irisnet/irishub/modules/regulatory/types"
)

// InitGenesis initializes the module's state from a provided genesis state.
func InitGenesis(ctx sdk.Context, k keeper.Keeper, genState types.GenesisState) {
	// Set all the rule
	for _, elem := range genState.RuleList {
		k.SetRule(ctx, elem)
	}
	// Set all the binding
	for _, elem := range genState.BindingList {
		k.SetBinding(ctx, elem)
	}
	// Set all the relation
	for _, elem := range genState.RelationList {
		k.SetRelation(ctx, elem)
	}
	// Set all the registration
	for _, elem := range genState.RegistrationList {
		k.SetRegistration(ctx, elem)
	}
	// Set all the suspiciousAccountList
	for _, elem := range genState.SuspiciousAccountListList {
		k.SetSuspiciousAccountList(ctx, elem)
	}
	// Set all the specValues
	for _, elem := range genState.SpecValuesList {
		k.SetSpecValues(ctx, elem)
	}
	// Set all the rewardList
	for _, elem := range genState.RewardListList {
		k.SetRewardList(ctx, elem)
	}
	// this line is used by starport scaffolding # genesis/module/init
	k.SetParams(ctx, genState.Params)
}

// ExportGenesis returns the module's exported genesis
func ExportGenesis(ctx sdk.Context, k keeper.Keeper) *types.GenesisState {
	genesis := types.DefaultGenesis()
	genesis.Params = k.GetParams(ctx)

	genesis.RuleList = k.GetAllRule(ctx)
	genesis.BindingList = k.GetAllBinding(ctx)
	genesis.RelationList = k.GetAllRelation(ctx)
	genesis.RegistrationList = k.GetAllRegistration(ctx)
	genesis.SuspiciousAccountListList = k.GetAllSuspiciousAccountList(ctx)
	genesis.SpecValuesList = k.GetAllSpecValues(ctx)
	genesis.RewardListList = k.GetAllRewardList(ctx)
	// this line is used by starport scaffolding # genesis/module/export

	return genesis
}
