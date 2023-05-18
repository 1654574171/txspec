package cli

import (
	"context"

	"github.com/cosmos/cosmos-sdk/client"
	"github.com/cosmos/cosmos-sdk/client/flags"
	"github.com/irisnet/irishub/modules/regulatory/types"
	"github.com/spf13/cobra"
)

func CmdListRegistration() *cobra.Command {
	cmd := &cobra.Command{
		Use:   "list-registration",
		Short: "list all registration",
		RunE: func(cmd *cobra.Command, args []string) error {
			clientCtx := client.GetClientContextFromCmd(cmd)

			pageReq, err := client.ReadPageRequest(cmd.Flags())
			if err != nil {
				return err
			}

			queryClient := types.NewQueryClient(clientCtx)

			params := &types.QueryAllRegistrationRequest{
				Pagination: pageReq,
			}

			res, err := queryClient.RegistrationAll(context.Background(), params)
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

func CmdShowRegistration() *cobra.Command {
	cmd := &cobra.Command{
		Use:   "show-registration [regulatory-service-name]",
		Short: "shows a registration",
		Args:  cobra.ExactArgs(1),
		RunE: func(cmd *cobra.Command, args []string) (err error) {
			clientCtx := client.GetClientContextFromCmd(cmd)

			queryClient := types.NewQueryClient(clientCtx)

			argRegulatoryServiceName := args[0]

			params := &types.QueryGetRegistrationRequest{
				RegulatoryServiceName: argRegulatoryServiceName,
			}

			res, err := queryClient.Registration(context.Background(), params)
			if err != nil {
				return err
			}

			return clientCtx.PrintProto(res)
		},
	}

	flags.AddQueryFlagsToCmd(cmd)

	return cmd
}
