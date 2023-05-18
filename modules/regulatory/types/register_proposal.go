package types

import (
	context "context"
	"fmt"

	"strings"

	govtypes "github.com/cosmos/cosmos-sdk/x/gov/types/v1beta1"
	grpc "google.golang.org/grpc"
	"google.golang.org/grpc/credentials/insecure"
)

const (
	ProposalTypeRegister = "RegisterProposal"
)

var _ govtypes.Content = &RegisterProposal{}

func init() {
	govtypes.RegisterProposalType(ProposalTypeRegister)
}

func NewRegisterProposal(title, description, operationType string, regulatoryService *RegulatoryService, chainId string) (*RegisterProposal, error) {

	if operationType == "insert" || operationType == "update" {
		err := ValidateRegulatoryService(*regulatoryService)
		if err != nil {
			return nil, err
		}
		// remote register
		remoteRegisterResp, err := regulatoryServiceRegister(*regulatoryService.Endpoint, chainId)
		if err != nil {
			fmt.Println("remote reigster fail")
			return nil, err
		}
		return &RegisterProposal{title, description, &Registration{regulatoryService.Name, remoteRegisterResp.IasAttestationReport,
			remoteRegisterResp.EnclavePk, regulatoryService.Endpoint}, operationType}, nil
	} else if operationType == "delete" {
		if len(regulatoryService.Name) == 0 {
			return nil, ErrEmptyRSName
		}
		return &RegisterProposal{title, description, &Registration{regulatoryService.Name, "",
			"", regulatoryService.Endpoint}, operationType}, nil
	}
	return nil, ErrInvalidOperationType

}

// ProposalRoute returns the routing key of a rule proposal.
func (rp *RegisterProposal) ProposalRoute() string { return RouterKey }

// ProposalType returns the type of a rule proposal.
func (rp *RegisterProposal) ProposalType() string { return ProposalTypeRegister }

// ValidateBasic  returns the type of a rule proposal.
func (rp *RegisterProposal) ValidateBasic() error {
	err := govtypes.ValidateAbstract(rp)
	if err != nil {
		return err
	}
	operationType := rp.OperationType
	switch operationType {
	case "insert":
	case "update":
	case "delete":
		return nil
	default:
		return ErrInvalidOperationType
	}
	return ValidateRegistration(*rp.Registration)
}

func NewRegulatoryService(name string, endpoint Endpoint) RegulatoryService {
	return RegulatoryService{name, &endpoint}

}
func ValidateRegulatoryService(rs RegulatoryService) error {
	//TODO RegulatoryService field validate

	if len(rs.Name) == 0 {
		return ErrEmptyRSName
	}
	if rs.Endpoint == nil {
		return ErrEmptyRSEndpoint
	}
	if len(rs.Endpoint.IpAddress) == 0 {
		return ErrEmptyRSIpAddress
	}
	if rs.Endpoint.Port == 0 {
		return ErrInvalidRSPort
	}
	//endpoint ip format check
	if len(strings.Split(rs.Endpoint.IpAddress, ".")) != 4 {
		return ErrInvalidRSIpAddress
	}
	return nil
}
func ValidateRegistration(registration Registration) error {
	if len(registration.EnclavePK) == 0 {
		return ErrEmptyEnclavePK
	}
	if len(registration.IasAttestatioReport) == 0 {
		return ErrEmptyRegistrationReport
	}

	return nil
}
func regulatoryServiceRegister(endpoint Endpoint, chainId string) (RegisterResponse, error) {

	serviceAddress := fmt.Sprintf("%v:%v", endpoint.IpAddress, endpoint.Port)

	connect, err := grpc.Dial(serviceAddress, grpc.WithTransportCredentials(insecure.NewCredentials()))
	if err != nil {
		return RegisterResponse{}, ErrDialRS
	}

	defer connect.Close()
	client := NewRegisterClient(connect)

	response, err := client.RegisterRegulatoryService(context.Background(), &RegisterRequest{ChainType: "cosmos", ChainId: chainId})
	if err != nil {
		return RegisterResponse{}, ErrDialRS
	}

	return *response, nil
}
