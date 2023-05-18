package types

import (
	govtypes "github.com/cosmos/cosmos-sdk/x/gov/types/v1beta1"
)

const (
	ProposalTypeRelation = "RelationProposal"
)

var _ govtypes.Content = &RelationProposal{}

func init() {
	govtypes.RegisterProposalType(ProposalTypeRelation)
}

func NewRelationProposal(title, description, operationType string, relation *Relation) *RelationProposal {
	return &RelationProposal{title, description, relation, operationType}
}

// ProposalRoute returns the routing key of a rule proposal.
func (rp *RelationProposal) ProposalRoute() string { return RouterKey }

// ProposalType returns the type of a rule proposal.
func (rp *RelationProposal) ProposalType() string { return ProposalTypeRelation }

// ValidateBasic  returns the type of a rule proposal.
func (rp *RelationProposal) ValidateBasic() error {
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
	return ValidateRelation(*rp.Relation)
}

func NewRelation(contractAddress, bindingName string) Relation {
	return Relation{contractAddress, bindingName}

}
func ValidateRelation(relation Relation) error {
	if len(relation.ContractAddress) == 0 {
		return ErrEmptyRuleName
	}
	//TODO verify binding name already in state
	if len(relation.BindingName) == 0 {
		return ErrEmptyHash
	}
	return nil
}
