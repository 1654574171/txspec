package types

import (
	sdk "github.com/cosmos/cosmos-sdk/types"
	sdkerrors "github.com/cosmos/cosmos-sdk/types/errors"
)

const TypeMsgSubmitSpecValue = "submit_spec_value"

var _ sdk.Msg = &MsgSubmitSpecValue{}

func NewMsgSubmitSpecValue(creator string, relatedTxHash string, data string, datahash string, signature string, contractAddress string) *MsgSubmitSpecValue {
  return &MsgSubmitSpecValue{
		Creator: creator,
    RelatedTxHash: relatedTxHash,
    Data: data,
    Datahash: datahash,
    Signature: signature,
    ContractAddress: contractAddress,
	}
}

func (msg *MsgSubmitSpecValue) Route() string {
  return RouterKey
}

func (msg *MsgSubmitSpecValue) Type() string {
  return TypeMsgSubmitSpecValue
}

func (msg *MsgSubmitSpecValue) GetSigners() []sdk.AccAddress {
  creator, err := sdk.AccAddressFromBech32(msg.Creator)
  if err != nil {
    panic(err)
  }
  return []sdk.AccAddress{creator}
}

func (msg *MsgSubmitSpecValue) GetSignBytes() []byte {
  bz := ModuleCdc.MustMarshalJSON(msg)
  return sdk.MustSortJSON(bz)
}

func (msg *MsgSubmitSpecValue) ValidateBasic() error {
  _, err := sdk.AccAddressFromBech32(msg.Creator)
  	if err != nil {
  		return sdkerrors.Wrapf(sdkerrors.ErrInvalidAddress, "invalid creator address (%s)", err)
  	}
  return nil
}

