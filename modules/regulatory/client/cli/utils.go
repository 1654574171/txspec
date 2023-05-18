package cli

import (
	"encoding/base64"
	"os"

	"github.com/irisnet/irishub/modules/regulatory/types"

	"github.com/cosmos/cosmos-sdk/codec"
)

type (
	RuleProposalJSON struct {
		Title         string     `json:"title" yaml:"title"`
		Description   string     `json:"description" yaml:"description"`
		Rule          types.Rule `json:"rule" yaml:"rule"`
		Deposit       string     `json:"deposit" yaml:"deposit"`
		OperationType string     `json:"operationType" yaml:"operationType"`
	}
	BindingProposalJSON struct {
		Title         string        `json:"title" yaml:"title"`
		Description   string        `json:"description" yaml:"description"`
		Binding       types.Binding `json:"binding" yaml:"binding"`
		Deposit       string        `json:"deposit" yaml:"deposit"`
		OperationType string        `json:"operationType" yaml:"operationType"`
	}
	RelationProposalJSON struct {
		Title         string         `json:"title" yaml:"title"`
		Description   string         `json:"description" yaml:"description"`
		Relation      types.Relation `json:"relation" yaml:"relation"`
		Deposit       string         `json:"deposit" yaml:"deposit"`
		OperationType string         `json:"operationType" yaml:"operationType"`
	}
	RegisterProposalJSON struct {
		Title             string                  `json:"title" yaml:"title"`
		Description       string                  `json:"description" yaml:"description"`
		RegulatoryService types.RegulatoryService `json:"regulatoryService" yaml:"regulatoryService"`
		Deposit           string                  `json:"deposit" yaml:"deposit"`
		OperationType     string                  `json:"operationType" yaml:"operationType"`
	}

	RewardListProposalJSON struct {
		Title         string           `json:"title" yaml:"title"`
		Description   string           `json:"description" yaml:"description"`
		RewardList    types.RewardList `json:"rewardList" yaml:"rewardList"`
		Deposit       string           `json:"deposit" yaml:"deposit"`
		OperationType string           `json:"operationType" yaml:"operationType"`
	}
)

func ParseRuleProposalJSON(cdc *codec.LegacyAmino, proposalFile string) (RuleProposalJSON, error) {
	proposal := RuleProposalJSON{}

	contents, err := os.ReadFile(proposalFile)
	if err != nil {
		return proposal, err
	}
	if err := cdc.UnmarshalJSON(contents, &proposal); err != nil {
		return proposal, err
	}
	content := base64.StdEncoding.EncodeToString([]byte(proposal.Rule.Content))
	proposal.Rule.Content = content
	return proposal, nil
}

func ParseBindingProposalJSON(cdc *codec.LegacyAmino, proposalFile string) (BindingProposalJSON, error) {
	proposal := BindingProposalJSON{}

	contents, err := os.ReadFile(proposalFile)
	if err != nil {
		return proposal, err
	}
	if err := cdc.UnmarshalJSON(contents, &proposal); err != nil {
		return proposal, err
	}
	content := base64.StdEncoding.EncodeToString([]byte(proposal.Binding.Content))
	proposal.Binding.Content = content
	return proposal, nil
}
func ParseRelationProposalJSON(cdc *codec.LegacyAmino, proposalFile string) (RelationProposalJSON, error) {
	proposal := RelationProposalJSON{}
	contents, err := os.ReadFile(proposalFile)
	if err != nil {
		return proposal, err
	}
	if err := cdc.UnmarshalJSON(contents, &proposal); err != nil {
		return proposal, err
	}

	return proposal, nil
}

func ParseRegisterProposalJSON(cdc *codec.LegacyAmino, proposalFile string) (RegisterProposalJSON, error) {
	proposal := RegisterProposalJSON{}
	contents, err := os.ReadFile(proposalFile)
	if err != nil {
		return proposal, err
	}
	if err := cdc.UnmarshalJSON(contents, &proposal); err != nil {
		return proposal, err
	}

	return proposal, nil
}

func ParseRewardListProposalJSON(cdc *codec.LegacyAmino, proposalFile string) (RewardListProposalJSON, error) {
	proposal := RewardListProposalJSON{}
	contents, err := os.ReadFile(proposalFile)
	if err != nil {
		return proposal, err
	}
	if err := cdc.UnmarshalJSON(contents, &proposal); err != nil {
		return proposal, err
	}

	return proposal, nil
}
