package types

import (
	"fmt"
)

// DefaultIndex is the default global index
const DefaultIndex uint64 = 1

// DefaultGenesis returns the default genesis state
func DefaultGenesis() *GenesisState {
	return &GenesisState{
		RuleList:     []Rule{},
		BindingList:  []Binding{},
		RelationList: []Relation{},
		RegistrationList: []Registration{},
SuspiciousAccountListList: []SuspiciousAccountList{},
SpecValuesList: []SpecValues{},
RewardListList: []RewardList{},
// this line is used by starport scaffolding # genesis/types/default
		Params: DefaultParams(),
	}
}

// Validate performs basic genesis state validation returning an error upon any
// failure.
func (gs GenesisState) Validate() error {
	// Check for duplicated index in rule
	ruleIndexMap := make(map[string]struct{})

	for _, elem := range gs.RuleList {
		index := string(RuleKey(elem.RuleName))
		if _, ok := ruleIndexMap[index]; ok {
			return fmt.Errorf("duplicated index for rule")
		}
		ruleIndexMap[index] = struct{}{}
	}
	// Check for duplicated index in binding
	bindingIndexMap := make(map[string]struct{})

	for _, elem := range gs.BindingList {
		index := string(BindingKey(elem.BindingName))
		if _, ok := bindingIndexMap[index]; ok {
			return fmt.Errorf("duplicated index for binding")
		}
		bindingIndexMap[index] = struct{}{}
	}
	// Check for duplicated index in relation
	relationIndexMap := make(map[string]struct{})

	for _, elem := range gs.RelationList {
		index := string(RelationKey(elem.ContractAddress))
		if _, ok := relationIndexMap[index]; ok {
			return fmt.Errorf("duplicated index for relation")
		}
		relationIndexMap[index] = struct{}{}
	}
	// Check for duplicated index in registration
registrationIndexMap := make(map[string]struct{})

for _, elem := range gs.RegistrationList {
	index := string(RegistrationKey(elem.RegulatoryServiceName))
	if _, ok := registrationIndexMap[index]; ok {
		return fmt.Errorf("duplicated index for registration")
	}
	registrationIndexMap[index] = struct{}{}
}
// Check for duplicated index in suspiciousAccountList
suspiciousAccountListIndexMap := make(map[string]struct{})

for _, elem := range gs.SuspiciousAccountListList {
	index := string(SuspiciousAccountListKey(elem.ContractAddress))
	if _, ok := suspiciousAccountListIndexMap[index]; ok {
		return fmt.Errorf("duplicated index for suspiciousAccountList")
	}
	suspiciousAccountListIndexMap[index] = struct{}{}
}
// Check for duplicated index in specValues
specValuesIndexMap := make(map[string]struct{})

for _, elem := range gs.SpecValuesList {
	index := string(SpecValuesKey(elem.ContractAddress))
	if _, ok := specValuesIndexMap[index]; ok {
		return fmt.Errorf("duplicated index for specValues")
	}
	specValuesIndexMap[index] = struct{}{}
}
// Check for duplicated index in rewardList
rewardListIndexMap := make(map[string]struct{})

for _, elem := range gs.RewardListList {
	index := string(RewardListKey(elem.ContractAddress))
	if _, ok := rewardListIndexMap[index]; ok {
		return fmt.Errorf("duplicated index for rewardList")
	}
	rewardListIndexMap[index] = struct{}{}
}
// this line is used by starport scaffolding # genesis/types/validate

	return gs.Params.Validate()
}
