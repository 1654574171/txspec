package cli

import (
	"context"

	"github.com/cosmos/cosmos-sdk/client"
	"github.com/cosmos/cosmos-sdk/client/flags"
	"github.com/irisnet/irishub/modules/regulatory/types"
	"github.com/spf13/cobra"
)

func CmdListSuspiciousAccountList() *cobra.Command {
	cmd := &cobra.Command{
		Use:   "list-suspicious-account-list",
		Short: "list all suspiciousAccountList",
		RunE: func(cmd *cobra.Command, args []string) error {
			clientCtx := client.GetClientContextFromCmd(cmd)

			pageReq, err := client.ReadPageRequest(cmd.Flags())
			if err != nil {
				return err
			}

			queryClient := types.NewQueryClient(clientCtx)

			params := &types.QueryAllSuspiciousAccountListRequest{
				Pagination: pageReq,
			}

			res, err := queryClient.SuspiciousAccountListAll(context.Background(), params)
			if err != nil {
				return err
			}

			return clientCtx.PrintProto(res)
		},
	}

	flags.AddPaginationFlagsToCmd(cmd, cmd.Use)
	flags.AddQueryFlagsToCmd(cmd)

	return cmd
}

func CmdShowSuspiciousAccountList() *cobra.Command {
	cmd := &cobra.Command{
		Use:   "show-suspicious-account-list [contract-address]",
		Short: "shows a suspiciousAccountList",
		Args:  cobra.ExactArgs(1),
		RunE: func(cmd *cobra.Command, args []string) (err error) {
			clientCtx := client.GetClientContextFromCmd(cmd)

			queryClient := types.NewQueryClient(clientCtx)

			argContractAddress := args[0]

			params := &types.QueryGetSuspiciousAccountListRequest{
				ContractAddress: argContractAddress,
			}

			res, err := queryClient.SuspiciousAccountList(context.Background(), params)
			if err != nil {
				return err
			}

			return clientCtx.PrintProto(res)
		},
	}

	flags.AddQueryFlagsToCmd(cmd)

	return cmd
}
