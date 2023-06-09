// Code generated by protoc-gen-gogo. DO NOT EDIT.
// source: regulatory/regulatory/ProofResponse.proto

package types

import (
	fmt "fmt"
	proto "github.com/gogo/protobuf/proto"
	io "io"
	math "math"
	math_bits "math/bits"
)

// Reference imports to suppress errors if they are not otherwise used.
var _ = proto.Marshal
var _ = fmt.Errorf
var _ = math.Inf

// This is a compile-time assertion to ensure that this generated file
// is compatible with the proto package it is being compiled against.
// A compilation error at this line likely means your copy of the
// proto package needs to be updated.
const _ = proto.GoGoProtoPackageIsVersion3 // please upgrade the proto package

type ErrorInfo struct {
	Status       bool   `protobuf:"varint,1,opt,name=status,proto3" json:"status,omitempty"`
	RuleFileName string `protobuf:"bytes,2,opt,name=ruleFileName,proto3" json:"ruleFileName,omitempty"`
	RuleFileID   string `protobuf:"bytes,3,opt,name=ruleFileID,proto3" json:"ruleFileID,omitempty"`
	ErrorString  string `protobuf:"bytes,4,opt,name=errorString,proto3" json:"errorString,omitempty"`
}

func (m *ErrorInfo) Reset()         { *m = ErrorInfo{} }
func (m *ErrorInfo) String() string { return proto.CompactTextString(m) }
func (*ErrorInfo) ProtoMessage()    {}
func (*ErrorInfo) Descriptor() ([]byte, []int) {
	return fileDescriptor_d630e8d82f5d7f59, []int{0}
}
func (m *ErrorInfo) XXX_Unmarshal(b []byte) error {
	return m.Unmarshal(b)
}
func (m *ErrorInfo) XXX_Marshal(b []byte, deterministic bool) ([]byte, error) {
	if deterministic {
		return xxx_messageInfo_ErrorInfo.Marshal(b, m, deterministic)
	} else {
		b = b[:cap(b)]
		n, err := m.MarshalToSizedBuffer(b)
		if err != nil {
			return nil, err
		}
		return b[:n], nil
	}
}
func (m *ErrorInfo) XXX_Merge(src proto.Message) {
	xxx_messageInfo_ErrorInfo.Merge(m, src)
}
func (m *ErrorInfo) XXX_Size() int {
	return m.Size()
}
func (m *ErrorInfo) XXX_DiscardUnknown() {
	xxx_messageInfo_ErrorInfo.DiscardUnknown(m)
}

var xxx_messageInfo_ErrorInfo proto.InternalMessageInfo

func (m *ErrorInfo) GetStatus() bool {
	if m != nil {
		return m.Status
	}
	return false
}

func (m *ErrorInfo) GetRuleFileName() string {
	if m != nil {
		return m.RuleFileName
	}
	return ""
}

func (m *ErrorInfo) GetRuleFileID() string {
	if m != nil {
		return m.RuleFileID
	}
	return ""
}

func (m *ErrorInfo) GetErrorString() string {
	if m != nil {
		return m.ErrorString
	}
	return ""
}

type Receipt struct {
	Status       bool         `protobuf:"varint,1,opt,name=Status,proto3" json:"Status,omitempty"`
	Contractid   string       `protobuf:"bytes,2,opt,name=contractid,proto3" json:"contractid,omitempty"`
	BindingHash  []byte       `protobuf:"bytes,3,opt,name=bindingHash,proto3" json:"bindingHash,omitempty"`
	RuleFileHash [][]byte     `protobuf:"bytes,4,rep,name=ruleFileHash,proto3" json:"ruleFileHash,omitempty"`
	ErrorInfo    []*ErrorInfo `protobuf:"bytes,5,rep,name=errorInfo,proto3" json:"errorInfo,omitempty"`
}

func (m *Receipt) Reset()         { *m = Receipt{} }
func (m *Receipt) String() string { return proto.CompactTextString(m) }
func (*Receipt) ProtoMessage()    {}
func (*Receipt) Descriptor() ([]byte, []int) {
	return fileDescriptor_d630e8d82f5d7f59, []int{1}
}
func (m *Receipt) XXX_Unmarshal(b []byte) error {
	return m.Unmarshal(b)
}
func (m *Receipt) XXX_Marshal(b []byte, deterministic bool) ([]byte, error) {
	if deterministic {
		return xxx_messageInfo_Receipt.Marshal(b, m, deterministic)
	} else {
		b = b[:cap(b)]
		n, err := m.MarshalToSizedBuffer(b)
		if err != nil {
			return nil, err
		}
		return b[:n], nil
	}
}
func (m *Receipt) XXX_Merge(src proto.Message) {
	xxx_messageInfo_Receipt.Merge(m, src)
}
func (m *Receipt) XXX_Size() int {
	return m.Size()
}
func (m *Receipt) XXX_DiscardUnknown() {
	xxx_messageInfo_Receipt.DiscardUnknown(m)
}

var xxx_messageInfo_Receipt proto.InternalMessageInfo

func (m *Receipt) GetStatus() bool {
	if m != nil {
		return m.Status
	}
	return false
}

func (m *Receipt) GetContractid() string {
	if m != nil {
		return m.Contractid
	}
	return ""
}

func (m *Receipt) GetBindingHash() []byte {
	if m != nil {
		return m.BindingHash
	}
	return nil
}

func (m *Receipt) GetRuleFileHash() [][]byte {
	if m != nil {
		return m.RuleFileHash
	}
	return nil
}

func (m *Receipt) GetErrorInfo() []*ErrorInfo {
	if m != nil {
		return m.ErrorInfo
	}
	return nil
}

type Proof struct {
	Status      bool       `protobuf:"varint,1,opt,name=status,proto3" json:"status,omitempty"`
	RequestHash []byte     `protobuf:"bytes,2,opt,name=RequestHash,proto3" json:"RequestHash,omitempty"`
	StateHash   []byte     `protobuf:"bytes,3,opt,name=StateHash,proto3" json:"StateHash,omitempty"`
	Receipts    []*Receipt `protobuf:"bytes,4,rep,name=receipts,proto3" json:"receipts,omitempty"`
	Signature   []byte     `protobuf:"bytes,5,opt,name=Signature,proto3" json:"Signature,omitempty"`
}

func (m *Proof) Reset()         { *m = Proof{} }
func (m *Proof) String() string { return proto.CompactTextString(m) }
func (*Proof) ProtoMessage()    {}
func (*Proof) Descriptor() ([]byte, []int) {
	return fileDescriptor_d630e8d82f5d7f59, []int{2}
}
func (m *Proof) XXX_Unmarshal(b []byte) error {
	return m.Unmarshal(b)
}
func (m *Proof) XXX_Marshal(b []byte, deterministic bool) ([]byte, error) {
	if deterministic {
		return xxx_messageInfo_Proof.Marshal(b, m, deterministic)
	} else {
		b = b[:cap(b)]
		n, err := m.MarshalToSizedBuffer(b)
		if err != nil {
			return nil, err
		}
		return b[:n], nil
	}
}
func (m *Proof) XXX_Merge(src proto.Message) {
	xxx_messageInfo_Proof.Merge(m, src)
}
func (m *Proof) XXX_Size() int {
	return m.Size()
}
func (m *Proof) XXX_DiscardUnknown() {
	xxx_messageInfo_Proof.DiscardUnknown(m)
}

var xxx_messageInfo_Proof proto.InternalMessageInfo

func (m *Proof) GetStatus() bool {
	if m != nil {
		return m.Status
	}
	return false
}

func (m *Proof) GetRequestHash() []byte {
	if m != nil {
		return m.RequestHash
	}
	return nil
}

func (m *Proof) GetStateHash() []byte {
	if m != nil {
		return m.StateHash
	}
	return nil
}

func (m *Proof) GetReceipts() []*Receipt {
	if m != nil {
		return m.Receipts
	}
	return nil
}

func (m *Proof) GetSignature() []byte {
	if m != nil {
		return m.Signature
	}
	return nil
}

type ProofResponse struct {
	TxHash       []byte   `protobuf:"bytes,1,opt,name=TxHash,proto3" json:"TxHash,omitempty"`
	ProofsHash   []byte   `protobuf:"bytes,2,opt,name=ProofsHash,proto3" json:"ProofsHash,omitempty"`
	Proofs       []*Proof `protobuf:"bytes,3,rep,name=Proofs,proto3" json:"Proofs,omitempty"`
	TeeSignature []byte   `protobuf:"bytes,4,opt,name=TeeSignature,proto3" json:"TeeSignature,omitempty"`
}

func (m *ProofResponse) Reset()         { *m = ProofResponse{} }
func (m *ProofResponse) String() string { return proto.CompactTextString(m) }
func (*ProofResponse) ProtoMessage()    {}
func (*ProofResponse) Descriptor() ([]byte, []int) {
	return fileDescriptor_d630e8d82f5d7f59, []int{3}
}
func (m *ProofResponse) XXX_Unmarshal(b []byte) error {
	return m.Unmarshal(b)
}
func (m *ProofResponse) XXX_Marshal(b []byte, deterministic bool) ([]byte, error) {
	if deterministic {
		return xxx_messageInfo_ProofResponse.Marshal(b, m, deterministic)
	} else {
		b = b[:cap(b)]
		n, err := m.MarshalToSizedBuffer(b)
		if err != nil {
			return nil, err
		}
		return b[:n], nil
	}
}
func (m *ProofResponse) XXX_Merge(src proto.Message) {
	xxx_messageInfo_ProofResponse.Merge(m, src)
}
func (m *ProofResponse) XXX_Size() int {
	return m.Size()
}
func (m *ProofResponse) XXX_DiscardUnknown() {
	xxx_messageInfo_ProofResponse.DiscardUnknown(m)
}

var xxx_messageInfo_ProofResponse proto.InternalMessageInfo

func (m *ProofResponse) GetTxHash() []byte {
	if m != nil {
		return m.TxHash
	}
	return nil
}

func (m *ProofResponse) GetProofsHash() []byte {
	if m != nil {
		return m.ProofsHash
	}
	return nil
}

func (m *ProofResponse) GetProofs() []*Proof {
	if m != nil {
		return m.Proofs
	}
	return nil
}

func (m *ProofResponse) GetTeeSignature() []byte {
	if m != nil {
		return m.TeeSignature
	}
	return nil
}

func init() {
	proto.RegisterType((*ErrorInfo)(nil), "request_proto.ErrorInfo")
	proto.RegisterType((*Receipt)(nil), "request_proto.Receipt")
	proto.RegisterType((*Proof)(nil), "request_proto.Proof")
	proto.RegisterType((*ProofResponse)(nil), "request_proto.ProofResponse")
}

func init() {
	proto.RegisterFile("regulatory/regulatory/ProofResponse.proto", fileDescriptor_d630e8d82f5d7f59)
}

var fileDescriptor_d630e8d82f5d7f59 = []byte{
	// 411 bytes of a gzipped FileDescriptorProto
	0x1f, 0x8b, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0xff, 0x74, 0x92, 0x31, 0x6f, 0xda, 0x40,
	0x18, 0x86, 0x39, 0x0c, 0x14, 0x9f, 0x61, 0x39, 0x55, 0xe8, 0x86, 0xd6, 0xb2, 0x3c, 0xb9, 0x52,
	0x45, 0x25, 0x2a, 0xb5, 0x7b, 0xd5, 0x56, 0x65, 0xa9, 0xa2, 0x83, 0x29, 0x4b, 0x64, 0xe0, 0xc3,
	0xb1, 0x44, 0x7c, 0xce, 0xdd, 0x59, 0x82, 0x9f, 0x90, 0x2d, 0x6b, 0x7e, 0x46, 0x7e, 0x41, 0xd6,
	0x8c, 0x8c, 0x19, 0x23, 0xf8, 0x23, 0xd1, 0x9d, 0x0d, 0x9c, 0x91, 0xb2, 0xf9, 0x7b, 0xf5, 0xea,
	0x7b, 0x9f, 0x7b, 0xfd, 0xe1, 0x2f, 0x02, 0x92, 0x62, 0x15, 0x2b, 0x2e, 0x36, 0xdf, 0xac, 0xcf,
	0x0b, 0xc1, 0xf9, 0x92, 0x81, 0xcc, 0x79, 0x26, 0x61, 0x98, 0x0b, 0xae, 0x38, 0xe9, 0x0b, 0xb8,
	0x2d, 0x40, 0xaa, 0x2b, 0x33, 0x86, 0x77, 0x08, 0xbb, 0x7f, 0x84, 0xe0, 0x62, 0x9c, 0x2d, 0x39,
	0x19, 0xe0, 0x8e, 0x54, 0xb1, 0x2a, 0x24, 0x45, 0x01, 0x8a, 0xba, 0xac, 0x9a, 0x48, 0x88, 0x7b,
	0xa2, 0x58, 0xc1, 0xdf, 0x74, 0x05, 0xff, 0xe3, 0x1b, 0xa0, 0xcd, 0x00, 0x45, 0x2e, 0xab, 0x69,
	0xc4, 0xc7, 0xf8, 0x30, 0x8f, 0x7f, 0x53, 0xc7, 0x38, 0x2c, 0x85, 0x04, 0xd8, 0x03, 0x1d, 0x34,
	0x51, 0x22, 0xcd, 0x12, 0xda, 0x32, 0x06, 0x5b, 0x0a, 0x9f, 0x10, 0xfe, 0xc0, 0x60, 0x0e, 0x69,
	0xae, 0x34, 0xc9, 0xa4, 0x46, 0x52, 0x4e, 0x3a, 0x65, 0xce, 0x33, 0x25, 0xe2, 0xb9, 0x4a, 0x17,
	0x15, 0x87, 0xa5, 0xe8, 0x94, 0x59, 0x9a, 0x2d, 0xd2, 0x2c, 0xf9, 0x17, 0xcb, 0x6b, 0x83, 0xd1,
	0x63, 0xb6, 0x64, 0xbf, 0xc5, 0x58, 0x5a, 0x81, 0x13, 0xf5, 0x58, 0x4d, 0x23, 0x3f, 0xb0, 0x0b,
	0x87, 0x52, 0x68, 0x3b, 0x70, 0x22, 0x6f, 0x44, 0x87, 0xb5, 0xe2, 0x86, 0xc7, 0xd2, 0xd8, 0xc9,
	0x1a, 0x3e, 0x22, 0xdc, 0x36, 0xa5, 0xbf, 0xdb, 0x64, 0x80, 0x3d, 0x56, 0xee, 0x31, 0xe1, 0xcd,
	0x92, 0xcf, 0x92, 0xc8, 0x27, 0xec, 0xea, 0xb7, 0x82, 0xc5, 0x7f, 0x12, 0xc8, 0x08, 0x77, 0x45,
	0x59, 0x91, 0x34, 0xe4, 0xde, 0x68, 0x70, 0x06, 0x56, 0x35, 0xc8, 0x8e, 0x3e, 0xb3, 0x31, 0x4d,
	0xb2, 0x58, 0x15, 0x02, 0x68, 0xbb, 0xda, 0x78, 0x10, 0xc2, 0x07, 0x84, 0xfb, 0xb5, 0x43, 0xd1,
	0xec, 0xd3, 0xb5, 0x89, 0x47, 0xc6, 0x5c, 0x4d, 0xba, 0x7b, 0x63, 0x94, 0x16, 0xba, 0xa5, 0x90,
	0xaf, 0xb8, 0x53, 0x4e, 0xd4, 0x31, 0x64, 0x1f, 0xcf, 0xc8, 0xca, 0x94, 0xca, 0xa3, 0xff, 0xc3,
	0x14, 0xe0, 0x04, 0xd6, 0x32, 0xfb, 0x6a, 0xda, 0xaf, 0x9f, 0xcf, 0x3b, 0x1f, 0x6d, 0x77, 0x3e,
	0x7a, 0xdd, 0xf9, 0xe8, 0x7e, 0xef, 0x37, 0xb6, 0x7b, 0xbf, 0xf1, 0xb2, 0xf7, 0x1b, 0x97, 0x9f,
	0xad, 0x33, 0x5f, 0xdb, 0x37, 0xaf, 0x36, 0x39, 0xc8, 0x59, 0xc7, 0x24, 0x7e, 0x7f, 0x0b, 0x00,
	0x00, 0xff, 0xff, 0xe8, 0x29, 0x8e, 0xcd, 0x19, 0x03, 0x00, 0x00,
}

func (m *ErrorInfo) Marshal() (dAtA []byte, err error) {
	size := m.Size()
	dAtA = make([]byte, size)
	n, err := m.MarshalToSizedBuffer(dAtA[:size])
	if err != nil {
		return nil, err
	}
	return dAtA[:n], nil
}

func (m *ErrorInfo) MarshalTo(dAtA []byte) (int, error) {
	size := m.Size()
	return m.MarshalToSizedBuffer(dAtA[:size])
}

func (m *ErrorInfo) MarshalToSizedBuffer(dAtA []byte) (int, error) {
	i := len(dAtA)
	_ = i
	var l int
	_ = l
	if len(m.ErrorString) > 0 {
		i -= len(m.ErrorString)
		copy(dAtA[i:], m.ErrorString)
		i = encodeVarintProofResponse(dAtA, i, uint64(len(m.ErrorString)))
		i--
		dAtA[i] = 0x22
	}
	if len(m.RuleFileID) > 0 {
		i -= len(m.RuleFileID)
		copy(dAtA[i:], m.RuleFileID)
		i = encodeVarintProofResponse(dAtA, i, uint64(len(m.RuleFileID)))
		i--
		dAtA[i] = 0x1a
	}
	if len(m.RuleFileName) > 0 {
		i -= len(m.RuleFileName)
		copy(dAtA[i:], m.RuleFileName)
		i = encodeVarintProofResponse(dAtA, i, uint64(len(m.RuleFileName)))
		i--
		dAtA[i] = 0x12
	}
	if m.Status {
		i--
		if m.Status {
			dAtA[i] = 1
		} else {
			dAtA[i] = 0
		}
		i--
		dAtA[i] = 0x8
	}
	return len(dAtA) - i, nil
}

func (m *Receipt) Marshal() (dAtA []byte, err error) {
	size := m.Size()
	dAtA = make([]byte, size)
	n, err := m.MarshalToSizedBuffer(dAtA[:size])
	if err != nil {
		return nil, err
	}
	return dAtA[:n], nil
}

func (m *Receipt) MarshalTo(dAtA []byte) (int, error) {
	size := m.Size()
	return m.MarshalToSizedBuffer(dAtA[:size])
}

func (m *Receipt) MarshalToSizedBuffer(dAtA []byte) (int, error) {
	i := len(dAtA)
	_ = i
	var l int
	_ = l
	if len(m.ErrorInfo) > 0 {
		for iNdEx := len(m.ErrorInfo) - 1; iNdEx >= 0; iNdEx-- {
			{
				size, err := m.ErrorInfo[iNdEx].MarshalToSizedBuffer(dAtA[:i])
				if err != nil {
					return 0, err
				}
				i -= size
				i = encodeVarintProofResponse(dAtA, i, uint64(size))
			}
			i--
			dAtA[i] = 0x2a
		}
	}
	if len(m.RuleFileHash) > 0 {
		for iNdEx := len(m.RuleFileHash) - 1; iNdEx >= 0; iNdEx-- {
			i -= len(m.RuleFileHash[iNdEx])
			copy(dAtA[i:], m.RuleFileHash[iNdEx])
			i = encodeVarintProofResponse(dAtA, i, uint64(len(m.RuleFileHash[iNdEx])))
			i--
			dAtA[i] = 0x22
		}
	}
	if len(m.BindingHash) > 0 {
		i -= len(m.BindingHash)
		copy(dAtA[i:], m.BindingHash)
		i = encodeVarintProofResponse(dAtA, i, uint64(len(m.BindingHash)))
		i--
		dAtA[i] = 0x1a
	}
	if len(m.Contractid) > 0 {
		i -= len(m.Contractid)
		copy(dAtA[i:], m.Contractid)
		i = encodeVarintProofResponse(dAtA, i, uint64(len(m.Contractid)))
		i--
		dAtA[i] = 0x12
	}
	if m.Status {
		i--
		if m.Status {
			dAtA[i] = 1
		} else {
			dAtA[i] = 0
		}
		i--
		dAtA[i] = 0x8
	}
	return len(dAtA) - i, nil
}

func (m *Proof) Marshal() (dAtA []byte, err error) {
	size := m.Size()
	dAtA = make([]byte, size)
	n, err := m.MarshalToSizedBuffer(dAtA[:size])
	if err != nil {
		return nil, err
	}
	return dAtA[:n], nil
}

func (m *Proof) MarshalTo(dAtA []byte) (int, error) {
	size := m.Size()
	return m.MarshalToSizedBuffer(dAtA[:size])
}

func (m *Proof) MarshalToSizedBuffer(dAtA []byte) (int, error) {
	i := len(dAtA)
	_ = i
	var l int
	_ = l
	if len(m.Signature) > 0 {
		i -= len(m.Signature)
		copy(dAtA[i:], m.Signature)
		i = encodeVarintProofResponse(dAtA, i, uint64(len(m.Signature)))
		i--
		dAtA[i] = 0x2a
	}
	if len(m.Receipts) > 0 {
		for iNdEx := len(m.Receipts) - 1; iNdEx >= 0; iNdEx-- {
			{
				size, err := m.Receipts[iNdEx].MarshalToSizedBuffer(dAtA[:i])
				if err != nil {
					return 0, err
				}
				i -= size
				i = encodeVarintProofResponse(dAtA, i, uint64(size))
			}
			i--
			dAtA[i] = 0x22
		}
	}
	if len(m.StateHash) > 0 {
		i -= len(m.StateHash)
		copy(dAtA[i:], m.StateHash)
		i = encodeVarintProofResponse(dAtA, i, uint64(len(m.StateHash)))
		i--
		dAtA[i] = 0x1a
	}
	if len(m.RequestHash) > 0 {
		i -= len(m.RequestHash)
		copy(dAtA[i:], m.RequestHash)
		i = encodeVarintProofResponse(dAtA, i, uint64(len(m.RequestHash)))
		i--
		dAtA[i] = 0x12
	}
	if m.Status {
		i--
		if m.Status {
			dAtA[i] = 1
		} else {
			dAtA[i] = 0
		}
		i--
		dAtA[i] = 0x8
	}
	return len(dAtA) - i, nil
}

func (m *ProofResponse) Marshal() (dAtA []byte, err error) {
	size := m.Size()
	dAtA = make([]byte, size)
	n, err := m.MarshalToSizedBuffer(dAtA[:size])
	if err != nil {
		return nil, err
	}
	return dAtA[:n], nil
}

func (m *ProofResponse) MarshalTo(dAtA []byte) (int, error) {
	size := m.Size()
	return m.MarshalToSizedBuffer(dAtA[:size])
}

func (m *ProofResponse) MarshalToSizedBuffer(dAtA []byte) (int, error) {
	i := len(dAtA)
	_ = i
	var l int
	_ = l
	if len(m.TeeSignature) > 0 {
		i -= len(m.TeeSignature)
		copy(dAtA[i:], m.TeeSignature)
		i = encodeVarintProofResponse(dAtA, i, uint64(len(m.TeeSignature)))
		i--
		dAtA[i] = 0x22
	}
	if len(m.Proofs) > 0 {
		for iNdEx := len(m.Proofs) - 1; iNdEx >= 0; iNdEx-- {
			{
				size, err := m.Proofs[iNdEx].MarshalToSizedBuffer(dAtA[:i])
				if err != nil {
					return 0, err
				}
				i -= size
				i = encodeVarintProofResponse(dAtA, i, uint64(size))
			}
			i--
			dAtA[i] = 0x1a
		}
	}
	if len(m.ProofsHash) > 0 {
		i -= len(m.ProofsHash)
		copy(dAtA[i:], m.ProofsHash)
		i = encodeVarintProofResponse(dAtA, i, uint64(len(m.ProofsHash)))
		i--
		dAtA[i] = 0x12
	}
	if len(m.TxHash) > 0 {
		i -= len(m.TxHash)
		copy(dAtA[i:], m.TxHash)
		i = encodeVarintProofResponse(dAtA, i, uint64(len(m.TxHash)))
		i--
		dAtA[i] = 0xa
	}
	return len(dAtA) - i, nil
}

func encodeVarintProofResponse(dAtA []byte, offset int, v uint64) int {
	offset -= sovProofResponse(v)
	base := offset
	for v >= 1<<7 {
		dAtA[offset] = uint8(v&0x7f | 0x80)
		v >>= 7
		offset++
	}
	dAtA[offset] = uint8(v)
	return base
}
func (m *ErrorInfo) Size() (n int) {
	if m == nil {
		return 0
	}
	var l int
	_ = l
	if m.Status {
		n += 2
	}
	l = len(m.RuleFileName)
	if l > 0 {
		n += 1 + l + sovProofResponse(uint64(l))
	}
	l = len(m.RuleFileID)
	if l > 0 {
		n += 1 + l + sovProofResponse(uint64(l))
	}
	l = len(m.ErrorString)
	if l > 0 {
		n += 1 + l + sovProofResponse(uint64(l))
	}
	return n
}

func (m *Receipt) Size() (n int) {
	if m == nil {
		return 0
	}
	var l int
	_ = l
	if m.Status {
		n += 2
	}
	l = len(m.Contractid)
	if l > 0 {
		n += 1 + l + sovProofResponse(uint64(l))
	}
	l = len(m.BindingHash)
	if l > 0 {
		n += 1 + l + sovProofResponse(uint64(l))
	}
	if len(m.RuleFileHash) > 0 {
		for _, b := range m.RuleFileHash {
			l = len(b)
			n += 1 + l + sovProofResponse(uint64(l))
		}
	}
	if len(m.ErrorInfo) > 0 {
		for _, e := range m.ErrorInfo {
			l = e.Size()
			n += 1 + l + sovProofResponse(uint64(l))
		}
	}
	return n
}

func (m *Proof) Size() (n int) {
	if m == nil {
		return 0
	}
	var l int
	_ = l
	if m.Status {
		n += 2
	}
	l = len(m.RequestHash)
	if l > 0 {
		n += 1 + l + sovProofResponse(uint64(l))
	}
	l = len(m.StateHash)
	if l > 0 {
		n += 1 + l + sovProofResponse(uint64(l))
	}
	if len(m.Receipts) > 0 {
		for _, e := range m.Receipts {
			l = e.Size()
			n += 1 + l + sovProofResponse(uint64(l))
		}
	}
	l = len(m.Signature)
	if l > 0 {
		n += 1 + l + sovProofResponse(uint64(l))
	}
	return n
}

func (m *ProofResponse) Size() (n int) {
	if m == nil {
		return 0
	}
	var l int
	_ = l
	l = len(m.TxHash)
	if l > 0 {
		n += 1 + l + sovProofResponse(uint64(l))
	}
	l = len(m.ProofsHash)
	if l > 0 {
		n += 1 + l + sovProofResponse(uint64(l))
	}
	if len(m.Proofs) > 0 {
		for _, e := range m.Proofs {
			l = e.Size()
			n += 1 + l + sovProofResponse(uint64(l))
		}
	}
	l = len(m.TeeSignature)
	if l > 0 {
		n += 1 + l + sovProofResponse(uint64(l))
	}
	return n
}

func sovProofResponse(x uint64) (n int) {
	return (math_bits.Len64(x|1) + 6) / 7
}
func sozProofResponse(x uint64) (n int) {
	return sovProofResponse(uint64((x << 1) ^ uint64((int64(x) >> 63))))
}
func (m *ErrorInfo) Unmarshal(dAtA []byte) error {
	l := len(dAtA)
	iNdEx := 0
	for iNdEx < l {
		preIndex := iNdEx
		var wire uint64
		for shift := uint(0); ; shift += 7 {
			if shift >= 64 {
				return ErrIntOverflowProofResponse
			}
			if iNdEx >= l {
				return io.ErrUnexpectedEOF
			}
			b := dAtA[iNdEx]
			iNdEx++
			wire |= uint64(b&0x7F) << shift
			if b < 0x80 {
				break
			}
		}
		fieldNum := int32(wire >> 3)
		wireType := int(wire & 0x7)
		if wireType == 4 {
			return fmt.Errorf("proto: ErrorInfo: wiretype end group for non-group")
		}
		if fieldNum <= 0 {
			return fmt.Errorf("proto: ErrorInfo: illegal tag %d (wire type %d)", fieldNum, wire)
		}
		switch fieldNum {
		case 1:
			if wireType != 0 {
				return fmt.Errorf("proto: wrong wireType = %d for field Status", wireType)
			}
			var v int
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowProofResponse
				}
				if iNdEx >= l {
					return io.ErrUnexpectedEOF
				}
				b := dAtA[iNdEx]
				iNdEx++
				v |= int(b&0x7F) << shift
				if b < 0x80 {
					break
				}
			}
			m.Status = bool(v != 0)
		case 2:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field RuleFileName", wireType)
			}
			var stringLen uint64
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowProofResponse
				}
				if iNdEx >= l {
					return io.ErrUnexpectedEOF
				}
				b := dAtA[iNdEx]
				iNdEx++
				stringLen |= uint64(b&0x7F) << shift
				if b < 0x80 {
					break
				}
			}
			intStringLen := int(stringLen)
			if intStringLen < 0 {
				return ErrInvalidLengthProofResponse
			}
			postIndex := iNdEx + intStringLen
			if postIndex < 0 {
				return ErrInvalidLengthProofResponse
			}
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			m.RuleFileName = string(dAtA[iNdEx:postIndex])
			iNdEx = postIndex
		case 3:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field RuleFileID", wireType)
			}
			var stringLen uint64
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowProofResponse
				}
				if iNdEx >= l {
					return io.ErrUnexpectedEOF
				}
				b := dAtA[iNdEx]
				iNdEx++
				stringLen |= uint64(b&0x7F) << shift
				if b < 0x80 {
					break
				}
			}
			intStringLen := int(stringLen)
			if intStringLen < 0 {
				return ErrInvalidLengthProofResponse
			}
			postIndex := iNdEx + intStringLen
			if postIndex < 0 {
				return ErrInvalidLengthProofResponse
			}
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			m.RuleFileID = string(dAtA[iNdEx:postIndex])
			iNdEx = postIndex
		case 4:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field ErrorString", wireType)
			}
			var stringLen uint64
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowProofResponse
				}
				if iNdEx >= l {
					return io.ErrUnexpectedEOF
				}
				b := dAtA[iNdEx]
				iNdEx++
				stringLen |= uint64(b&0x7F) << shift
				if b < 0x80 {
					break
				}
			}
			intStringLen := int(stringLen)
			if intStringLen < 0 {
				return ErrInvalidLengthProofResponse
			}
			postIndex := iNdEx + intStringLen
			if postIndex < 0 {
				return ErrInvalidLengthProofResponse
			}
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			m.ErrorString = string(dAtA[iNdEx:postIndex])
			iNdEx = postIndex
		default:
			iNdEx = preIndex
			skippy, err := skipProofResponse(dAtA[iNdEx:])
			if err != nil {
				return err
			}
			if (skippy < 0) || (iNdEx+skippy) < 0 {
				return ErrInvalidLengthProofResponse
			}
			if (iNdEx + skippy) > l {
				return io.ErrUnexpectedEOF
			}
			iNdEx += skippy
		}
	}

	if iNdEx > l {
		return io.ErrUnexpectedEOF
	}
	return nil
}
func (m *Receipt) Unmarshal(dAtA []byte) error {
	l := len(dAtA)
	iNdEx := 0
	for iNdEx < l {
		preIndex := iNdEx
		var wire uint64
		for shift := uint(0); ; shift += 7 {
			if shift >= 64 {
				return ErrIntOverflowProofResponse
			}
			if iNdEx >= l {
				return io.ErrUnexpectedEOF
			}
			b := dAtA[iNdEx]
			iNdEx++
			wire |= uint64(b&0x7F) << shift
			if b < 0x80 {
				break
			}
		}
		fieldNum := int32(wire >> 3)
		wireType := int(wire & 0x7)
		if wireType == 4 {
			return fmt.Errorf("proto: Receipt: wiretype end group for non-group")
		}
		if fieldNum <= 0 {
			return fmt.Errorf("proto: Receipt: illegal tag %d (wire type %d)", fieldNum, wire)
		}
		switch fieldNum {
		case 1:
			if wireType != 0 {
				return fmt.Errorf("proto: wrong wireType = %d for field Status", wireType)
			}
			var v int
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowProofResponse
				}
				if iNdEx >= l {
					return io.ErrUnexpectedEOF
				}
				b := dAtA[iNdEx]
				iNdEx++
				v |= int(b&0x7F) << shift
				if b < 0x80 {
					break
				}
			}
			m.Status = bool(v != 0)
		case 2:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field Contractid", wireType)
			}
			var stringLen uint64
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowProofResponse
				}
				if iNdEx >= l {
					return io.ErrUnexpectedEOF
				}
				b := dAtA[iNdEx]
				iNdEx++
				stringLen |= uint64(b&0x7F) << shift
				if b < 0x80 {
					break
				}
			}
			intStringLen := int(stringLen)
			if intStringLen < 0 {
				return ErrInvalidLengthProofResponse
			}
			postIndex := iNdEx + intStringLen
			if postIndex < 0 {
				return ErrInvalidLengthProofResponse
			}
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			m.Contractid = string(dAtA[iNdEx:postIndex])
			iNdEx = postIndex
		case 3:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field BindingHash", wireType)
			}
			var byteLen int
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowProofResponse
				}
				if iNdEx >= l {
					return io.ErrUnexpectedEOF
				}
				b := dAtA[iNdEx]
				iNdEx++
				byteLen |= int(b&0x7F) << shift
				if b < 0x80 {
					break
				}
			}
			if byteLen < 0 {
				return ErrInvalidLengthProofResponse
			}
			postIndex := iNdEx + byteLen
			if postIndex < 0 {
				return ErrInvalidLengthProofResponse
			}
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			m.BindingHash = append(m.BindingHash[:0], dAtA[iNdEx:postIndex]...)
			if m.BindingHash == nil {
				m.BindingHash = []byte{}
			}
			iNdEx = postIndex
		case 4:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field RuleFileHash", wireType)
			}
			var byteLen int
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowProofResponse
				}
				if iNdEx >= l {
					return io.ErrUnexpectedEOF
				}
				b := dAtA[iNdEx]
				iNdEx++
				byteLen |= int(b&0x7F) << shift
				if b < 0x80 {
					break
				}
			}
			if byteLen < 0 {
				return ErrInvalidLengthProofResponse
			}
			postIndex := iNdEx + byteLen
			if postIndex < 0 {
				return ErrInvalidLengthProofResponse
			}
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			m.RuleFileHash = append(m.RuleFileHash, make([]byte, postIndex-iNdEx))
			copy(m.RuleFileHash[len(m.RuleFileHash)-1], dAtA[iNdEx:postIndex])
			iNdEx = postIndex
		case 5:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field ErrorInfo", wireType)
			}
			var msglen int
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowProofResponse
				}
				if iNdEx >= l {
					return io.ErrUnexpectedEOF
				}
				b := dAtA[iNdEx]
				iNdEx++
				msglen |= int(b&0x7F) << shift
				if b < 0x80 {
					break
				}
			}
			if msglen < 0 {
				return ErrInvalidLengthProofResponse
			}
			postIndex := iNdEx + msglen
			if postIndex < 0 {
				return ErrInvalidLengthProofResponse
			}
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			m.ErrorInfo = append(m.ErrorInfo, &ErrorInfo{})
			if err := m.ErrorInfo[len(m.ErrorInfo)-1].Unmarshal(dAtA[iNdEx:postIndex]); err != nil {
				return err
			}
			iNdEx = postIndex
		default:
			iNdEx = preIndex
			skippy, err := skipProofResponse(dAtA[iNdEx:])
			if err != nil {
				return err
			}
			if (skippy < 0) || (iNdEx+skippy) < 0 {
				return ErrInvalidLengthProofResponse
			}
			if (iNdEx + skippy) > l {
				return io.ErrUnexpectedEOF
			}
			iNdEx += skippy
		}
	}

	if iNdEx > l {
		return io.ErrUnexpectedEOF
	}
	return nil
}
func (m *Proof) Unmarshal(dAtA []byte) error {
	l := len(dAtA)
	iNdEx := 0
	for iNdEx < l {
		preIndex := iNdEx
		var wire uint64
		for shift := uint(0); ; shift += 7 {
			if shift >= 64 {
				return ErrIntOverflowProofResponse
			}
			if iNdEx >= l {
				return io.ErrUnexpectedEOF
			}
			b := dAtA[iNdEx]
			iNdEx++
			wire |= uint64(b&0x7F) << shift
			if b < 0x80 {
				break
			}
		}
		fieldNum := int32(wire >> 3)
		wireType := int(wire & 0x7)
		if wireType == 4 {
			return fmt.Errorf("proto: Proof: wiretype end group for non-group")
		}
		if fieldNum <= 0 {
			return fmt.Errorf("proto: Proof: illegal tag %d (wire type %d)", fieldNum, wire)
		}
		switch fieldNum {
		case 1:
			if wireType != 0 {
				return fmt.Errorf("proto: wrong wireType = %d for field Status", wireType)
			}
			var v int
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowProofResponse
				}
				if iNdEx >= l {
					return io.ErrUnexpectedEOF
				}
				b := dAtA[iNdEx]
				iNdEx++
				v |= int(b&0x7F) << shift
				if b < 0x80 {
					break
				}
			}
			m.Status = bool(v != 0)
		case 2:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field RequestHash", wireType)
			}
			var byteLen int
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowProofResponse
				}
				if iNdEx >= l {
					return io.ErrUnexpectedEOF
				}
				b := dAtA[iNdEx]
				iNdEx++
				byteLen |= int(b&0x7F) << shift
				if b < 0x80 {
					break
				}
			}
			if byteLen < 0 {
				return ErrInvalidLengthProofResponse
			}
			postIndex := iNdEx + byteLen
			if postIndex < 0 {
				return ErrInvalidLengthProofResponse
			}
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			m.RequestHash = append(m.RequestHash[:0], dAtA[iNdEx:postIndex]...)
			if m.RequestHash == nil {
				m.RequestHash = []byte{}
			}
			iNdEx = postIndex
		case 3:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field StateHash", wireType)
			}
			var byteLen int
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowProofResponse
				}
				if iNdEx >= l {
					return io.ErrUnexpectedEOF
				}
				b := dAtA[iNdEx]
				iNdEx++
				byteLen |= int(b&0x7F) << shift
				if b < 0x80 {
					break
				}
			}
			if byteLen < 0 {
				return ErrInvalidLengthProofResponse
			}
			postIndex := iNdEx + byteLen
			if postIndex < 0 {
				return ErrInvalidLengthProofResponse
			}
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			m.StateHash = append(m.StateHash[:0], dAtA[iNdEx:postIndex]...)
			if m.StateHash == nil {
				m.StateHash = []byte{}
			}
			iNdEx = postIndex
		case 4:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field Receipts", wireType)
			}
			var msglen int
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowProofResponse
				}
				if iNdEx >= l {
					return io.ErrUnexpectedEOF
				}
				b := dAtA[iNdEx]
				iNdEx++
				msglen |= int(b&0x7F) << shift
				if b < 0x80 {
					break
				}
			}
			if msglen < 0 {
				return ErrInvalidLengthProofResponse
			}
			postIndex := iNdEx + msglen
			if postIndex < 0 {
				return ErrInvalidLengthProofResponse
			}
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			m.Receipts = append(m.Receipts, &Receipt{})
			if err := m.Receipts[len(m.Receipts)-1].Unmarshal(dAtA[iNdEx:postIndex]); err != nil {
				return err
			}
			iNdEx = postIndex
		case 5:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field Signature", wireType)
			}
			var byteLen int
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowProofResponse
				}
				if iNdEx >= l {
					return io.ErrUnexpectedEOF
				}
				b := dAtA[iNdEx]
				iNdEx++
				byteLen |= int(b&0x7F) << shift
				if b < 0x80 {
					break
				}
			}
			if byteLen < 0 {
				return ErrInvalidLengthProofResponse
			}
			postIndex := iNdEx + byteLen
			if postIndex < 0 {
				return ErrInvalidLengthProofResponse
			}
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			m.Signature = append(m.Signature[:0], dAtA[iNdEx:postIndex]...)
			if m.Signature == nil {
				m.Signature = []byte{}
			}
			iNdEx = postIndex
		default:
			iNdEx = preIndex
			skippy, err := skipProofResponse(dAtA[iNdEx:])
			if err != nil {
				return err
			}
			if (skippy < 0) || (iNdEx+skippy) < 0 {
				return ErrInvalidLengthProofResponse
			}
			if (iNdEx + skippy) > l {
				return io.ErrUnexpectedEOF
			}
			iNdEx += skippy
		}
	}

	if iNdEx > l {
		return io.ErrUnexpectedEOF
	}
	return nil
}
func (m *ProofResponse) Unmarshal(dAtA []byte) error {
	l := len(dAtA)
	iNdEx := 0
	for iNdEx < l {
		preIndex := iNdEx
		var wire uint64
		for shift := uint(0); ; shift += 7 {
			if shift >= 64 {
				return ErrIntOverflowProofResponse
			}
			if iNdEx >= l {
				return io.ErrUnexpectedEOF
			}
			b := dAtA[iNdEx]
			iNdEx++
			wire |= uint64(b&0x7F) << shift
			if b < 0x80 {
				break
			}
		}
		fieldNum := int32(wire >> 3)
		wireType := int(wire & 0x7)
		if wireType == 4 {
			return fmt.Errorf("proto: ProofResponse: wiretype end group for non-group")
		}
		if fieldNum <= 0 {
			return fmt.Errorf("proto: ProofResponse: illegal tag %d (wire type %d)", fieldNum, wire)
		}
		switch fieldNum {
		case 1:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field TxHash", wireType)
			}
			var byteLen int
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowProofResponse
				}
				if iNdEx >= l {
					return io.ErrUnexpectedEOF
				}
				b := dAtA[iNdEx]
				iNdEx++
				byteLen |= int(b&0x7F) << shift
				if b < 0x80 {
					break
				}
			}
			if byteLen < 0 {
				return ErrInvalidLengthProofResponse
			}
			postIndex := iNdEx + byteLen
			if postIndex < 0 {
				return ErrInvalidLengthProofResponse
			}
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			m.TxHash = append(m.TxHash[:0], dAtA[iNdEx:postIndex]...)
			if m.TxHash == nil {
				m.TxHash = []byte{}
			}
			iNdEx = postIndex
		case 2:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field ProofsHash", wireType)
			}
			var byteLen int
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowProofResponse
				}
				if iNdEx >= l {
					return io.ErrUnexpectedEOF
				}
				b := dAtA[iNdEx]
				iNdEx++
				byteLen |= int(b&0x7F) << shift
				if b < 0x80 {
					break
				}
			}
			if byteLen < 0 {
				return ErrInvalidLengthProofResponse
			}
			postIndex := iNdEx + byteLen
			if postIndex < 0 {
				return ErrInvalidLengthProofResponse
			}
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			m.ProofsHash = append(m.ProofsHash[:0], dAtA[iNdEx:postIndex]...)
			if m.ProofsHash == nil {
				m.ProofsHash = []byte{}
			}
			iNdEx = postIndex
		case 3:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field Proofs", wireType)
			}
			var msglen int
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowProofResponse
				}
				if iNdEx >= l {
					return io.ErrUnexpectedEOF
				}
				b := dAtA[iNdEx]
				iNdEx++
				msglen |= int(b&0x7F) << shift
				if b < 0x80 {
					break
				}
			}
			if msglen < 0 {
				return ErrInvalidLengthProofResponse
			}
			postIndex := iNdEx + msglen
			if postIndex < 0 {
				return ErrInvalidLengthProofResponse
			}
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			m.Proofs = append(m.Proofs, &Proof{})
			if err := m.Proofs[len(m.Proofs)-1].Unmarshal(dAtA[iNdEx:postIndex]); err != nil {
				return err
			}
			iNdEx = postIndex
		case 4:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field TeeSignature", wireType)
			}
			var byteLen int
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowProofResponse
				}
				if iNdEx >= l {
					return io.ErrUnexpectedEOF
				}
				b := dAtA[iNdEx]
				iNdEx++
				byteLen |= int(b&0x7F) << shift
				if b < 0x80 {
					break
				}
			}
			if byteLen < 0 {
				return ErrInvalidLengthProofResponse
			}
			postIndex := iNdEx + byteLen
			if postIndex < 0 {
				return ErrInvalidLengthProofResponse
			}
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			m.TeeSignature = append(m.TeeSignature[:0], dAtA[iNdEx:postIndex]...)
			if m.TeeSignature == nil {
				m.TeeSignature = []byte{}
			}
			iNdEx = postIndex
		default:
			iNdEx = preIndex
			skippy, err := skipProofResponse(dAtA[iNdEx:])
			if err != nil {
				return err
			}
			if (skippy < 0) || (iNdEx+skippy) < 0 {
				return ErrInvalidLengthProofResponse
			}
			if (iNdEx + skippy) > l {
				return io.ErrUnexpectedEOF
			}
			iNdEx += skippy
		}
	}

	if iNdEx > l {
		return io.ErrUnexpectedEOF
	}
	return nil
}
func skipProofResponse(dAtA []byte) (n int, err error) {
	l := len(dAtA)
	iNdEx := 0
	depth := 0
	for iNdEx < l {
		var wire uint64
		for shift := uint(0); ; shift += 7 {
			if shift >= 64 {
				return 0, ErrIntOverflowProofResponse
			}
			if iNdEx >= l {
				return 0, io.ErrUnexpectedEOF
			}
			b := dAtA[iNdEx]
			iNdEx++
			wire |= (uint64(b) & 0x7F) << shift
			if b < 0x80 {
				break
			}
		}
		wireType := int(wire & 0x7)
		switch wireType {
		case 0:
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return 0, ErrIntOverflowProofResponse
				}
				if iNdEx >= l {
					return 0, io.ErrUnexpectedEOF
				}
				iNdEx++
				if dAtA[iNdEx-1] < 0x80 {
					break
				}
			}
		case 1:
			iNdEx += 8
		case 2:
			var length int
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return 0, ErrIntOverflowProofResponse
				}
				if iNdEx >= l {
					return 0, io.ErrUnexpectedEOF
				}
				b := dAtA[iNdEx]
				iNdEx++
				length |= (int(b) & 0x7F) << shift
				if b < 0x80 {
					break
				}
			}
			if length < 0 {
				return 0, ErrInvalidLengthProofResponse
			}
			iNdEx += length
		case 3:
			depth++
		case 4:
			if depth == 0 {
				return 0, ErrUnexpectedEndOfGroupProofResponse
			}
			depth--
		case 5:
			iNdEx += 4
		default:
			return 0, fmt.Errorf("proto: illegal wireType %d", wireType)
		}
		if iNdEx < 0 {
			return 0, ErrInvalidLengthProofResponse
		}
		if depth == 0 {
			return iNdEx, nil
		}
	}
	return 0, io.ErrUnexpectedEOF
}

var (
	ErrInvalidLengthProofResponse        = fmt.Errorf("proto: negative length found during unmarshaling")
	ErrIntOverflowProofResponse          = fmt.Errorf("proto: integer overflow")
	ErrUnexpectedEndOfGroupProofResponse = fmt.Errorf("proto: unexpected end of group")
)
