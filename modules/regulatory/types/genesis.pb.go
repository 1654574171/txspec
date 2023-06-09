// Code generated by protoc-gen-gogo. DO NOT EDIT.
// source: regulatory/regulatory/genesis.proto

package types

import (
	fmt "fmt"
	_ "github.com/gogo/protobuf/gogoproto"
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

// GenesisState defines the regulatory module's genesis state.
type GenesisState struct {
	Params                    Params                  `protobuf:"bytes,1,opt,name=params,proto3" json:"params"`
	RuleList                  []Rule                  `protobuf:"bytes,2,rep,name=ruleList,proto3" json:"ruleList"`
	BindingList               []Binding               `protobuf:"bytes,3,rep,name=bindingList,proto3" json:"bindingList"`
	RelationList              []Relation              `protobuf:"bytes,4,rep,name=relationList,proto3" json:"relationList"`
	RegistrationList          []Registration          `protobuf:"bytes,5,rep,name=registrationList,proto3" json:"registrationList"`
	SuspiciousAccountListList []SuspiciousAccountList `protobuf:"bytes,6,rep,name=suspiciousAccountListList,proto3" json:"suspiciousAccountListList"`
	SpecValuesList            []SpecValues            `protobuf:"bytes,7,rep,name=specValuesList,proto3" json:"specValuesList"`
	RewardListList            []RewardList            `protobuf:"bytes,8,rep,name=rewardListList,proto3" json:"rewardListList"`
}

func (m *GenesisState) Reset()         { *m = GenesisState{} }
func (m *GenesisState) String() string { return proto.CompactTextString(m) }
func (*GenesisState) ProtoMessage()    {}
func (*GenesisState) Descriptor() ([]byte, []int) {
	return fileDescriptor_0e09aa12e6b500bf, []int{0}
}
func (m *GenesisState) XXX_Unmarshal(b []byte) error {
	return m.Unmarshal(b)
}
func (m *GenesisState) XXX_Marshal(b []byte, deterministic bool) ([]byte, error) {
	if deterministic {
		return xxx_messageInfo_GenesisState.Marshal(b, m, deterministic)
	} else {
		b = b[:cap(b)]
		n, err := m.MarshalToSizedBuffer(b)
		if err != nil {
			return nil, err
		}
		return b[:n], nil
	}
}
func (m *GenesisState) XXX_Merge(src proto.Message) {
	xxx_messageInfo_GenesisState.Merge(m, src)
}
func (m *GenesisState) XXX_Size() int {
	return m.Size()
}
func (m *GenesisState) XXX_DiscardUnknown() {
	xxx_messageInfo_GenesisState.DiscardUnknown(m)
}

var xxx_messageInfo_GenesisState proto.InternalMessageInfo

func (m *GenesisState) GetParams() Params {
	if m != nil {
		return m.Params
	}
	return Params{}
}

func (m *GenesisState) GetRuleList() []Rule {
	if m != nil {
		return m.RuleList
	}
	return nil
}

func (m *GenesisState) GetBindingList() []Binding {
	if m != nil {
		return m.BindingList
	}
	return nil
}

func (m *GenesisState) GetRelationList() []Relation {
	if m != nil {
		return m.RelationList
	}
	return nil
}

func (m *GenesisState) GetRegistrationList() []Registration {
	if m != nil {
		return m.RegistrationList
	}
	return nil
}

func (m *GenesisState) GetSuspiciousAccountListList() []SuspiciousAccountList {
	if m != nil {
		return m.SuspiciousAccountListList
	}
	return nil
}

func (m *GenesisState) GetSpecValuesList() []SpecValues {
	if m != nil {
		return m.SpecValuesList
	}
	return nil
}

func (m *GenesisState) GetRewardListList() []RewardList {
	if m != nil {
		return m.RewardListList
	}
	return nil
}

func init() {
	proto.RegisterType((*GenesisState)(nil), "regulatory.regulatory.GenesisState")
}

func init() {
	proto.RegisterFile("regulatory/regulatory/genesis.proto", fileDescriptor_0e09aa12e6b500bf)
}

var fileDescriptor_0e09aa12e6b500bf = []byte{
	// 421 bytes of a gzipped FileDescriptorProto
	0x1f, 0x8b, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0xff, 0x7c, 0x92, 0x4f, 0x6b, 0xe2, 0x40,
	0x18, 0xc6, 0x93, 0xf5, 0xcf, 0xca, 0x28, 0xcb, 0x32, 0xec, 0x82, 0xeb, 0x62, 0x74, 0x75, 0xa1,
	0x1e, 0x4a, 0x04, 0x3d, 0xf4, 0x50, 0x7a, 0xa8, 0x87, 0x96, 0x42, 0xa1, 0x45, 0x69, 0x0f, 0xbd,
	0xc8, 0x18, 0x87, 0x30, 0x90, 0x66, 0xc2, 0xcc, 0xa4, 0xad, 0xdf, 0xa0, 0xc7, 0x7e, 0x2c, 0x8f,
	0x1e, 0x7b, 0x2a, 0x45, 0xbf, 0x48, 0xc9, 0x64, 0x4c, 0x62, 0x9b, 0xf1, 0x36, 0x30, 0xbf, 0xe7,
	0xf7, 0x0e, 0xf3, 0x3e, 0xa0, 0xcb, 0xb0, 0x1b, 0x7a, 0x48, 0x50, 0xb6, 0xe8, 0x67, 0x8e, 0x2e,
	0xf6, 0x31, 0x27, 0xdc, 0x0e, 0x18, 0x15, 0x14, 0xfe, 0x4e, 0x6f, 0xec, 0xf4, 0xd8, 0xf8, 0xe5,
	0x52, 0x97, 0x4a, 0xa2, 0x1f, 0x9d, 0x62, 0xb8, 0xd1, 0xc9, 0x37, 0x06, 0x88, 0xa1, 0x7b, 0x25,
	0x6c, 0xb4, 0xf3, 0x19, 0x16, 0x7a, 0x58, 0x11, 0x9a, 0x77, 0xcd, 0x88, 0x3f, 0x27, 0xbe, 0xab,
	0xa0, 0xff, 0x1a, 0x0d, 0xf6, 0x90, 0x20, 0xd4, 0x57, 0x54, 0x4f, 0x47, 0xb9, 0x84, 0x0b, 0x96,
	0x25, 0x87, 0xf9, 0x24, 0x0f, 0x79, 0x40, 0x1c, 0x42, 0x43, 0x3e, 0x45, 0x8e, 0x43, 0x43, 0x5f,
	0x4c, 0x3d, 0xc2, 0x85, 0x0a, 0x1d, 0x68, 0x42, 0x01, 0x76, 0xa6, 0x0f, 0xc8, 0x0b, 0x31, 0xdf,
	0x0f, 0x32, 0xfc, 0x88, 0xd8, 0x3c, 0x63, 0xec, 0x3c, 0x97, 0x40, 0xed, 0x3c, 0x5e, 0xc0, 0x44,
	0x20, 0x81, 0xe1, 0x31, 0x28, 0xc7, 0xdf, 0x57, 0x37, 0xdb, 0x66, 0xaf, 0x3a, 0x68, 0xda, 0xb9,
	0x0b, 0xb1, 0xaf, 0x25, 0x34, 0x2a, 0x2e, 0xdf, 0x5a, 0xc6, 0x58, 0x45, 0xe0, 0x09, 0xa8, 0x44,
	0xff, 0x7a, 0x49, 0xb8, 0xa8, 0x7f, 0x6b, 0x17, 0x7a, 0xd5, 0xc1, 0x5f, 0x4d, 0x7c, 0x1c, 0x7a,
	0x58, 0x85, 0x93, 0x08, 0x3c, 0x03, 0x55, 0xf5, 0xe9, 0xd2, 0x50, 0x90, 0x06, 0x4b, 0x63, 0x18,
	0xc5, 0xa4, 0x92, 0x64, 0x83, 0xf0, 0x02, 0xd4, 0xb6, 0x7b, 0x91, 0xa2, 0xa2, 0x14, 0xb5, 0x74,
	0x4f, 0x51, 0xa8, 0x32, 0xed, 0x44, 0xe1, 0x0d, 0xf8, 0x99, 0x5d, 0x9e, 0xd4, 0x95, 0xa4, 0xae,
	0xab, 0xd5, 0xa5, 0xb8, 0x52, 0x7e, 0x51, 0xc0, 0x00, 0xfc, 0x49, 0x37, 0x7d, 0x1a, 0x2f, 0x3a,
	0xba, 0x90, 0xfe, 0xb2, 0xf4, 0x1f, 0x6a, 0xfc, 0x93, 0xbc, 0x9c, 0x1a, 0xa4, 0x97, 0xc2, 0x2b,
	0xf0, 0x23, 0xaa, 0xc9, 0xad, 0x6c, 0x89, 0x1c, 0xf3, 0x5d, 0x8e, 0xf9, 0xa7, 0x1b, 0x93, 0xc0,
	0xca, 0xfd, 0x29, 0x1e, 0x09, 0xe3, 0x3a, 0x25, 0xef, 0xae, 0xec, 0x15, 0x8e, 0x13, 0x78, 0x2b,
	0xdc, 0x8d, 0x8f, 0x8e, 0x96, 0x6b, 0xcb, 0x5c, 0xad, 0x2d, 0xf3, 0x7d, 0x6d, 0x99, 0x2f, 0x1b,
	0xcb, 0x58, 0x6d, 0x2c, 0xe3, 0x75, 0x63, 0x19, 0x77, 0xcd, 0x4c, 0x85, 0x9f, 0xb2, 0x7d, 0x16,
	0x8b, 0x00, 0xf3, 0x59, 0x59, 0x56, 0x79, 0xf8, 0x11, 0x00, 0x00, 0xff, 0xff, 0xaf, 0x21, 0x72,
	0xf3, 0x60, 0x04, 0x00, 0x00,
}

func (m *GenesisState) Marshal() (dAtA []byte, err error) {
	size := m.Size()
	dAtA = make([]byte, size)
	n, err := m.MarshalToSizedBuffer(dAtA[:size])
	if err != nil {
		return nil, err
	}
	return dAtA[:n], nil
}

func (m *GenesisState) MarshalTo(dAtA []byte) (int, error) {
	size := m.Size()
	return m.MarshalToSizedBuffer(dAtA[:size])
}

func (m *GenesisState) MarshalToSizedBuffer(dAtA []byte) (int, error) {
	i := len(dAtA)
	_ = i
	var l int
	_ = l
	if len(m.RewardListList) > 0 {
		for iNdEx := len(m.RewardListList) - 1; iNdEx >= 0; iNdEx-- {
			{
				size, err := m.RewardListList[iNdEx].MarshalToSizedBuffer(dAtA[:i])
				if err != nil {
					return 0, err
				}
				i -= size
				i = encodeVarintGenesis(dAtA, i, uint64(size))
			}
			i--
			dAtA[i] = 0x42
		}
	}
	if len(m.SpecValuesList) > 0 {
		for iNdEx := len(m.SpecValuesList) - 1; iNdEx >= 0; iNdEx-- {
			{
				size, err := m.SpecValuesList[iNdEx].MarshalToSizedBuffer(dAtA[:i])
				if err != nil {
					return 0, err
				}
				i -= size
				i = encodeVarintGenesis(dAtA, i, uint64(size))
			}
			i--
			dAtA[i] = 0x3a
		}
	}
	if len(m.SuspiciousAccountListList) > 0 {
		for iNdEx := len(m.SuspiciousAccountListList) - 1; iNdEx >= 0; iNdEx-- {
			{
				size, err := m.SuspiciousAccountListList[iNdEx].MarshalToSizedBuffer(dAtA[:i])
				if err != nil {
					return 0, err
				}
				i -= size
				i = encodeVarintGenesis(dAtA, i, uint64(size))
			}
			i--
			dAtA[i] = 0x32
		}
	}
	if len(m.RegistrationList) > 0 {
		for iNdEx := len(m.RegistrationList) - 1; iNdEx >= 0; iNdEx-- {
			{
				size, err := m.RegistrationList[iNdEx].MarshalToSizedBuffer(dAtA[:i])
				if err != nil {
					return 0, err
				}
				i -= size
				i = encodeVarintGenesis(dAtA, i, uint64(size))
			}
			i--
			dAtA[i] = 0x2a
		}
	}
	if len(m.RelationList) > 0 {
		for iNdEx := len(m.RelationList) - 1; iNdEx >= 0; iNdEx-- {
			{
				size, err := m.RelationList[iNdEx].MarshalToSizedBuffer(dAtA[:i])
				if err != nil {
					return 0, err
				}
				i -= size
				i = encodeVarintGenesis(dAtA, i, uint64(size))
			}
			i--
			dAtA[i] = 0x22
		}
	}
	if len(m.BindingList) > 0 {
		for iNdEx := len(m.BindingList) - 1; iNdEx >= 0; iNdEx-- {
			{
				size, err := m.BindingList[iNdEx].MarshalToSizedBuffer(dAtA[:i])
				if err != nil {
					return 0, err
				}
				i -= size
				i = encodeVarintGenesis(dAtA, i, uint64(size))
			}
			i--
			dAtA[i] = 0x1a
		}
	}
	if len(m.RuleList) > 0 {
		for iNdEx := len(m.RuleList) - 1; iNdEx >= 0; iNdEx-- {
			{
				size, err := m.RuleList[iNdEx].MarshalToSizedBuffer(dAtA[:i])
				if err != nil {
					return 0, err
				}
				i -= size
				i = encodeVarintGenesis(dAtA, i, uint64(size))
			}
			i--
			dAtA[i] = 0x12
		}
	}
	{
		size, err := m.Params.MarshalToSizedBuffer(dAtA[:i])
		if err != nil {
			return 0, err
		}
		i -= size
		i = encodeVarintGenesis(dAtA, i, uint64(size))
	}
	i--
	dAtA[i] = 0xa
	return len(dAtA) - i, nil
}

func encodeVarintGenesis(dAtA []byte, offset int, v uint64) int {
	offset -= sovGenesis(v)
	base := offset
	for v >= 1<<7 {
		dAtA[offset] = uint8(v&0x7f | 0x80)
		v >>= 7
		offset++
	}
	dAtA[offset] = uint8(v)
	return base
}
func (m *GenesisState) Size() (n int) {
	if m == nil {
		return 0
	}
	var l int
	_ = l
	l = m.Params.Size()
	n += 1 + l + sovGenesis(uint64(l))
	if len(m.RuleList) > 0 {
		for _, e := range m.RuleList {
			l = e.Size()
			n += 1 + l + sovGenesis(uint64(l))
		}
	}
	if len(m.BindingList) > 0 {
		for _, e := range m.BindingList {
			l = e.Size()
			n += 1 + l + sovGenesis(uint64(l))
		}
	}
	if len(m.RelationList) > 0 {
		for _, e := range m.RelationList {
			l = e.Size()
			n += 1 + l + sovGenesis(uint64(l))
		}
	}
	if len(m.RegistrationList) > 0 {
		for _, e := range m.RegistrationList {
			l = e.Size()
			n += 1 + l + sovGenesis(uint64(l))
		}
	}
	if len(m.SuspiciousAccountListList) > 0 {
		for _, e := range m.SuspiciousAccountListList {
			l = e.Size()
			n += 1 + l + sovGenesis(uint64(l))
		}
	}
	if len(m.SpecValuesList) > 0 {
		for _, e := range m.SpecValuesList {
			l = e.Size()
			n += 1 + l + sovGenesis(uint64(l))
		}
	}
	if len(m.RewardListList) > 0 {
		for _, e := range m.RewardListList {
			l = e.Size()
			n += 1 + l + sovGenesis(uint64(l))
		}
	}
	return n
}

func sovGenesis(x uint64) (n int) {
	return (math_bits.Len64(x|1) + 6) / 7
}
func sozGenesis(x uint64) (n int) {
	return sovGenesis(uint64((x << 1) ^ uint64((int64(x) >> 63))))
}
func (m *GenesisState) Unmarshal(dAtA []byte) error {
	l := len(dAtA)
	iNdEx := 0
	for iNdEx < l {
		preIndex := iNdEx
		var wire uint64
		for shift := uint(0); ; shift += 7 {
			if shift >= 64 {
				return ErrIntOverflowGenesis
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
			return fmt.Errorf("proto: GenesisState: wiretype end group for non-group")
		}
		if fieldNum <= 0 {
			return fmt.Errorf("proto: GenesisState: illegal tag %d (wire type %d)", fieldNum, wire)
		}
		switch fieldNum {
		case 1:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field Params", wireType)
			}
			var msglen int
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowGenesis
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
				return ErrInvalidLengthGenesis
			}
			postIndex := iNdEx + msglen
			if postIndex < 0 {
				return ErrInvalidLengthGenesis
			}
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			if err := m.Params.Unmarshal(dAtA[iNdEx:postIndex]); err != nil {
				return err
			}
			iNdEx = postIndex
		case 2:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field RuleList", wireType)
			}
			var msglen int
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowGenesis
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
				return ErrInvalidLengthGenesis
			}
			postIndex := iNdEx + msglen
			if postIndex < 0 {
				return ErrInvalidLengthGenesis
			}
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			m.RuleList = append(m.RuleList, Rule{})
			if err := m.RuleList[len(m.RuleList)-1].Unmarshal(dAtA[iNdEx:postIndex]); err != nil {
				return err
			}
			iNdEx = postIndex
		case 3:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field BindingList", wireType)
			}
			var msglen int
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowGenesis
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
				return ErrInvalidLengthGenesis
			}
			postIndex := iNdEx + msglen
			if postIndex < 0 {
				return ErrInvalidLengthGenesis
			}
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			m.BindingList = append(m.BindingList, Binding{})
			if err := m.BindingList[len(m.BindingList)-1].Unmarshal(dAtA[iNdEx:postIndex]); err != nil {
				return err
			}
			iNdEx = postIndex
		case 4:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field RelationList", wireType)
			}
			var msglen int
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowGenesis
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
				return ErrInvalidLengthGenesis
			}
			postIndex := iNdEx + msglen
			if postIndex < 0 {
				return ErrInvalidLengthGenesis
			}
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			m.RelationList = append(m.RelationList, Relation{})
			if err := m.RelationList[len(m.RelationList)-1].Unmarshal(dAtA[iNdEx:postIndex]); err != nil {
				return err
			}
			iNdEx = postIndex
		case 5:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field RegistrationList", wireType)
			}
			var msglen int
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowGenesis
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
				return ErrInvalidLengthGenesis
			}
			postIndex := iNdEx + msglen
			if postIndex < 0 {
				return ErrInvalidLengthGenesis
			}
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			m.RegistrationList = append(m.RegistrationList, Registration{})
			if err := m.RegistrationList[len(m.RegistrationList)-1].Unmarshal(dAtA[iNdEx:postIndex]); err != nil {
				return err
			}
			iNdEx = postIndex
		case 6:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field SuspiciousAccountListList", wireType)
			}
			var msglen int
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowGenesis
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
				return ErrInvalidLengthGenesis
			}
			postIndex := iNdEx + msglen
			if postIndex < 0 {
				return ErrInvalidLengthGenesis
			}
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			m.SuspiciousAccountListList = append(m.SuspiciousAccountListList, SuspiciousAccountList{})
			if err := m.SuspiciousAccountListList[len(m.SuspiciousAccountListList)-1].Unmarshal(dAtA[iNdEx:postIndex]); err != nil {
				return err
			}
			iNdEx = postIndex
		case 7:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field SpecValuesList", wireType)
			}
			var msglen int
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowGenesis
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
				return ErrInvalidLengthGenesis
			}
			postIndex := iNdEx + msglen
			if postIndex < 0 {
				return ErrInvalidLengthGenesis
			}
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			m.SpecValuesList = append(m.SpecValuesList, SpecValues{})
			if err := m.SpecValuesList[len(m.SpecValuesList)-1].Unmarshal(dAtA[iNdEx:postIndex]); err != nil {
				return err
			}
			iNdEx = postIndex
		case 8:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field RewardListList", wireType)
			}
			var msglen int
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowGenesis
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
				return ErrInvalidLengthGenesis
			}
			postIndex := iNdEx + msglen
			if postIndex < 0 {
				return ErrInvalidLengthGenesis
			}
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			m.RewardListList = append(m.RewardListList, RewardList{})
			if err := m.RewardListList[len(m.RewardListList)-1].Unmarshal(dAtA[iNdEx:postIndex]); err != nil {
				return err
			}
			iNdEx = postIndex
		default:
			iNdEx = preIndex
			skippy, err := skipGenesis(dAtA[iNdEx:])
			if err != nil {
				return err
			}
			if (skippy < 0) || (iNdEx+skippy) < 0 {
				return ErrInvalidLengthGenesis
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
func skipGenesis(dAtA []byte) (n int, err error) {
	l := len(dAtA)
	iNdEx := 0
	depth := 0
	for iNdEx < l {
		var wire uint64
		for shift := uint(0); ; shift += 7 {
			if shift >= 64 {
				return 0, ErrIntOverflowGenesis
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
					return 0, ErrIntOverflowGenesis
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
					return 0, ErrIntOverflowGenesis
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
				return 0, ErrInvalidLengthGenesis
			}
			iNdEx += length
		case 3:
			depth++
		case 4:
			if depth == 0 {
				return 0, ErrUnexpectedEndOfGroupGenesis
			}
			depth--
		case 5:
			iNdEx += 4
		default:
			return 0, fmt.Errorf("proto: illegal wireType %d", wireType)
		}
		if iNdEx < 0 {
			return 0, ErrInvalidLengthGenesis
		}
		if depth == 0 {
			return iNdEx, nil
		}
	}
	return 0, io.ErrUnexpectedEOF
}

var (
	ErrInvalidLengthGenesis        = fmt.Errorf("proto: negative length found during unmarshaling")
	ErrIntOverflowGenesis          = fmt.Errorf("proto: integer overflow")
	ErrUnexpectedEndOfGroupGenesis = fmt.Errorf("proto: unexpected end of group")
)
