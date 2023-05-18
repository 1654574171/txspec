package keeper

import (
	sdk "github.com/cosmos/cosmos-sdk/types"
)

// HandlerOptions are the options required for constructing a default SDK AnteHandler.
type HandlerOptions struct {
	RegulatoryKeeper Keeper
}
type VerifyProofDecorator struct {
	regulatoryKeeper Keeper
}
type ComplianceProofDecorator struct {
	regulatoryKeeper Keeper
}

func NewComplianceProofDecorator(regulatoryKeeper Keeper) ComplianceProofDecorator {
	return ComplianceProofDecorator{
		regulatoryKeeper: regulatoryKeeper,
	}
}
func NewVerifyProofDecorator(regulatoryKeeper Keeper) VerifyProofDecorator {
	return VerifyProofDecorator{
		regulatoryKeeper: regulatoryKeeper,
	}
}

// AnteHandler :used to get compliance cproof from Compliance Engine
func (sud ComplianceProofDecorator) AnteHandle(ctx sdk.Context, tx sdk.Tx, runRegulateTx bool, next sdk.AnteHandler) (newCtx sdk.Context, err error) {

	if !runRegulateTx {

		_ = sud.regulatoryKeeper.GetCompliance(ctx, tx)

		return next(ctx, tx, runRegulateTx)
	}

	return next(ctx, tx, runRegulateTx)
}

func NewRegulatoryPostHandler(options HandlerOptions) (sdk.AnteHandler, error) {
	anteDecorators := []sdk.AnteDecorator{
		NewComplianceProofDecorator(options.RegulatoryKeeper), // outermost AnteDecorator. SetUpContext must be called first
	}
	return sdk.ChainAnteDecorators(anteDecorators...), nil
}
