package cli

import (
	"fmt"
	"strings"
	"time"

	"github.com/cosmos/cosmos-sdk/client"
	"github.com/cosmos/cosmos-sdk/client/flags"
	"github.com/cosmos/cosmos-sdk/client/tx"
	sdk "github.com/cosmos/cosmos-sdk/types"
	"github.com/cosmos/cosmos-sdk/version"
	"github.com/spf13/cobra"

	// "github.com/cosmos/cosmos-sdk/client/flags"
	"github.com/irisnet/irishub/modules/regulatory/types"

	govtypes "github.com/cosmos/cosmos-sdk/x/gov/types/v1beta1"
)

var (
	DefaultRelativePacketTimeoutTimestamp = uint64((time.Duration(10) * time.Minute).Nanoseconds())
)

const (
	flagPacketTimeoutTimestamp = "packet-timeout-timestamp"
	listSeparator              = ","
)

// GetTxCmd returns the transaction commands for this module
func GetTxCmd() *cobra.Command {
	cmd := &cobra.Command{
		Use:                        types.ModuleName,
		Short:                      fmt.Sprintf("%s transactions subcommands", types.ModuleName),
		DisableFlagParsing:         true,
		SuggestionsMinimumDistance: 2,
		RunE:                       client.ValidateCmd,
	}

	cmd.AddCommand(CmdSubmitSpecValue())
	// this line is used by starport scaffolding # 1
	cmd.AddCommand(
		GetCmdSubmitRuleProposal(),
		GetCmdSubmitBindingProposal(),
		GetCmdSubmitRelationProposal(),
		GetCmdSubmitRegisterProposal(),
		GetCmdSubmitRewardListProposal(),
	)
	return cmd
}

// // GetCmdSubmitRuleProposal implements the command to submit a rule proposal
func GetCmdSubmitRuleProposal() *cobra.Command {
	bech32PrefixAccAddr := sdk.GetConfig().GetBech32AccountAddrPrefix()

	cmd := &cobra.Command{
		Use:   "submit-rule-proposal [proposal-file]",
		Args:  cobra.ExactArgs(1),
		Short: "Submit a rule proposal",
		Long: strings.TrimSpace(
			fmt.Sprintf(`Submit a rule proposal.
The proposal details must be supplied via a JSON file.

Example:
$ %s tx regulatory submit-rule-proposal <path/to/proposal.json> --from=<key_or_address>

Where proposal.json contains:

{
  "title": "rule proposal",
  "description": "add a new rule",
  "rule":{
	"ruleName":"erc20",
	"content":"content test"
  },
  "operationType":"insert",
  "deposit":"1000token"
}

"operationType" can be insert,update and delete .  
`,
				version.AppName, bech32PrefixAccAddr,
			),
		),
		RunE: func(cmd *cobra.Command, args []string) error {
			clientCtx, err := client.GetClientTxContext(cmd)
			if err != nil {
				return err
			}
			proposal, err := ParseRuleProposalJSON(clientCtx.LegacyAmino, args[0])
			if err != nil {
				return err
			}
			deposit, err := sdk.ParseCoinsNormalized(proposal.Deposit)
			if err != nil {
				return err
			}

			content := types.NewRuleProposal(proposal.Title, proposal.Description, proposal.OperationType, &proposal.Rule)
			from := clientCtx.GetFromAddress()
			msg, err := govtypes.NewMsgSubmitProposal(content, deposit, from)
			if err != nil {
				return err
			}
			return tx.GenerateOrBroadcastTxCLI(clientCtx, cmd.Flags(), msg)
		},
	}
	flags.AddTxFlagsToCmd(cmd)
	return cmd
}

// // GetCmdSubmitRuleProposal implements the command to submit a rule proposal
func GetCmdSubmitBindingProposal() *cobra.Command {
	bech32PrefixAccAddr := sdk.GetConfig().GetBech32AccountAddrPrefix()

	cmd := &cobra.Command{
		Use:   "submit-binding-proposal [proposal-file]",
		Args:  cobra.ExactArgs(1),
		Short: "Submit a binding proposal",
		Long: strings.TrimSpace(
			fmt.Sprintf(`Submit a binding proposal.
The proposal details must be supplied via a JSON file.

Example:
$ %s tx regulatory submit-binding-proposal <path/to/proposal.json> --from=<key_or_address>

Where proposal.json contains:

{
  "title": "binding proposal",
  "description": "add a new binding",
  "binding":{
	"bindingName":"erc20-binding",
	"contractName":"erc20",
	"content":"content test"
  },
  "deposit":"1000token",
  "operationType":"insert",
}
"operationType" can be insert,update and delete .
`,
				version.AppName, bech32PrefixAccAddr,
			),
		),
		RunE: func(cmd *cobra.Command, args []string) error {
			clientCtx, err := client.GetClientTxContext(cmd)
			if err != nil {
				return err
			}
			proposal, err := ParseBindingProposalJSON(clientCtx.LegacyAmino, args[0])
			if err != nil {
				return err
			}
			deposit, err := sdk.ParseCoinsNormalized(proposal.Deposit)
			if err != nil {
				return err
			}

			content := types.NewBindingProposal(proposal.Title, proposal.Description, proposal.OperationType, &proposal.Binding)
			from := clientCtx.GetFromAddress()
			msg, err := govtypes.NewMsgSubmitProposal(content, deposit, from)
			if err != nil {
				return err
			}
			return tx.GenerateOrBroadcastTxCLI(clientCtx, cmd.Flags(), msg)
		},
	}
	flags.AddTxFlagsToCmd(cmd)
	return cmd
}

// // GetCmdSubmitRuleProposal implements the command to submit a rule proposal
func GetCmdSubmitRegisterProposal() *cobra.Command {
	bech32PrefixAccAddr := sdk.GetConfig().GetBech32AccountAddrPrefix()

	cmd := &cobra.Command{
		Use:   "submit-register-proposal [proposal-file]",
		Args:  cobra.ExactArgs(1),
		Short: "Submit a register proposal",
		Long: strings.TrimSpace(
			fmt.Sprintf(`Submit a register proposal.
The proposal details must be supplied via a JSON file.

Example:
$ %s tx regulatory submit-register-proposal <path/to/proposal.json> --from=<key_or_address>

Where proposal.json contains:

{
  "title": "register proposal",
  "description": "add a new regulatory service register",
  "regulatoryService":{
	"name":"compliance engine service",

	"endpoint":{
		"ipAddress":"127.0.0.1",
		"port":8090
	}
  },
  "deposit":"1000token",
  "operationType":"insert",
}
"operationType" can be insert,update and delete .
`,
				version.AppName, bech32PrefixAccAddr,
			),
		),
		RunE: func(cmd *cobra.Command, args []string) error {
			clientCtx, err := client.GetClientTxContext(cmd)
			if err != nil {
				return err
			}
			proposal, err := ParseRegisterProposalJSON(clientCtx.LegacyAmino, args[0])
			if err != nil {
				return err
			}
			deposit, err := sdk.ParseCoinsNormalized(proposal.Deposit)
			if err != nil {
				return err
			}

			content, err := types.NewRegisterProposal(proposal.Title, proposal.Description, proposal.OperationType, &proposal.RegulatoryService, flags.FlagChainID)
			if err != nil {
				return err
			}
			from := clientCtx.GetFromAddress()
			msg, err := govtypes.NewMsgSubmitProposal(content, deposit, from)
			if err != nil {
				return err
			}
			return tx.GenerateOrBroadcastTxCLI(clientCtx, cmd.Flags(), msg)
		},
	}
	flags.AddTxFlagsToCmd(cmd)
	return cmd
}

func GetCmdSubmitRelationProposal() *cobra.Command {
	bech32PrefixAccAddr := sdk.GetConfig().GetBech32AccountAddrPrefix()

	cmd := &cobra.Command{
		Use:   "submit-relation-proposal [proposal-file]",
		Args:  cobra.ExactArgs(1),
		Short: "Submit a relation proposal",
		Long: strings.TrimSpace(
			fmt.Sprintf(`Submit a relation proposal.
The proposal details must be supplied via a JSON file.

Example:
$ %s tx regulatory submit-relation-proposal <path/to/proposal.json> --from=<key_or_address>

Where proposal.json contains:

{
  "title": "binding proposal",
  "description": "add a new binding",
  "relation":{
	"contractAddress":"erc20",
	"bindingName":"erc20-binding"
	
  },
  "deposit":"1000token",
  "operationType":"insert",
}
"operationType" can be insert,update and delete .
`,
				version.AppName, bech32PrefixAccAddr,
			),
		),
		RunE: func(cmd *cobra.Command, args []string) error {
			clientCtx, err := client.GetClientTxContext(cmd)
			if err != nil {
				return err
			}
			proposal, err := ParseRelationProposalJSON(clientCtx.LegacyAmino, args[0])
			if err != nil {
				return err
			}
			deposit, err := sdk.ParseCoinsNormalized(proposal.Deposit)
			if err != nil {
				return err
			}

			content := types.NewRelationProposal(proposal.Title, proposal.Description, proposal.OperationType, &proposal.Relation)
			from := clientCtx.GetFromAddress()
			msg, err := govtypes.NewMsgSubmitProposal(content, deposit, from)
			if err != nil {
				return err
			}
			return tx.GenerateOrBroadcastTxCLI(clientCtx, cmd.Flags(), msg)
		},
	}
	flags.AddTxFlagsToCmd(cmd)
	return cmd
}

func GetCmdSubmitRewardListProposal() *cobra.Command {
	bech32PrefixAccAddr := sdk.GetConfig().GetBech32AccountAddrPrefix()

	cmd := &cobra.Command{
		Use:   "submit-reward-list-proposal [proposal-file]",
		Args:  cobra.ExactArgs(1),
		Short: "Submit a reward list proposal",
		Long: strings.TrimSpace(
			fmt.Sprintf(`Submit a reward list proposal.
The proposal details must be supplied via a JSON file.

Example:
$ %s tx regulatory submit-reward-list-proposal <path/to/proposal.json> --from=<key_or_address>

Where proposal.json contains:

{
  "title": "reward list proposal",
  "description": "add a new reward list ",
  "relation":{
	"contractAddress":"erc20",
	"rewardList":"aaaaa"
	
  },
  "deposit":"1000token",
  "operationType":"insert",
}
"operationType" can be insert,update and delete .
`,
				version.AppName, bech32PrefixAccAddr,
			),
		),
		RunE: func(cmd *cobra.Command, args []string) error {
			clientCtx, err := client.GetClientTxContext(cmd)
			if err != nil {
				return err
			}
			proposal, err := ParseRewardListProposalJSON(clientCtx.LegacyAmino, args[0])
			if err != nil {
				return err
			}
			deposit, err := sdk.ParseCoinsNormalized(proposal.Deposit)
			if err != nil {
				return err
			}

			content := types.NewRewardListProposal(proposal.Title, proposal.Description, proposal.OperationType, &proposal.RewardList)
			fmt.Println(content)
			from := clientCtx.GetFromAddress()
			msg, err := govtypes.NewMsgSubmitProposal(content, deposit, from)
			if err != nil {
				return err
			}
			return tx.GenerateOrBroadcastTxCLI(clientCtx, cmd.Flags(), msg)
		},
	}
	flags.AddTxFlagsToCmd(cmd)
	return cmd
}
