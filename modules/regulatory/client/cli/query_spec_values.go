package cli

import (
	"context"

	"github.com/cosmos/cosmos-sdk/client"
	"github.com/cosmos/cosmos-sdk/client/flags"
	"github.com/irisnet/irishub/modules/regulatory/types"
	"github.com/spf13/cobra"
)

func CmdListSpecValues() *cobra.Command {
	cmd := &cobra.Command{
		Use:   "list-spec-values",
		Short: "list all specValues",
		RunE: func(cmd *cobra.Command, args []string) error {
			clientCtx := client.GetClientContextFromCmd(cmd)

			pageReq, err := client.ReadPageRequest(cmd.Flags())
			if err != nil {
				return err
			}

			queryClient := types.NewQueryClient(clientCtx)

			params := &types.QueryAllSpecValuesRequest{
				Pagination: pageReq,
			}

			res, err := queryClient.SpecValuesAll(context.Background(), params)
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

func CmdShowSpecValues() *cobra.Command {
	cmd := &cobra.Command{
		Use:   "show-spec-values [contract-address]",
		Short: "shows a specValues",
		Args:  cobra.ExactArgs(1),
		RunE: func(cmd *cobra.Command, args []string) (err error) {
			clientCtx := client.GetClientContextFromCmd(cmd)

			queryClient := types.NewQueryClient(clientCtx)

			argContractAddress := args[0]

			params := &types.QueryGetSpecValuesRequest{
				ContractAddress: argContractAddress,
			}

			res, err := queryClient.SpecValues(context.Background(), params)
			if err != nil {
				return err
			}

			return clientCtx.PrintProto(res)
		},
	}

	flags.AddQueryFlagsToCmd(cmd)

	return cmd
}
