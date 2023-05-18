package types

import (
	govtypes "github.com/cosmos/cosmos-sdk/x/gov/types/v1beta1"
)

const (
	ProposalTypeRule = "RuleProposal"
)

var _ govtypes.Content = &RuleProposal{}

func init() {
	govtypes.RegisterProposalType(ProposalTypeRule)
}

func NewRuleProposal(title, description, operationType string, rule *Rule) *RuleProposal {
	return &RuleProposal{title, description, rule, operationType}
}

// ProposalRoute returns the routing key of a rule proposal.
func (rp *RuleProposal) ProposalRoute() string { return RouterKey }

// ProposalType returns the type of a rule proposal.
func (rp *RuleProposal) ProposalType() string { return ProposalTypeRule }

// ValidateBasic  returns the type of a rule proposal.
func (rp *RuleProposal) ValidateBasic() error {
	err := govtypes.ValidateAbstract(rp)
	if err != nil {
		return err
	}
	operationType := rp.OperationType
	switch operationType {
	case "insert":
	case "update":
	case "delete":
	default:
		return ErrInvalidOperationType
	}

	//TODO validate
	return ValidateRule(*rp.Rule)
}

func NewRule(name, content, hash string) Rule {
	return Rule{name, content, hash}

}
func ValidateRule(rule Rule) error {

	if len(rule.RuleName) == 0 {
		return ErrEmptyRuleName
	}
	if len(rule.Content) == 0 {
		return ErrEmptyRuleContent
	}
	//TODO
	//we need check proposal's rule content is valid before proposal execute

	return nil
}
