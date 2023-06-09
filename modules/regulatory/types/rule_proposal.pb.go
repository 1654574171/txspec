// Code generated by protoc-gen-gogo. DO NOT EDIT.
// source: regulatory/regulatory/rule_proposal.proto

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

type RuleProposal struct {
	Title         string `protobuf:"bytes,1,opt,name=title,proto3" json:"title,omitempty"`
	Description   string `protobuf:"bytes,2,opt,name=description,proto3" json:"description,omitempty"`
	Rule          *Rule  `protobuf:"bytes,3,opt,name=rule,proto3" json:"rule,omitempty"`
	OperationType string `protobuf:"bytes,4,opt,name=operationType,proto3" json:"operationType,omitempty"`
}

func (m *RuleProposal) Reset()         { *m = RuleProposal{} }
func (m *RuleProposal) String() string { return proto.CompactTextString(m) }
func (*RuleProposal) ProtoMessage()    {}
func (*RuleProposal) Descriptor() ([]byte, []int) {
	return fileDescriptor_7ca3fb20b4101167, []int{0}
}
func (m *RuleProposal) XXX_Unmarshal(b []byte) error {
	return m.Unmarshal(b)
}
func (m *RuleProposal) XXX_Marshal(b []byte, deterministic bool) ([]byte, error) {
	if deterministic {
		return xxx_messageInfo_RuleProposal.Marshal(b, m, deterministic)
	} else {
		b = b[:cap(b)]
		n, err := m.MarshalToSizedBuffer(b)
		if err != nil {
			return nil, err
		}
		return b[:n], nil
	}
}
func (m *RuleProposal) XXX_Merge(src proto.Message) {
	xxx_messageInfo_RuleProposal.Merge(m, src)
}
func (m *RuleProposal) XXX_Size() int {
	return m.Size()
}
func (m *RuleProposal) XXX_DiscardUnknown() {
	xxx_messageInfo_RuleProposal.DiscardUnknown(m)
}

var xxx_messageInfo_RuleProposal proto.InternalMessageInfo

func (m *RuleProposal) GetTitle() string {
	if m != nil {
		return m.Title
	}
	return ""
}

func (m *RuleProposal) GetDescription() string {
	if m != nil {
		return m.Description
	}
	return ""
}

func (m *RuleProposal) GetRule() *Rule {
	if m != nil {
		return m.Rule
	}
	return nil
}

func (m *RuleProposal) GetOperationType() string {
	if m != nil {
		return m.OperationType
	}
	return ""
}

func init() {
	proto.RegisterType((*RuleProposal)(nil), "regulatory.regulatory.RuleProposal")
}

func init() {
	proto.RegisterFile("regulatory/regulatory/rule_proposal.proto", fileDescriptor_7ca3fb20b4101167)
}

var fileDescriptor_7ca3fb20b4101167 = []byte{
	// 211 bytes of a gzipped FileDescriptorProto
	0x1f, 0x8b, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0xff, 0xe2, 0xd2, 0x2c, 0x4a, 0x4d, 0x2f,
	0xcd, 0x49, 0x2c, 0xc9, 0x2f, 0xaa, 0xd4, 0x47, 0x66, 0x96, 0xe6, 0xa4, 0xc6, 0x17, 0x14, 0xe5,
	0x17, 0xe4, 0x17, 0x27, 0xe6, 0xe8, 0x15, 0x14, 0xe5, 0x97, 0xe4, 0x0b, 0x89, 0x22, 0xe4, 0xf5,
	0x10, 0x4c, 0x29, 0x05, 0xdc, 0x26, 0x40, 0x34, 0x2a, 0xcd, 0x65, 0xe4, 0xe2, 0x09, 0x2a, 0xcd,
	0x49, 0x0d, 0x80, 0x9a, 0x27, 0x24, 0xc2, 0xc5, 0x5a, 0x92, 0x59, 0x92, 0x93, 0x2a, 0xc1, 0xa8,
	0xc0, 0xa8, 0xc1, 0x19, 0x04, 0xe1, 0x08, 0x29, 0x70, 0x71, 0xa7, 0xa4, 0x16, 0x27, 0x17, 0x65,
	0x16, 0x94, 0x64, 0xe6, 0xe7, 0x49, 0x30, 0x81, 0xe5, 0x90, 0x85, 0x84, 0xf4, 0xb9, 0x58, 0x40,
	0xc6, 0x4a, 0x30, 0x2b, 0x30, 0x6a, 0x70, 0x1b, 0x49, 0xeb, 0x61, 0x75, 0x90, 0x1e, 0xc8, 0xaa,
	0x20, 0xb0, 0x42, 0x21, 0x15, 0x2e, 0xde, 0xfc, 0x82, 0xd4, 0xa2, 0x44, 0x90, 0xee, 0x90, 0xca,
	0x82, 0x54, 0x09, 0x16, 0xb0, 0xa1, 0xa8, 0x82, 0x4e, 0xe6, 0x27, 0x1e, 0xc9, 0x31, 0x5e, 0x78,
	0x24, 0xc7, 0xf8, 0xe0, 0x91, 0x1c, 0xe3, 0x84, 0xc7, 0x72, 0x0c, 0x17, 0x1e, 0xcb, 0x31, 0xdc,
	0x78, 0x2c, 0xc7, 0x10, 0x25, 0x8b, 0xe4, 0xa1, 0x0a, 0x64, 0xdf, 0x95, 0x54, 0x16, 0xa4, 0x16,
	0x27, 0xb1, 0x81, 0xfd, 0x67, 0x0c, 0x08, 0x00, 0x00, 0xff, 0xff, 0x91, 0x37, 0x3a, 0x22, 0x45,
	0x01, 0x00, 0x00,
}

func (m *RuleProposal) Marshal() (dAtA []byte, err error) {
	size := m.Size()
	dAtA = make([]byte, size)
	n, err := m.MarshalToSizedBuffer(dAtA[:size])
	if err != nil {
		return nil, err
	}
	return dAtA[:n], nil
}

func (m *RuleProposal) MarshalTo(dAtA []byte) (int, error) {
	size := m.Size()
	return m.MarshalToSizedBuffer(dAtA[:size])
}

func (m *RuleProposal) MarshalToSizedBuffer(dAtA []byte) (int, error) {
	i := len(dAtA)
	_ = i
	var l int
	_ = l
	if len(m.OperationType) > 0 {
		i -= len(m.OperationType)
		copy(dAtA[i:], m.OperationType)
		i = encodeVarintRuleProposal(dAtA, i, uint64(len(m.OperationType)))
		i--
		dAtA[i] = 0x22
	}
	if m.Rule != nil {
		{
			size, err := m.Rule.MarshalToSizedBuffer(dAtA[:i])
			if err != nil {
				return 0, err
			}
			i -= size
			i = encodeVarintRuleProposal(dAtA, i, uint64(size))
		}
		i--
		dAtA[i] = 0x1a
	}
	if len(m.Description) > 0 {
		i -= len(m.Description)
		copy(dAtA[i:], m.Description)
		i = encodeVarintRuleProposal(dAtA, i, uint64(len(m.Description)))
		i--
		dAtA[i] = 0x12
	}
	if len(m.Title) > 0 {
		i -= len(m.Title)
		copy(dAtA[i:], m.Title)
		i = encodeVarintRuleProposal(dAtA, i, uint64(len(m.Title)))
		i--
		dAtA[i] = 0xa
	}
	return len(dAtA) - i, nil
}

func encodeVarintRuleProposal(dAtA []byte, offset int, v uint64) int {
	offset -= sovRuleProposal(v)
	base := offset
	for v >= 1<<7 {
		dAtA[offset] = uint8(v&0x7f | 0x80)
		v >>= 7
		offset++
	}
	dAtA[offset] = uint8(v)
	return base
}
func (m *RuleProposal) Size() (n int) {
	if m == nil {
		return 0
	}
	var l int
	_ = l
	l = len(m.Title)
	if l > 0 {
		n += 1 + l + sovRuleProposal(uint64(l))
	}
	l = len(m.Description)
	if l > 0 {
		n += 1 + l + sovRuleProposal(uint64(l))
	}
	if m.Rule != nil {
		l = m.Rule.Size()
		n += 1 + l + sovRuleProposal(uint64(l))
	}
	l = len(m.OperationType)
	if l > 0 {
		n += 1 + l + sovRuleProposal(uint64(l))
	}
	return n
}

func sovRuleProposal(x uint64) (n int) {
	return (math_bits.Len64(x|1) + 6) / 7
}
func sozRuleProposal(x uint64) (n int) {
	return sovRuleProposal(uint64((x << 1) ^ uint64((int64(x) >> 63))))
}
func (m *RuleProposal) Unmarshal(dAtA []byte) error {
	l := len(dAtA)
	iNdEx := 0
	for iNdEx < l {
		preIndex := iNdEx
		var wire uint64
		for shift := uint(0); ; shift += 7 {
			if shift >= 64 {
				return ErrIntOverflowRuleProposal
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
			return fmt.Errorf("proto: RuleProposal: wiretype end group for non-group")
		}
		if fieldNum <= 0 {
			return fmt.Errorf("proto: RuleProposal: illegal tag %d (wire type %d)", fieldNum, wire)
		}
		switch fieldNum {
		case 1:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field Title", wireType)
			}
			var stringLen uint64
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowRuleProposal
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
				return ErrInvalidLengthRuleProposal
			}
			postIndex := iNdEx + intStringLen
			if postIndex < 0 {
				return ErrInvalidLengthRuleProposal
			}
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			m.Title = string(dAtA[iNdEx:postIndex])
			iNdEx = postIndex
		case 2:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field Description", wireType)
			}
			var stringLen uint64
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowRuleProposal
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
				return ErrInvalidLengthRuleProposal
			}
			postIndex := iNdEx + intStringLen
			if postIndex < 0 {
				return ErrInvalidLengthRuleProposal
			}
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			m.Description = string(dAtA[iNdEx:postIndex])
			iNdEx = postIndex
		case 3:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field Rule", wireType)
			}
			var msglen int
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowRuleProposal
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
				return ErrInvalidLengthRuleProposal
			}
			postIndex := iNdEx + msglen
			if postIndex < 0 {
				return ErrInvalidLengthRuleProposal
			}
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			if m.Rule == nil {
				m.Rule = &Rule{}
			}
			if err := m.Rule.Unmarshal(dAtA[iNdEx:postIndex]); err != nil {
				return err
			}
			iNdEx = postIndex
		case 4:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field OperationType", wireType)
			}
			var stringLen uint64
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowRuleProposal
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
				return ErrInvalidLengthRuleProposal
			}
			postIndex := iNdEx + intStringLen
			if postIndex < 0 {
				return ErrInvalidLengthRuleProposal
			}
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			m.OperationType = string(dAtA[iNdEx:postIndex])
			iNdEx = postIndex
		default:
			iNdEx = preIndex
			skippy, err := skipRuleProposal(dAtA[iNdEx:])
			if err != nil {
				return err
			}
			if (skippy < 0) || (iNdEx+skippy) < 0 {
				return ErrInvalidLengthRuleProposal
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
func skipRuleProposal(dAtA []byte) (n int, err error) {
	l := len(dAtA)
	iNdEx := 0
	depth := 0
	for iNdEx < l {
		var wire uint64
		for shift := uint(0); ; shift += 7 {
			if shift >= 64 {
				return 0, ErrIntOverflowRuleProposal
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
					return 0, ErrIntOverflowRuleProposal
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
					return 0, ErrIntOverflowRuleProposal
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
				return 0, ErrInvalidLengthRuleProposal
			}
			iNdEx += length
		case 3:
			depth++
		case 4:
			if depth == 0 {
				return 0, ErrUnexpectedEndOfGroupRuleProposal
			}
			depth--
		case 5:
			iNdEx += 4
		default:
			return 0, fmt.Errorf("proto: illegal wireType %d", wireType)
		}
		if iNdEx < 0 {
			return 0, ErrInvalidLengthRuleProposal
		}
		if depth == 0 {
			return iNdEx, nil
		}
	}
	return 0, io.ErrUnexpectedEOF
}

var (
	ErrInvalidLengthRuleProposal        = fmt.Errorf("proto: negative length found during unmarshaling")
	ErrIntOverflowRuleProposal          = fmt.Errorf("proto: integer overflow")
	ErrUnexpectedEndOfGroupRuleProposal = fmt.Errorf("proto: unexpected end of group")
)
