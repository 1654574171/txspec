package cli

import (
	"context"

	"github.com/cosmos/cosmos-sdk/client"
	"github.com/cosmos/cosmos-sdk/client/flags"
	"github.com/irisnet/irishub/modules/regulatory/types"
	"github.com/spf13/cobra"
)

func CmdListBinding() *cobra.Command {
	cmd := &cobra.Command{
		Use:   "list-binding",
		Short: "list all binding",
		RunE: func(cmd *cobra.Command, args []string) error {
			clientCtx := client.GetClientContextFromCmd(cmd)

			pageReq, err := client.ReadPageRequest(cmd.Flags())
			if err != nil {
				return err
			}

			queryClient := types.NewQueryClient(clientCtx)

			params := &types.QueryAllBindingRequest{
				Pagination: pageReq,
			}

			res, err := queryClient.BindingAll(context.Background(), params)
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

func CmdShowBinding() *cobra.Command {
	cmd := &cobra.Command{
		Use:   "show-binding [binding-name]",
		Short: "shows a binding",
		Args:  cobra.ExactArgs(1),
		RunE: func(cmd *cobra.Command, args []string) (err error) {
			clientCtx := client.GetClientContextFromCmd(cmd)

			queryClient := types.NewQueryClient(clientCtx)

			argBindingName := args[0]

			params := &types.QueryGetBindingRequest{
				BindingName: argBindingName,
			}

			res, err := queryClient.Binding(context.Background(), params)
			if err != nil {
				return err
			}

			return clientCtx.PrintProto(res)
		},
	}

	flags.AddQueryFlagsToCmd(cmd)

	return cmd
}
