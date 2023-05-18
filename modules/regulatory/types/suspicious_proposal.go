package types

import (
	govtypes "github.com/cosmos/cosmos-sdk/x/gov/types/v1beta1"
)

const (
	ProposalTypeSuspicious = "SuspiciousProposal"
)

var _ govtypes.Content = &SuspiciousProposal{}

func init() {
	govtypes.RegisterProposalType(ProposalTypeSuspicious)
}

func NewSuspiciousProposal(title, description string, suspicious *SuspiciousAccountList) *SuspiciousProposal {
	return &SuspiciousProposal{title, description, suspicious}
}

// ProposalRoute returns the routing key of a Suspicious proposal.
func (rp *SuspiciousProposal) ProposalRoute() string { return RouterKey }

// ProposalType returns the type of a Suspicious proposal.
func (rp *SuspiciousProposal) ProposalType() string { return ProposalTypeSuspicious }

// ValidateBasic  returns the type of a Suspicious proposal.
func (rp *SuspiciousProposal) ValidateBasic() error {
	err := govtypes.ValidateAbstract(rp)
	if err != nil {
		return err
	}

	//TODO validate
	return ValidateSuspicious(*rp.SuspiciousAccountList)
}

func NewSuspicious(contractAddress string, accounts []string) SuspiciousAccountList {
	return SuspiciousAccountList{contractAddress, accounts}

}
func ValidateSuspicious(Suspicious SuspiciousAccountList) error {

	if len(Suspicious.ContractAddress) == 0 {
		return ErrEmptySuspiciousContractAddress
	}
	if len(Suspicious.Account) == 0 {
		return ErrEmptySuspiciousAccount
	}
	//TODO 增加对于account地址长度的检查

	return nil
}
