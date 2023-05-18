package cli

import (
	"fmt"
	// "strings"

	"github.com/spf13/cobra"

	"github.com/cosmos/cosmos-sdk/client"
	// "github.com/cosmos/cosmos-sdk/client/flags"
	// sdk "github.com/cosmos/cosmos-sdk/types"

	"github.com/irisnet/irishub/modules/regulatory/types"
)

// GetQueryCmd returns the cli query commands for this module
func GetQueryCmd(queryRoute string) *cobra.Command {
	// Group regulatory queries under a subcommand
	cmd := &cobra.Command{
		Use:                        types.ModuleName,
		Short:                      fmt.Sprintf("Querying commands for the %s module", types.ModuleName),
		DisableFlagParsing:         true,
		SuggestionsMinimumDistance: 2,
		RunE:                       client.ValidateCmd,
	}

	cmd.AddCommand(CmdQueryParams())
	cmd.AddCommand(CmdListRule())
	cmd.AddCommand(CmdShowRule())
	cmd.AddCommand(CmdListBinding())
	cmd.AddCommand(CmdShowBinding())
	cmd.AddCommand(CmdListRelation())
	cmd.AddCommand(CmdShowRelation())
	cmd.AddCommand(CmdListRegistration())
	cmd.AddCommand(CmdShowRegistration())
	cmd.AddCommand(CmdListSuspiciousAccountList())
	cmd.AddCommand(CmdShowSuspiciousAccountList())
	cmd.AddCommand(CmdListSpecValues())
	cmd.AddCommand(CmdShowSpecValues())
	cmd.AddCommand(CmdListRewardList())
	cmd.AddCommand(CmdShowRewardList())
	// this line is used by starport scaffolding # 1

	return cmd
}
