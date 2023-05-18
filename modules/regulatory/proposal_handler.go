package regulatory

import (
	"crypto/sha256"
	"encoding/base64"
	"encoding/hex"
	"strings"

	"github.com/irisnet/irishub/modules/regulatory/keeper"

	"github.com/irisnet/irishub/modules/regulatory/types"

	sdk "github.com/cosmos/cosmos-sdk/types"

	sdkerrors "github.com/cosmos/cosmos-sdk/types/errors"
	govtypes "github.com/cosmos/cosmos-sdk/x/gov/types/v1beta1"
)

// NewParamChangeProposalHandler creates a new governance Handler for a ParamChangeProposal
func NewRegulatoryProposalHandler(k keeper.Keeper) govtypes.Handler {
	return func(ctx sdk.Context, content govtypes.Content) error {
		switch c := content.(type) {
		case *types.RuleProposal:

			return handleRuleProposal(ctx, k, c)

		case *types.BindingProposal:
			return handleBindingProposal(ctx, k, c)
		case *types.RegisterProposal:
			return handleRegisterProposal(ctx, k, c)
		case *types.RelationProposal:
			return handleRelationProposal(ctx, k, c)
		case *types.SuspiciousProposal:
			return handleSuspiciousProposal(ctx, k, c)
		case *types.RewardListProposal:
			return handleRewardListProposal(ctx, k, c)
		default:
			return sdkerrors.Wrapf(sdkerrors.ErrUnknownRequest, "unrecognized param proposal content type: %T", c)
		}
	}
}

func handleRuleProposal(ctx sdk.Context, k keeper.Keeper, rp *types.RuleProposal) error {
	_, found := k.GetRule(ctx, rp.Rule.RuleName)
	switch rp.OperationType {
	case "insert":
		{
			if found {
				return types.ErrEntityAlreadyExists
			}

			hash := sha256.Sum256([]byte(rp.Rule.RuleName + rp.Rule.Content))
			rp.Rule.Hash = hex.EncodeToString(hash[:])
			content, err := base64.StdEncoding.DecodeString(rp.Rule.Content)
			if err != nil {
				//rule content base64 decode error
				return types.ErrInvalidRuleContent
			}
			rp.Rule.Content = string(content)
			k.SetRule(ctx, *rp.Rule)

		}
	case "update":
		{
			if !found {
				return types.ErrEntityNonExists
			}
			hash := sha256.Sum256([]byte(rp.Rule.RuleName + rp.Rule.Content))
			rp.Rule.Hash = hex.EncodeToString(hash[:])
			content, err := base64.StdEncoding.DecodeString(rp.Rule.Content)
			if err != nil {
				//rule content base64 decode error
				return types.ErrInvalidRuleContent
			}
			rp.Rule.Content = string(content)
			k.SetRule(ctx, *rp.Rule)
		}
	case "delete":
		{
			if !found {
				return types.ErrEntityNonExists
			}
			k.RemoveRule(ctx, rp.Rule.RuleName)
		}
	default:
		return types.ErrInvalidOperationType
	}
	ctx.EventManager().EmitEvent(
		sdk.NewEvent(
			types.EventTypeRuleProposal,
			sdk.NewAttribute(types.AttributeKeyRuleName, rp.Rule.RuleName),
			sdk.NewAttribute(types.AttributeKeyRuleContent, rp.Rule.Content),
			sdk.NewAttribute(types.AttributeKeyRuleHash, rp.Rule.Hash),
			sdk.NewAttribute(types.AttributeKeyOperationType, rp.OperationType),
		),
	)
	return nil
}

func handleBindingProposal(ctx sdk.Context, k keeper.Keeper, bp *types.BindingProposal) error {
	_, found := k.GetBinding(ctx, bp.Binding.BindingName)
	switch bp.OperationType {
	case "insert":
		{
			if found {
				return types.ErrEntityAlreadyExists
			}
			hash := sha256.Sum256([]byte(bp.Binding.BindingName + bp.Binding.Content))
			bp.Binding.Hash = hex.EncodeToString(hash[:])

			content, err := base64.StdEncoding.DecodeString(bp.Binding.Content)
			if err != nil {
				//rule content base64 decode error
				return types.ErrInvalidBindingContent
			}
			bp.Binding.Content = string(content)
			k.SetBinding(ctx, *bp.Binding)
		}
	case "update":
		{
			if !found {
				return types.ErrEntityNonExists
			}
			hash := sha256.Sum256([]byte(bp.Binding.BindingName + bp.Binding.Content))
			bp.Binding.Hash = hex.EncodeToString(hash[:])
			content, err := base64.StdEncoding.DecodeString(bp.Binding.Content)
			if err != nil {
				//rule content base64 decode error
				return types.ErrInvalidBindingContent
			}
			bp.Binding.Content = string(content)
			k.SetBinding(ctx, *bp.Binding)
		}
	case "delete":
		{
			if !found {
				return types.ErrEntityNonExists
			}
			k.RemoveBinding(ctx, bp.Binding.BindingName)
		}
	default:
		return types.ErrInvalidOperationType
	}

	ctx.EventManager().EmitEvent(
		sdk.NewEvent(
			types.EventTypeBindingProposal,
			sdk.NewAttribute(types.AttributeKeyBindingName, bp.Binding.BindingName),
			sdk.NewAttribute(types.AttributeKeyBindingContent, bp.Binding.Content),
			sdk.NewAttribute(types.AttributeKeyBindingHash, bp.Binding.Hash),
			sdk.NewAttribute(types.AttributeKeyBindingRuleFilesNames, strings.Join(bp.Binding.RuleFilesNames, ",")),
			sdk.NewAttribute(types.AttributeKeyOperationType, bp.OperationType),
		),
	)
	return nil
}
func handleRelationProposal(ctx sdk.Context, k keeper.Keeper, rp *types.RelationProposal) error {

	_, found := k.GetRelation(ctx, rp.Relation.ContractAddress)
	switch rp.OperationType {
	case "insert":
		{
			if found {
				return types.ErrEntityAlreadyExists
			}
			k.SetRelation(ctx, *rp.Relation)
		}
	case "update":
		{
			if !found {
				return types.ErrEntityNonExists
			}
			k.SetRelation(ctx, *rp.Relation)
		}
	case "delete":
		{
			if !found {
				return types.ErrEntityNonExists
			}
			k.RemoveRelation(ctx, rp.Relation.ContractAddress)
		}
	default:
		return types.ErrInvalidOperationType
	}

	ctx.EventManager().EmitEvent(
		sdk.NewEvent(
			types.EventTypeRelationProposal,
			sdk.NewAttribute(types.AttributeKeyContractAddress, rp.Relation.ContractAddress),
			sdk.NewAttribute(types.AttributeKeyBindingName, rp.Relation.BindingName),
			sdk.NewAttribute(types.AttributeKeyOperationType, rp.OperationType),
		),
	)
	return nil
}

func handleRegisterProposal(ctx sdk.Context, k keeper.Keeper, rp *types.RegisterProposal) error {

	//TODO validate register response

	registrationInfo := types.Registration{
		RegulatoryServiceName: rp.Registration.RegulatoryServiceName,
		IasAttestatioReport:   rp.Registration.IasAttestatioReport,
		EnclavePK:             rp.Registration.EnclavePK,
		Endpoint:              rp.Registration.Endpoint,
	}
	_, found := k.GetRegistration(ctx, rp.Registration.RegulatoryServiceName)
	switch rp.OperationType {
	case "insert":
		{
			if found {
				return types.ErrEntityAlreadyExists
			}
			k.SetRegistration(ctx, registrationInfo)
			stream := keeper.CreateStream(ctx, k, registrationInfo)
			err := k.UpdateComplianceServiceStreamMap(stream, "insert", registrationInfo.RegulatoryServiceName)
			if err != nil {
				k.Logger(ctx).Info("stream instert error")
			}
		}
	case "update":
		{
			if !found {
				return types.ErrEntityNonExists
			}
			k.SetRegistration(ctx, registrationInfo)
			stream := keeper.CreateStream(ctx, k, registrationInfo)
			err := k.UpdateComplianceServiceStreamMap(stream, "update", registrationInfo.RegulatoryServiceName)
			if err != nil {
				k.Logger(ctx).Info("stream update error")
			}
		}
	case "delete":
		{
			if !found {
				return types.ErrEntityNonExists
			}
			k.RemoveRegistration(ctx, rp.Registration.RegulatoryServiceName)
			err := k.UpdateComplianceServiceStreamMap(nil, "delete", registrationInfo.RegulatoryServiceName)
			if err != nil {
				k.Logger(ctx).Info("stream delete error")
			}
		}
	default:
		return types.ErrInvalidOperationType
	}

	ctx.EventManager().EmitEvent(
		sdk.NewEvent(
			types.EventTypeRegisterProposal,
			sdk.NewAttribute(types.AttributeKeyRegulatoryServiceName, registrationInfo.RegulatoryServiceName),

			sdk.NewAttribute(types.AttributeKeyOperationType, rp.OperationType),
		),
	)
	return nil
}

//处理黑名单提案
func handleSuspiciousProposal(ctx sdk.Context, k keeper.Keeper, sp *types.SuspiciousProposal) error {

	suspiciousAccountList := types.SuspiciousAccountList{
		ContractAddress: sp.SuspiciousAccountList.ContractAddress,
		Account:         sp.SuspiciousAccountList.Account,
	}
	//查看历史是否存在该合约的黑名单信息
	alreadySuspiciousAccountList, found := k.GetSuspiciousAccountList(ctx, suspiciousAccountList.ContractAddress)
	if found {
		//如果已存在，则将新的account追加
		//TODO 判断新增的account是否已存在account list中，如果存在跳过添加
		alreadySuspiciousAccountList.Account = append(alreadySuspiciousAccountList.Account, suspiciousAccountList.Account...)
	} else {
		alreadySuspiciousAccountList = suspiciousAccountList
	}
	k.SetSuspiciousAccountList(ctx, alreadySuspiciousAccountList)
	ctx.EventManager().EmitEvent(
		sdk.NewEvent(
			types.EventTypeSuspiciousUpdate,
			sdk.NewAttribute(types.AttributeKeyContractAddress, sp.SuspiciousAccountList.ContractAddress),
			//将所有新增的account address以string输出
			sdk.NewAttribute(types.AttributeKeySuspiciousAccounts, strings.Join(sp.SuspiciousAccountList.Account, ",")),
		),
	)
	return nil
}
func handleRewardListProposal(ctx sdk.Context, k keeper.Keeper, rp *types.RewardListProposal) error {
	alreadyList, found := k.GetRewardList(ctx, rp.List.ContractAddress)
	switch rp.OperationType {
	case "insert":
		{
			if found {
				alreadyList.List = append(alreadyList.List, rp.List.List...)
			} else {
				rewardList := types.RewardList{
					ContractAddress: rp.List.ContractAddress,
					List:            rp.List.List,
				}
				alreadyList = rewardList
			}
			k.SetRewardList(ctx, alreadyList)
		}
	case "update":
		{
			if !found {
				return types.ErrEntityNonExists
			}

			rewardList := types.RewardList{
				ContractAddress: rp.List.ContractAddress,
				List:            rp.List.List,
			}
			k.SetRewardList(ctx, rewardList)

		}
	case "delete":
		{
			if !found {
				return types.ErrEntityNonExists
			}
			k.RemoveRewardList(ctx, rp.List.ContractAddress)
		}
	default:
		return types.ErrInvalidOperationType
	}

	for _, item := range rp.List.List {
		ctx.EventManager().EmitEvent(
			sdk.NewEvent(
				types.EventTypeRewardListProposal,
				sdk.NewAttribute(types.AttributeKeyContractAddress, rp.List.ContractAddress),
				sdk.NewAttribute(types.AttributeKeyRewardList, item),
				sdk.NewAttribute(types.AttributeKeyOperationType, rp.OperationType),
			),
		)
	}
	return nil
}
