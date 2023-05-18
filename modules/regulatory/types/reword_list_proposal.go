package types

import (
	govtypes "github.com/cosmos/cosmos-sdk/x/gov/types/v1beta1"
)

const (
	ProposalTypeRewardList = "RewardListProposal"
)

var _ govtypes.Content = &RewardListProposal{}

func init() {
	govtypes.RegisterProposalType(ProposalTypeRewardList)
}

func NewRewardListProposal(title, description, operationType string, rewardList *RewardList) *RewardListProposal {
	return &RewardListProposal{title, description, rewardList, operationType}
}

// ProposalRoute returns the routing key of a reward list  proposal.
func (rp *RewardListProposal) ProposalRoute() string { return RouterKey }

// ProposalType returns the type of a reward list  proposal.
func (rp *RewardListProposal) ProposalType() string { return ProposalTypeRewardList }

// ValidateBasic  returns the type of a reward list proposal.
func (rp *RewardListProposal) ValidateBasic() error {
	err := govtypes.ValidateAbstract(rp)
	if err != nil {
		return err
	}

	//TODO validate
	return ValidateRewardList(*rp.List)
}

func NewRewardList(contractAddress string, list []string) RewardList {
	return RewardList{contractAddress, list}

}
func ValidateRewardList(rewardList RewardList) error {

	if len(rewardList.ContractAddress) == 0 {
		return ErrEmptySuspiciousContractAddress
	}
	if len(rewardList.List) == 0 {
		return ErrEmptySuspiciousAccount
	}

	return nil
}
