package types_test

import (
	"testing"

	"github.com/irisnet/irishub/modules/regulatory/types"
	"github.com/stretchr/testify/require"
)

func TestGenesisState_Validate(t *testing.T) {
	for _, tc := range []struct {
		desc     string
		genState *types.GenesisState
		valid    bool
	}{
		{
			desc:     "default is valid",
			genState: types.DefaultGenesis(),
			valid:    true,
		},
		{
			desc: "valid genesis state",
			genState: &types.GenesisState{

				RuleList: []types.Rule{
					{
						RuleName: "0",
					},
					{
						RuleName: "1",
					},
				},
				BindingList: []types.Binding{
					{
						BindingName: "0",
					},
					{
						BindingName: "1",
					},
				},
				RelationList: []types.Relation{
					{
						ContractAddress: "0",
					},
					{
						ContractAddress: "1",
					},
				},
				RegistrationList: []types.Registration{
					{
						RegulatoryServiceName: "0",
					},
					{
						RegulatoryServiceName: "1",
					},
				},
				SuspiciousAccountListList: []types.SuspiciousAccountList{
					{
						ContractAddress: "0",
					},
					{
						ContractAddress: "1",
					},
				},
				SpecValuesList: []types.SpecValues{
					{
						ContractAddress: "0",
					},
					{
						ContractAddress: "1",
					},
				},
				RewardListList: []types.RewardList{
					{
						ContractAddress: "0",
					},
					{
						ContractAddress: "1",
					},
				},
				// this line is used by starport scaffolding # types/genesis/validField
			},
			valid: true,
		},
		{
			desc: "duplicated rule",
			genState: &types.GenesisState{
				RuleList: []types.Rule{
					{
						RuleName: "0",
					},
					{
						RuleName: "0",
					},
				},
			},
			valid: false,
		},
		{
			desc: "duplicated binding",
			genState: &types.GenesisState{
				BindingList: []types.Binding{
					{
						BindingName: "0",
					},
					{
						BindingName: "0",
					},
				},
			},
			valid: false,
		},
		{
			desc: "duplicated relation",
			genState: &types.GenesisState{
				RelationList: []types.Relation{
					{
						ContractAddress: "0",
					},
					{
						ContractAddress: "0",
					},
				},
			},
			valid: false,
		},
		{
			desc: "duplicated registration",
			genState: &types.GenesisState{
				RegistrationList: []types.Registration{
					{
						RegulatoryServiceName: "0",
					},
					{
						RegulatoryServiceName: "0",
					},
				},
			},
			valid: false,
		},
		{
			desc: "duplicated suspiciousAccountList",
			genState: &types.GenesisState{
				SuspiciousAccountListList: []types.SuspiciousAccountList{
					{
						ContractAddress: "0",
					},
					{
						ContractAddress: "0",
					},
				},
			},
			valid: false,
		},
		{
			desc: "duplicated specValues",
			genState: &types.GenesisState{
				SpecValuesList: []types.SpecValues{
					{
						ContractAddress: "0",
					},
					{
						ContractAddress: "0",
					},
				},
			},
			valid: false,
		},
		{
			desc: "duplicated rewardList",
			genState: &types.GenesisState{
				RewardListList: []types.RewardList{
					{
						ContractAddress: "0",
					},
					{
						ContractAddress: "0",
					},
				},
			},
			valid: false,
		},
		// this line is used by starport scaffolding # types/genesis/testcase
	} {
		t.Run(tc.desc, func(t *testing.T) {
			err := tc.genState.Validate()
			if tc.valid {
				require.NoError(t, err)
			} else {
				require.Error(t, err)
			}
		})
	}
}
