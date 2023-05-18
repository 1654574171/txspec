package cli

import (
	"strconv"

	"github.com/cosmos/cosmos-sdk/client"
	"github.com/cosmos/cosmos-sdk/client/flags"
	"github.com/cosmos/cosmos-sdk/client/tx"
	"github.com/irisnet/irishub/modules/regulatory/types"
	"github.com/spf13/cobra"
)

var _ = strconv.Itoa(0)

func CmdSubmitSpecValue() *cobra.Command {
	cmd := &cobra.Command{
		Use:   "submit-spec-value [related-tx-hash] [data] [datahash] [signature] [contract-address]",
		Short: "Submit the rule processing results of the relevant transaction, where the data field is the JSON description of the returned result, defined by the application, and the contractAddress field is the application ID associated with the transaction.",
		Args:  cobra.ExactArgs(5),
		RunE: func(cmd *cobra.Command, args []string) (err error) {
			argRelatedTxHash := args[0]
			argData := args[1]
			argDatahash := args[2]
			argSignature := args[3]
			argContractAddress := args[4]

			clientCtx, err := client.GetClientTxContext(cmd)
			if err != nil {
				return err
			}

			msg := types.NewMsgSubmitSpecValue(
				clientCtx.GetFromAddress().String(),
				argRelatedTxHash,
				argData,
				argDatahash,
				argSignature,
				argContractAddress,
			)
			if err := msg.ValidateBasic(); err != nil {
				return err
			}
			return tx.GenerateOrBroadcastTxCLI(clientCtx, cmd.Flags(), msg)
		},
	}

	flags.AddTxFlagsToCmd(cmd)

	return cmd
}
