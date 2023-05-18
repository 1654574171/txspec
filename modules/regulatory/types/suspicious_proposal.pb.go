// Code generated by protoc-gen-gogo. DO NOT EDIT.
// source: regulatory/regulatory/suspicious_proposal.proto

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

type SuspiciousProposal struct {
	Title                 string                 `protobuf:"bytes,1,opt,name=title,proto3" json:"title,omitempty"`
	Description           string                 `protobuf:"bytes,2,opt,name=description,proto3" json:"description,omitempty"`
	SuspiciousAccountList *SuspiciousAccountList `protobuf:"bytes,3,opt,name=suspiciousAccountList,proto3" json:"suspiciousAccountList,omitempty"`
}

func (m *SuspiciousProposal) Reset()         { *m = SuspiciousProposal{} }
func (m *SuspiciousProposal) String() string { return proto.CompactTextString(m) }
func (*SuspiciousProposal) ProtoMessage()    {}
func (*SuspiciousProposal) Descriptor() ([]byte, []int) {
	return fileDescriptor_e7b0b2b19db3bafe, []int{0}
}
func (m *SuspiciousProposal) XXX_Unmarshal(b []byte) error {
	return m.Unmarshal(b)
}
func (m *SuspiciousProposal) XXX_Marshal(b []byte, deterministic bool) ([]byte, error) {
	if deterministic {
		return xxx_messageInfo_SuspiciousProposal.Marshal(b, m, deterministic)
	} else {
		b = b[:cap(b)]
		n, err := m.MarshalToSizedBuffer(b)
		if err != nil {
			return nil, err
		}
		return b[:n], nil
	}
}
func (m *SuspiciousProposal) XXX_Merge(src proto.Message) {
	xxx_messageInfo_SuspiciousProposal.Merge(m, src)
}
func (m *SuspiciousProposal) XXX_Size() int {
	return m.Size()
}
func (m *SuspiciousProposal) XXX_DiscardUnknown() {
	xxx_messageInfo_SuspiciousProposal.DiscardUnknown(m)
}

var xxx_messageInfo_SuspiciousProposal proto.InternalMessageInfo

func (m *SuspiciousProposal) GetTitle() string {
	if m != nil {
		return m.Title
	}
	return ""
}

func (m *SuspiciousProposal) GetDescription() string {
	if m != nil {
		return m.Description
	}
	return ""
}

func (m *SuspiciousProposal) GetSuspiciousAccountList() *SuspiciousAccountList {
	if m != nil {
		return m.SuspiciousAccountList
	}
	return nil
}

func init() {
	proto.RegisterType((*SuspiciousProposal)(nil), "regulatory.regulatory.SuspiciousProposal")
}

func init() {
	proto.RegisterFile("regulatory/regulatory/suspicious_proposal.proto", fileDescriptor_e7b0b2b19db3bafe)
}

var fileDescriptor_e7b0b2b19db3bafe = []byte{
	// 216 bytes of a gzipped FileDescriptorProto
	0x1f, 0x8b, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0xff, 0xe2, 0xd2, 0x2f, 0x4a, 0x4d, 0x2f,
	0xcd, 0x49, 0x2c, 0xc9, 0x2f, 0xaa, 0x44, 0x66, 0x16, 0x97, 0x16, 0x17, 0x64, 0x26, 0x67, 0xe6,
	0x97, 0x16, 0xc7, 0x17, 0x14, 0xe5, 0x17, 0xe4, 0x17, 0x27, 0xe6, 0xe8, 0x15, 0x14, 0xe5, 0x97,
	0xe4, 0x0b, 0x89, 0x22, 0x54, 0xe9, 0x21, 0x98, 0x52, 0xc6, 0x04, 0xcd, 0x49, 0x4c, 0x4e, 0xce,
	0x2f, 0xcd, 0x2b, 0x89, 0xcf, 0xc9, 0x2c, 0x2e, 0x81, 0x98, 0xa5, 0xb4, 0x81, 0x91, 0x4b, 0x28,
	0x18, 0xae, 0x22, 0x00, 0x6a, 0x91, 0x90, 0x08, 0x17, 0x6b, 0x49, 0x66, 0x49, 0x4e, 0xaa, 0x04,
	0xa3, 0x02, 0xa3, 0x06, 0x67, 0x10, 0x84, 0x23, 0xa4, 0xc0, 0xc5, 0x9d, 0x92, 0x5a, 0x9c, 0x5c,
	0x94, 0x59, 0x50, 0x92, 0x99, 0x9f, 0x27, 0xc1, 0x04, 0x96, 0x43, 0x16, 0x12, 0x4a, 0xe2, 0x12,
	0x45, 0xd8, 0xe7, 0x08, 0xb1, 0xce, 0x27, 0xb3, 0xb8, 0x44, 0x82, 0x59, 0x81, 0x51, 0x83, 0xdb,
	0x48, 0x47, 0x0f, 0xab, 0xd3, 0xf5, 0x82, 0xb1, 0xe9, 0x09, 0xc2, 0x6e, 0x94, 0x93, 0xf9, 0x89,
	0x47, 0x72, 0x8c, 0x17, 0x1e, 0xc9, 0x31, 0x3e, 0x78, 0x24, 0xc7, 0x38, 0xe1, 0xb1, 0x1c, 0xc3,
	0x85, 0xc7, 0x72, 0x0c, 0x37, 0x1e, 0xcb, 0x31, 0x44, 0xc9, 0x22, 0x79, 0xbb, 0x02, 0x39, 0x0c,
	0x4a, 0x2a, 0x0b, 0x52, 0x8b, 0x93, 0xd8, 0xc0, 0x5e, 0x36, 0x06, 0x04, 0x00, 0x00, 0xff, 0xff,
	0x48, 0xf3, 0x44, 0xee, 0x71, 0x01, 0x00, 0x00,
}

func (m *SuspiciousProposal) Marshal() (dAtA []byte, err error) {
	size := m.Size()
	dAtA = make([]byte, size)
	n, err := m.MarshalToSizedBuffer(dAtA[:size])
	if err != nil {
		return nil, err
	}
	return dAtA[:n], nil
}

func (m *SuspiciousProposal) MarshalTo(dAtA []byte) (int, error) {
	size := m.Size()
	return m.MarshalToSizedBuffer(dAtA[:size])
}

func (m *SuspiciousProposal) MarshalToSizedBuffer(dAtA []byte) (int, error) {
	i := len(dAtA)
	_ = i
	var l int
	_ = l
	if m.SuspiciousAccountList != nil {
		{
			size, err := m.SuspiciousAccountList.MarshalToSizedBuffer(dAtA[:i])
			if err != nil {
				return 0, err
			}
			i -= size
			i = encodeVarintSuspiciousProposal(dAtA, i, uint64(size))
		}
		i--
		dAtA[i] = 0x1a
	}
	if len(m.Description) > 0 {
		i -= len(m.Description)
		copy(dAtA[i:], m.Description)
		i = encodeVarintSuspiciousProposal(dAtA, i, uint64(len(m.Description)))
		i--
		dAtA[i] = 0x12
	}
	if len(m.Title) > 0 {
		i -= len(m.Title)
		copy(dAtA[i:], m.Title)
		i = encodeVarintSuspiciousProposal(dAtA, i, uint64(len(m.Title)))
		i--
		dAtA[i] = 0xa
	}
	return len(dAtA) - i, nil
}

func encodeVarintSuspiciousProposal(dAtA []byte, offset int, v uint64) int {
	offset -= sovSuspiciousProposal(v)
	base := offset
	for v >= 1<<7 {
		dAtA[offset] = uint8(v&0x7f | 0x80)
		v >>= 7
		offset++
	}
	dAtA[offset] = uint8(v)
	return base
}
func (m *SuspiciousProposal) Size() (n int) {
	if m == nil {
		return 0
	}
	var l int
	_ = l
	l = len(m.Title)
	if l > 0 {
		n += 1 + l + sovSuspiciousProposal(uint64(l))
	}
	l = len(m.Description)
	if l > 0 {
		n += 1 + l + sovSuspiciousProposal(uint64(l))
	}
	if m.SuspiciousAccountList != nil {
		l = m.SuspiciousAccountList.Size()
		n += 1 + l + sovSuspiciousProposal(uint64(l))
	}
	return n
}

func sovSuspiciousProposal(x uint64) (n int) {
	return (math_bits.Len64(x|1) + 6) / 7
}
func sozSuspiciousProposal(x uint64) (n int) {
	return sovSuspiciousProposal(uint64((x << 1) ^ uint64((int64(x) >> 63))))
}
func (m *SuspiciousProposal) Unmarshal(dAtA []byte) error {
	l := len(dAtA)
	iNdEx := 0
	for iNdEx < l {
		preIndex := iNdEx
		var wire uint64
		for shift := uint(0); ; shift += 7 {
			if shift >= 64 {
				return ErrIntOverflowSuspiciousProposal
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
			return fmt.Errorf("proto: SuspiciousProposal: wiretype end group for non-group")
		}
		if fieldNum <= 0 {
			return fmt.Errorf("proto: SuspiciousProposal: illegal tag %d (wire type %d)", fieldNum, wire)
		}
		switch fieldNum {
		case 1:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field Title", wireType)
			}
			var stringLen uint64
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowSuspiciousProposal
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
				return ErrInvalidLengthSuspiciousProposal
			}
			postIndex := iNdEx + intStringLen
			if postIndex < 0 {
				return ErrInvalidLengthSuspiciousProposal
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
					return ErrIntOverflowSuspiciousProposal
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
				return ErrInvalidLengthSuspiciousProposal
			}
			postIndex := iNdEx + intStringLen
			if postIndex < 0 {
				return ErrInvalidLengthSuspiciousProposal
			}
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			m.Description = string(dAtA[iNdEx:postIndex])
			iNdEx = postIndex
		case 3:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field SuspiciousAccountList", wireType)
			}
			var msglen int
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowSuspiciousProposal
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
				return ErrInvalidLengthSuspiciousProposal
			}
			postIndex := iNdEx + msglen
			if postIndex < 0 {
				return ErrInvalidLengthSuspiciousProposal
			}
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			if m.SuspiciousAccountList == nil {
				m.SuspiciousAccountList = &SuspiciousAccountList{}
			}
			if err := m.SuspiciousAccountList.Unmarshal(dAtA[iNdEx:postIndex]); err != nil {
				return err
			}
			iNdEx = postIndex
		default:
			iNdEx = preIndex
			skippy, err := skipSuspiciousProposal(dAtA[iNdEx:])
			if err != nil {
				return err
			}
			if (skippy < 0) || (iNdEx+skippy) < 0 {
				return ErrInvalidLengthSuspiciousProposal
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
func skipSuspiciousProposal(dAtA []byte) (n int, err error) {
	l := len(dAtA)
	iNdEx := 0
	depth := 0
	for iNdEx < l {
		var wire uint64
		for shift := uint(0); ; shift += 7 {
			if shift >= 64 {
				return 0, ErrIntOverflowSuspiciousProposal
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
					return 0, ErrIntOverflowSuspiciousProposal
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
					return 0, ErrIntOverflowSuspiciousProposal
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
				return 0, ErrInvalidLengthSuspiciousProposal
			}
			iNdEx += length
		case 3:
			depth++
		case 4:
			if depth == 0 {
				return 0, ErrUnexpectedEndOfGroupSuspiciousProposal
			}
			depth--
		case 5:
			iNdEx += 4
		default:
			return 0, fmt.Errorf("proto: illegal wireType %d", wireType)
		}
		if iNdEx < 0 {
			return 0, ErrInvalidLengthSuspiciousProposal
		}
		if depth == 0 {
			return iNdEx, nil
		}
	}
	return 0, io.ErrUnexpectedEOF
}

var (
	ErrInvalidLengthSuspiciousProposal        = fmt.Errorf("proto: negative length found during unmarshaling")
	ErrIntOverflowSuspiciousProposal          = fmt.Errorf("proto: integer overflow")
	ErrUnexpectedEndOfGroupSuspiciousProposal = fmt.Errorf("proto: unexpected end of group")
)