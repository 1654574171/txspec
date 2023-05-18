package types

import (
	govtypes "github.com/cosmos/cosmos-sdk/x/gov/types/v1beta1"
)

const (
	ProposalTypeBinding = "BindingProposal"
)

var _ govtypes.Content = &BindingProposal{}

func init() {
	govtypes.RegisterProposalType(ProposalTypeBinding)
}

func NewBindingProposal(title, description, operationType string, binding *Binding) *BindingProposal {
	return &BindingProposal{title, description, binding, operationType}
}

// ProposalRoute returns the routing key of a rule proposal.
func (bp *BindingProposal) ProposalRoute() string { return RouterKey }

// ProposalType returns the type of a rule proposal.
func (bp *BindingProposal) ProposalType() string { return ProposalTypeBinding }

// ValidateBasic  returns the type of a rule proposal.
func (bp *BindingProposal) ValidateBasic() error {
	err := govtypes.ValidateAbstract(bp)
	if err != nil {
		return err
	}
	operationType := bp.OperationType
	switch operationType {
	case "insert":
	case "update":
	case "delete":
	default:
		return ErrInvalidOperationType
	}

	//TODO validate
	return ValidateBinding(*bp.Binding)
}

func NewBinding(name, content, hash string, ruleFileNames []string) Binding {
	return Binding{name, content, hash, ruleFileNames}

}
func ValidateBinding(binding Binding) error {
	if len(binding.BindingName) == 0 {
		return ErrEmptyRuleName
	}
	if len(binding.Content) == 0 {
		return ErrEmptyRuleContent
	}
	//TODO
	//we need check proposal's binding content is valid before proposal execute

	return nil
}
