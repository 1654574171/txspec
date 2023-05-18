// Code generated by protoc-gen-gogo. DO NOT EDIT.
// source: regulatory/regulatory/registration.proto

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

type Registration struct {
	RegulatoryServiceName string    `protobuf:"bytes,1,opt,name=regulatoryServiceName,proto3" json:"regulatoryServiceName,omitempty"`
	IasAttestatioReport   string    `protobuf:"bytes,2,opt,name=iasAttestatioReport,proto3" json:"iasAttestatioReport,omitempty"`
	EnclavePK             string    `protobuf:"bytes,3,opt,name=enclavePK,proto3" json:"enclavePK,omitempty"`
	Endpoint              *Endpoint `protobuf:"bytes,4,opt,name=endpoint,proto3" json:"endpoint,omitempty"`
}

func (m *Registration) Reset()         { *m = Registration{} }
func (m *Registration) String() string { return proto.CompactTextString(m) }
func (*Registration) ProtoMessage()    {}
func (*Registration) Descriptor() ([]byte, []int) {
	return fileDescriptor_9e445d0af0a1de79, []int{0}
}
func (m *Registration) XXX_Unmarshal(b []byte) error {
	return m.Unmarshal(b)
}
func (m *Registration) XXX_Marshal(b []byte, deterministic bool) ([]byte, error) {
	if deterministic {
		return xxx_messageInfo_Registration.Marshal(b, m, deterministic)
	} else {
		b = b[:cap(b)]
		n, err := m.MarshalToSizedBuffer(b)
		if err != nil {
			return nil, err
		}
		return b[:n], nil
	}
}
func (m *Registration) XXX_Merge(src proto.Message) {
	xxx_messageInfo_Registration.Merge(m, src)
}
func (m *Registration) XXX_Size() int {
	return m.Size()
}
func (m *Registration) XXX_DiscardUnknown() {
	xxx_messageInfo_Registration.DiscardUnknown(m)
}

var xxx_messageInfo_Registration proto.InternalMessageInfo

func (m *Registration) GetRegulatoryServiceName() string {
	if m != nil {
		return m.RegulatoryServiceName
	}
	return ""
}

func (m *Registration) GetIasAttestatioReport() string {
	if m != nil {
		return m.IasAttestatioReport
	}
	return ""
}

func (m *Registration) GetEnclavePK() string {
	if m != nil {
		return m.EnclavePK
	}
	return ""
}

func (m *Registration) GetEndpoint() *Endpoint {
	if m != nil {
		return m.Endpoint
	}
	return nil
}

func init() {
	proto.RegisterType((*Registration)(nil), "regulatory.regulatory.Registration")
}

func init() {
	proto.RegisterFile("regulatory/regulatory/registration.proto", fileDescriptor_9e445d0af0a1de79)
}

var fileDescriptor_9e445d0af0a1de79 = []byte{
	// 225 bytes of a gzipped FileDescriptorProto
	0x1f, 0x8b, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0xff, 0xe2, 0xd2, 0x28, 0x4a, 0x4d, 0x2f,
	0xcd, 0x49, 0x2c, 0xc9, 0x2f, 0xaa, 0xd4, 0x47, 0x65, 0x66, 0x16, 0x97, 0x14, 0x25, 0x96, 0x64,
	0xe6, 0xe7, 0xe9, 0x15, 0x14, 0xe5, 0x97, 0xe4, 0x0b, 0x89, 0x22, 0xa4, 0xf5, 0x10, 0x4c, 0x29,
	0x15, 0xec, 0x06, 0xa4, 0xe6, 0xa5, 0x14, 0xe4, 0x67, 0xe6, 0x95, 0x40, 0x34, 0x2b, 0x5d, 0x64,
	0xe4, 0xe2, 0x09, 0x42, 0x32, 0x53, 0xc8, 0x84, 0x0b, 0xc9, 0xbc, 0xe0, 0xd4, 0xa2, 0xb2, 0xcc,
	0xe4, 0x54, 0xbf, 0xc4, 0xdc, 0x54, 0x09, 0x46, 0x05, 0x46, 0x0d, 0xce, 0x20, 0xec, 0x92, 0x42,
	0x06, 0x5c, 0xc2, 0x99, 0x89, 0xc5, 0x8e, 0x25, 0x25, 0xa9, 0xc5, 0x25, 0x20, 0x73, 0x82, 0x52,
	0x0b, 0xf2, 0x8b, 0x4a, 0x24, 0x98, 0xc0, 0x7a, 0xb0, 0x49, 0x09, 0xc9, 0x70, 0x71, 0xa6, 0xe6,
	0x25, 0xe7, 0x24, 0x96, 0xa5, 0x06, 0x78, 0x4b, 0x30, 0x83, 0xd5, 0x21, 0x04, 0x84, 0xac, 0xb9,
	0x38, 0x60, 0x0e, 0x95, 0x60, 0x51, 0x60, 0xd4, 0xe0, 0x36, 0x92, 0xd7, 0xc3, 0xea, 0x4d, 0x3d,
	0x57, 0xa8, 0xb2, 0x20, 0xb8, 0x06, 0x27, 0xf3, 0x13, 0x8f, 0xe4, 0x18, 0x2f, 0x3c, 0x92, 0x63,
	0x7c, 0xf0, 0x48, 0x8e, 0x71, 0xc2, 0x63, 0x39, 0x86, 0x0b, 0x8f, 0xe5, 0x18, 0x6e, 0x3c, 0x96,
	0x63, 0x88, 0x92, 0x45, 0x0a, 0x88, 0x0a, 0xe4, 0x50, 0x29, 0xa9, 0x2c, 0x48, 0x2d, 0x4e, 0x62,
	0x03, 0x87, 0x89, 0x31, 0x20, 0x00, 0x00, 0xff, 0xff, 0xd7, 0x27, 0x1e, 0xa2, 0x7c, 0x01, 0x00,
	0x00,
}

func (m *Registration) Marshal() (dAtA []byte, err error) {
	size := m.Size()
	dAtA = make([]byte, size)
	n, err := m.MarshalToSizedBuffer(dAtA[:size])
	if err != nil {
		return nil, err
	}
	return dAtA[:n], nil
}

func (m *Registration) MarshalTo(dAtA []byte) (int, error) {
	size := m.Size()
	return m.MarshalToSizedBuffer(dAtA[:size])
}

func (m *Registration) MarshalToSizedBuffer(dAtA []byte) (int, error) {
	i := len(dAtA)
	_ = i
	var l int
	_ = l
	if m.Endpoint != nil {
		{
			size, err := m.Endpoint.MarshalToSizedBuffer(dAtA[:i])
			if err != nil {
				return 0, err
			}
			i -= size
			i = encodeVarintRegistration(dAtA, i, uint64(size))
		}
		i--
		dAtA[i] = 0x22
	}
	if len(m.EnclavePK) > 0 {
		i -= len(m.EnclavePK)
		copy(dAtA[i:], m.EnclavePK)
		i = encodeVarintRegistration(dAtA, i, uint64(len(m.EnclavePK)))
		i--
		dAtA[i] = 0x1a
	}
	if len(m.IasAttestatioReport) > 0 {
		i -= len(m.IasAttestatioReport)
		copy(dAtA[i:], m.IasAttestatioReport)
		i = encodeVarintRegistration(dAtA, i, uint64(len(m.IasAttestatioReport)))
		i--
		dAtA[i] = 0x12
	}
	if len(m.RegulatoryServiceName) > 0 {
		i -= len(m.RegulatoryServiceName)
		copy(dAtA[i:], m.RegulatoryServiceName)
		i = encodeVarintRegistration(dAtA, i, uint64(len(m.RegulatoryServiceName)))
		i--
		dAtA[i] = 0xa
	}
	return len(dAtA) - i, nil
}

func encodeVarintRegistration(dAtA []byte, offset int, v uint64) int {
	offset -= sovRegistration(v)
	base := offset
	for v >= 1<<7 {
		dAtA[offset] = uint8(v&0x7f | 0x80)
		v >>= 7
		offset++
	}
	dAtA[offset] = uint8(v)
	return base
}
func (m *Registration) Size() (n int) {
	if m == nil {
		return 0
	}
	var l int
	_ = l
	l = len(m.RegulatoryServiceName)
	if l > 0 {
		n += 1 + l + sovRegistration(uint64(l))
	}
	l = len(m.IasAttestatioReport)
	if l > 0 {
		n += 1 + l + sovRegistration(uint64(l))
	}
	l = len(m.EnclavePK)
	if l > 0 {
		n += 1 + l + sovRegistration(uint64(l))
	}
	if m.Endpoint != nil {
		l = m.Endpoint.Size()
		n += 1 + l + sovRegistration(uint64(l))
	}
	return n
}

func sovRegistration(x uint64) (n int) {
	return (math_bits.Len64(x|1) + 6) / 7
}
func sozRegistration(x uint64) (n int) {
	return sovRegistration(uint64((x << 1) ^ uint64((int64(x) >> 63))))
}
func (m *Registration) Unmarshal(dAtA []byte) error {
	l := len(dAtA)
	iNdEx := 0
	for iNdEx < l {
		preIndex := iNdEx
		var wire uint64
		for shift := uint(0); ; shift += 7 {
			if shift >= 64 {
				return ErrIntOverflowRegistration
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
			return fmt.Errorf("proto: Registration: wiretype end group for non-group")
		}
		if fieldNum <= 0 {
			return fmt.Errorf("proto: Registration: illegal tag %d (wire type %d)", fieldNum, wire)
		}
		switch fieldNum {
		case 1:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field RegulatoryServiceName", wireType)
			}
			var stringLen uint64
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowRegistration
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
				return ErrInvalidLengthRegistration
			}
			postIndex := iNdEx + intStringLen
			if postIndex < 0 {
				return ErrInvalidLengthRegistration
			}
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			m.RegulatoryServiceName = string(dAtA[iNdEx:postIndex])
			iNdEx = postIndex
		case 2:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field IasAttestatioReport", wireType)
			}
			var stringLen uint64
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowRegistration
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
				return ErrInvalidLengthRegistration
			}
			postIndex := iNdEx + intStringLen
			if postIndex < 0 {
				return ErrInvalidLengthRegistration
			}
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			m.IasAttestatioReport = string(dAtA[iNdEx:postIndex])
			iNdEx = postIndex
		case 3:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field EnclavePK", wireType)
			}
			var stringLen uint64
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowRegistration
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
				return ErrInvalidLengthRegistration
			}
			postIndex := iNdEx + intStringLen
			if postIndex < 0 {
				return ErrInvalidLengthRegistration
			}
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			m.EnclavePK = string(dAtA[iNdEx:postIndex])
			iNdEx = postIndex
		case 4:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field Endpoint", wireType)
			}
			var msglen int
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowRegistration
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
				return ErrInvalidLengthRegistration
			}
			postIndex := iNdEx + msglen
			if postIndex < 0 {
				return ErrInvalidLengthRegistration
			}
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			if m.Endpoint == nil {
				m.Endpoint = &Endpoint{}
			}
			if err := m.Endpoint.Unmarshal(dAtA[iNdEx:postIndex]); err != nil {
				return err
			}
			iNdEx = postIndex
		default:
			iNdEx = preIndex
			skippy, err := skipRegistration(dAtA[iNdEx:])
			if err != nil {
				return err
			}
			if (skippy < 0) || (iNdEx+skippy) < 0 {
				return ErrInvalidLengthRegistration
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
func skipRegistration(dAtA []byte) (n int, err error) {
	l := len(dAtA)
	iNdEx := 0
	depth := 0
	for iNdEx < l {
		var wire uint64
		for shift := uint(0); ; shift += 7 {
			if shift >= 64 {
				return 0, ErrIntOverflowRegistration
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
					return 0, ErrIntOverflowRegistration
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
					return 0, ErrIntOverflowRegistration
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
				return 0, ErrInvalidLengthRegistration
			}
			iNdEx += length
		case 3:
			depth++
		case 4:
			if depth == 0 {
				return 0, ErrUnexpectedEndOfGroupRegistration
			}
			depth--
		case 5:
			iNdEx += 4
		default:
			return 0, fmt.Errorf("proto: illegal wireType %d", wireType)
		}
		if iNdEx < 0 {
			return 0, ErrInvalidLengthRegistration
		}
		if depth == 0 {
			return iNdEx, nil
		}
	}
	return 0, io.ErrUnexpectedEOF
}

var (
	ErrInvalidLengthRegistration        = fmt.Errorf("proto: negative length found during unmarshaling")
	ErrIntOverflowRegistration          = fmt.Errorf("proto: integer overflow")
	ErrUnexpectedEndOfGroupRegistration = fmt.Errorf("proto: unexpected end of group")
)
