// Code generated by protoc-gen-gogo. DO NOT EDIT.
// source: regulatory/regulatory/suspicious_account_list.proto

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

type SuspiciousAccountList struct {
	ContractAddress string   `protobuf:"bytes,1,opt,name=contractAddress,proto3" json:"contractAddress,omitempty"`
	Account         []string `protobuf:"bytes,2,rep,name=account,proto3" json:"account,omitempty"`
}

func (m *SuspiciousAccountList) Reset()         { *m = SuspiciousAccountList{} }
func (m *SuspiciousAccountList) String() string { return proto.CompactTextString(m) }
func (*SuspiciousAccountList) ProtoMessage()    {}
func (*SuspiciousAccountList) Descriptor() ([]byte, []int) {
	return fileDescriptor_62507433fd95e1ef, []int{0}
}
func (m *SuspiciousAccountList) XXX_Unmarshal(b []byte) error {
	return m.Unmarshal(b)
}
func (m *SuspiciousAccountList) XXX_Marshal(b []byte, deterministic bool) ([]byte, error) {
	if deterministic {
		return xxx_messageInfo_SuspiciousAccountList.Marshal(b, m, deterministic)
	} else {
		b = b[:cap(b)]
		n, err := m.MarshalToSizedBuffer(b)
		if err != nil {
			return nil, err
		}
		return b[:n], nil
	}
}
func (m *SuspiciousAccountList) XXX_Merge(src proto.Message) {
	xxx_messageInfo_SuspiciousAccountList.Merge(m, src)
}
func (m *SuspiciousAccountList) XXX_Size() int {
	return m.Size()
}
func (m *SuspiciousAccountList) XXX_DiscardUnknown() {
	xxx_messageInfo_SuspiciousAccountList.DiscardUnknown(m)
}

var xxx_messageInfo_SuspiciousAccountList proto.InternalMessageInfo

func (m *SuspiciousAccountList) GetContractAddress() string {
	if m != nil {
		return m.ContractAddress
	}
	return ""
}

func (m *SuspiciousAccountList) GetAccount() []string {
	if m != nil {
		return m.Account
	}
	return nil
}

func init() {
	proto.RegisterType((*SuspiciousAccountList)(nil), "regulatory.regulatory.SuspiciousAccountList")
}

func init() {
	proto.RegisterFile("regulatory/regulatory/suspicious_account_list.proto", fileDescriptor_62507433fd95e1ef)
}

var fileDescriptor_62507433fd95e1ef = []byte{
	// 177 bytes of a gzipped FileDescriptorProto
	0x1f, 0x8b, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0xff, 0xe2, 0x32, 0x2e, 0x4a, 0x4d, 0x2f,
	0xcd, 0x49, 0x2c, 0xc9, 0x2f, 0xaa, 0xd4, 0x47, 0x62, 0x16, 0x97, 0x16, 0x17, 0x64, 0x26, 0x67,
	0xe6, 0x97, 0x16, 0xc7, 0x27, 0x26, 0x27, 0xe7, 0x97, 0xe6, 0x95, 0xc4, 0xe7, 0x64, 0x16, 0x97,
	0xe8, 0x15, 0x14, 0xe5, 0x97, 0xe4, 0x0b, 0x89, 0x22, 0x54, 0xea, 0x21, 0x98, 0x4a, 0xd1, 0x5c,
	0xa2, 0xc1, 0x70, 0x7d, 0x8e, 0x10, 0x6d, 0x3e, 0x99, 0xc5, 0x25, 0x42, 0x1a, 0x5c, 0xfc, 0xc9,
	0xf9, 0x79, 0x25, 0x45, 0x89, 0xc9, 0x25, 0x8e, 0x29, 0x29, 0x45, 0xa9, 0xc5, 0xc5, 0x12, 0x8c,
	0x0a, 0x8c, 0x1a, 0x9c, 0x41, 0xe8, 0xc2, 0x42, 0x12, 0x5c, 0xec, 0x50, 0xfb, 0x24, 0x98, 0x14,
	0x98, 0x35, 0x38, 0x83, 0x60, 0x5c, 0x27, 0xf3, 0x13, 0x8f, 0xe4, 0x18, 0x2f, 0x3c, 0x92, 0x63,
	0x7c, 0xf0, 0x48, 0x8e, 0x71, 0xc2, 0x63, 0x39, 0x86, 0x0b, 0x8f, 0xe5, 0x18, 0x6e, 0x3c, 0x96,
	0x63, 0x88, 0x92, 0x45, 0x72, 0x77, 0x05, 0xb2, 0x27, 0x4a, 0x2a, 0x0b, 0x52, 0x8b, 0x93, 0xd8,
	0xc0, 0x6e, 0x36, 0x06, 0x04, 0x00, 0x00, 0xff, 0xff, 0x94, 0xf6, 0x0f, 0xf8, 0xea, 0x00, 0x00,
	0x00,
}

func (m *SuspiciousAccountList) Marshal() (dAtA []byte, err error) {
	size := m.Size()
	dAtA = make([]byte, size)
	n, err := m.MarshalToSizedBuffer(dAtA[:size])
	if err != nil {
		return nil, err
	}
	return dAtA[:n], nil
}

func (m *SuspiciousAccountList) MarshalTo(dAtA []byte) (int, error) {
	size := m.Size()
	return m.MarshalToSizedBuffer(dAtA[:size])
}

func (m *SuspiciousAccountList) MarshalToSizedBuffer(dAtA []byte) (int, error) {
	i := len(dAtA)
	_ = i
	var l int
	_ = l
	if len(m.Account) > 0 {
		for iNdEx := len(m.Account) - 1; iNdEx >= 0; iNdEx-- {
			i -= len(m.Account[iNdEx])
			copy(dAtA[i:], m.Account[iNdEx])
			i = encodeVarintSuspiciousAccountList(dAtA, i, uint64(len(m.Account[iNdEx])))
			i--
			dAtA[i] = 0x12
		}
	}
	if len(m.ContractAddress) > 0 {
		i -= len(m.ContractAddress)
		copy(dAtA[i:], m.ContractAddress)
		i = encodeVarintSuspiciousAccountList(dAtA, i, uint64(len(m.ContractAddress)))
		i--
		dAtA[i] = 0xa
	}
	return len(dAtA) - i, nil
}

func encodeVarintSuspiciousAccountList(dAtA []byte, offset int, v uint64) int {
	offset -= sovSuspiciousAccountList(v)
	base := offset
	for v >= 1<<7 {
		dAtA[offset] = uint8(v&0x7f | 0x80)
		v >>= 7
		offset++
	}
	dAtA[offset] = uint8(v)
	return base
}
func (m *SuspiciousAccountList) Size() (n int) {
	if m == nil {
		return 0
	}
	var l int
	_ = l
	l = len(m.ContractAddress)
	if l > 0 {
		n += 1 + l + sovSuspiciousAccountList(uint64(l))
	}
	if len(m.Account) > 0 {
		for _, s := range m.Account {
			l = len(s)
			n += 1 + l + sovSuspiciousAccountList(uint64(l))
		}
	}
	return n
}

func sovSuspiciousAccountList(x uint64) (n int) {
	return (math_bits.Len64(x|1) + 6) / 7
}
func sozSuspiciousAccountList(x uint64) (n int) {
	return sovSuspiciousAccountList(uint64((x << 1) ^ uint64((int64(x) >> 63))))
}
func (m *SuspiciousAccountList) Unmarshal(dAtA []byte) error {
	l := len(dAtA)
	iNdEx := 0
	for iNdEx < l {
		preIndex := iNdEx
		var wire uint64
		for shift := uint(0); ; shift += 7 {
			if shift >= 64 {
				return ErrIntOverflowSuspiciousAccountList
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
			return fmt.Errorf("proto: SuspiciousAccountList: wiretype end group for non-group")
		}
		if fieldNum <= 0 {
			return fmt.Errorf("proto: SuspiciousAccountList: illegal tag %d (wire type %d)", fieldNum, wire)
		}
		switch fieldNum {
		case 1:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field ContractAddress", wireType)
			}
			var stringLen uint64
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowSuspiciousAccountList
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
				return ErrInvalidLengthSuspiciousAccountList
			}
			postIndex := iNdEx + intStringLen
			if postIndex < 0 {
				return ErrInvalidLengthSuspiciousAccountList
			}
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			m.ContractAddress = string(dAtA[iNdEx:postIndex])
			iNdEx = postIndex
		case 2:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field Account", wireType)
			}
			var stringLen uint64
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowSuspiciousAccountList
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
				return ErrInvalidLengthSuspiciousAccountList
			}
			postIndex := iNdEx + intStringLen
			if postIndex < 0 {
				return ErrInvalidLengthSuspiciousAccountList
			}
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			m.Account = append(m.Account, string(dAtA[iNdEx:postIndex]))
			iNdEx = postIndex
		default:
			iNdEx = preIndex
			skippy, err := skipSuspiciousAccountList(dAtA[iNdEx:])
			if err != nil {
				return err
			}
			if (skippy < 0) || (iNdEx+skippy) < 0 {
				return ErrInvalidLengthSuspiciousAccountList
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
func skipSuspiciousAccountList(dAtA []byte) (n int, err error) {
	l := len(dAtA)
	iNdEx := 0
	depth := 0
	for iNdEx < l {
		var wire uint64
		for shift := uint(0); ; shift += 7 {
			if shift >= 64 {
				return 0, ErrIntOverflowSuspiciousAccountList
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
					return 0, ErrIntOverflowSuspiciousAccountList
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
					return 0, ErrIntOverflowSuspiciousAccountList
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
				return 0, ErrInvalidLengthSuspiciousAccountList
			}
			iNdEx += length
		case 3:
			depth++
		case 4:
			if depth == 0 {
				return 0, ErrUnexpectedEndOfGroupSuspiciousAccountList
			}
			depth--
		case 5:
			iNdEx += 4
		default:
			return 0, fmt.Errorf("proto: illegal wireType %d", wireType)
		}
		if iNdEx < 0 {
			return 0, ErrInvalidLengthSuspiciousAccountList
		}
		if depth == 0 {
			return iNdEx, nil
		}
	}
	return 0, io.ErrUnexpectedEOF
}

var (
	ErrInvalidLengthSuspiciousAccountList        = fmt.Errorf("proto: negative length found during unmarshaling")
	ErrIntOverflowSuspiciousAccountList          = fmt.Errorf("proto: integer overflow")
	ErrUnexpectedEndOfGroupSuspiciousAccountList = fmt.Errorf("proto: unexpected end of group")
)