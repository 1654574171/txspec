package simulation

import (
	"math/rand"

	"github.com/irisnet/irishub/modules/regulatory/keeper"

	"github.com/cosmos/cosmos-sdk/baseapp"
	sdk "github.com/cosmos/cosmos-sdk/types"
	simtypes "github.com/cosmos/cosmos-sdk/types/simulation"
	"github.com/irisnet/irishub/modules/regulatory/types"
)

func SimulateMsgSubmitSpecValue(
	ak types.AccountKeeper,
	bk types.BankKeeper,
	k keeper.Keeper,
) simtypes.Operation {
	return func(r *rand.Rand, app *baseapp.BaseApp, ctx sdk.Context, accs []simtypes.Account, chainID string,
	) (simtypes.OperationMsg, []simtypes.FutureOperation, error) {
		simAccount, _ := simtypes.RandomAcc(r, accs)
		msg := &types.MsgSubmitSpecValue{
			Creator: simAccount.Address.String(),
		}

		// TODO: Handling the SubmitSpecValue simulation

		return simtypes.NoOpMsg(types.ModuleName, msg.Type(), "SubmitSpecValue simulation not implemented"), nil, nil
	}
}
