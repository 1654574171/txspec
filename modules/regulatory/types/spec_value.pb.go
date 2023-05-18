// Code generated by protoc-gen-gogo. DO NOT EDIT.
// source: regulatory/regulatory/spec_value.proto

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

type SpecValue struct {
	//key:tx_hash
	//value:json type struct
	ValueMap map[string]string `protobuf:"bytes,1,rep,name=value_map,json=valueMap,proto3" json:"value_map,omitempty" protobuf_key:"bytes,1,opt,name=key,proto3" protobuf_val:"bytes,2,opt,name=value,proto3"`
}

func (m *SpecValue) Reset()         { *m = SpecValue{} }
func (m *SpecValue) String() string { return proto.CompactTextString(m) }
func (*SpecValue) ProtoMessage()    {}
func (*SpecValue) Descriptor() ([]byte, []int) {
	return fileDescriptor_782c839fb972a1cf, []int{0}
}
func (m *SpecValue) XXX_Unmarshal(b []byte) error {
	return m.Unmarshal(b)
}
func (m *SpecValue) XXX_Marshal(b []byte, deterministic bool) ([]byte, error) {
	if deterministic {
		return xxx_messageInfo_SpecValue.Marshal(b, m, deterministic)
	} else {
		b = b[:cap(b)]
		n, err := m.MarshalToSizedBuffer(b)
		if err != nil {
			return nil, err
		}
		return b[:n], nil
	}
}
func (m *SpecValue) XXX_Merge(src proto.Message) {
	xxx_messageInfo_SpecValue.Merge(m, src)
}
func (m *SpecValue) XXX_Size() int {
	return m.Size()
}
func (m *SpecValue) XXX_DiscardUnknown() {
	xxx_messageInfo_SpecValue.DiscardUnknown(m)
}

var xxx_messageInfo_SpecValue proto.InternalMessageInfo

func (m *SpecValue) GetValueMap() map[string]string {
	if m != nil {
		return m.ValueMap
	}
	return nil
}

func init() {
	proto.RegisterType((*SpecValue)(nil), "regulatory.regulatory.SpecValue")
	proto.RegisterMapType((map[string]string)(nil), "regulatory.regulatory.SpecValue.ValueMapEntry")
}

func init() {
	proto.RegisterFile("regulatory/regulatory/spec_value.proto", fileDescriptor_782c839fb972a1cf)
}

var fileDescriptor_782c839fb972a1cf = []byte{
	// 196 bytes of a gzipped FileDescriptorProto
	0x1f, 0x8b, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0xff, 0xe2, 0x52, 0x2b, 0x4a, 0x4d, 0x2f,
	0xcd, 0x49, 0x2c, 0xc9, 0x2f, 0xaa, 0xd4, 0x47, 0x62, 0x16, 0x17, 0xa4, 0x26, 0xc7, 0x97, 0x25,
	0xe6, 0x94, 0xa6, 0xea, 0x15, 0x14, 0xe5, 0x97, 0xe4, 0x0b, 0x89, 0x22, 0x24, 0xf5, 0x10, 0x4c,
	0xa5, 0xa9, 0x8c, 0x5c, 0x9c, 0xc1, 0x05, 0xa9, 0xc9, 0x61, 0x20, 0xa5, 0x42, 0xde, 0x5c, 0x9c,
	0x60, 0x3d, 0xf1, 0xb9, 0x89, 0x05, 0x12, 0x8c, 0x0a, 0xcc, 0x1a, 0xdc, 0x46, 0x7a, 0x7a, 0x58,
	0x35, 0xea, 0xc1, 0x35, 0xe9, 0x81, 0x49, 0xdf, 0xc4, 0x02, 0xd7, 0xbc, 0x92, 0xa2, 0xca, 0x20,
	0x8e, 0x32, 0x28, 0x57, 0xca, 0x9a, 0x8b, 0x17, 0x45, 0x4a, 0x48, 0x80, 0x8b, 0x39, 0x3b, 0xb5,
	0x52, 0x82, 0x51, 0x81, 0x51, 0x83, 0x33, 0x08, 0xc4, 0x14, 0x12, 0xe1, 0x62, 0x05, 0x2b, 0x97,
	0x60, 0x02, 0x8b, 0x41, 0x38, 0x56, 0x4c, 0x16, 0x8c, 0x4e, 0xe6, 0x27, 0x1e, 0xc9, 0x31, 0x5e,
	0x78, 0x24, 0xc7, 0xf8, 0xe0, 0x91, 0x1c, 0xe3, 0x84, 0xc7, 0x72, 0x0c, 0x17, 0x1e, 0xcb, 0x31,
	0xdc, 0x78, 0x2c, 0xc7, 0x10, 0x25, 0x8b, 0xe4, 0xcb, 0x0a, 0x64, 0x2f, 0x97, 0x54, 0x16, 0xa4,
	0x16, 0x27, 0xb1, 0x81, 0xbd, 0x6b, 0x0c, 0x08, 0x00, 0x00, 0xff, 0xff, 0x81, 0x24, 0x5d, 0x86,
	0x18, 0x01, 0x00, 0x00,
}

func (m *SpecValue) Marshal() (dAtA []byte, err error) {
	size := m.Size()
	dAtA = make([]byte, size)
	n, err := m.MarshalToSizedBuffer(dAtA[:size])
	if err != nil {
		return nil, err
	}
	return dAtA[:n], nil
}

func (m *SpecValue) MarshalTo(dAtA []byte) (int, error) {
	size := m.Size()
	return m.MarshalToSizedBuffer(dAtA[:size])
}

func (m *SpecValue) MarshalToSizedBuffer(dAtA []byte) (int, error) {
	i := len(dAtA)
	_ = i
	var l int
	_ = l
	if len(m.ValueMap) > 0 {
		for k := range m.ValueMap {
			v := m.ValueMap[k]
			baseI := i
			i -= len(v)
			copy(dAtA[i:], v)
			i = encodeVarintSpecValue(dAtA, i, uint64(len(v)))
			i--
			dAtA[i] = 0x12
			i -= len(k)
			copy(dAtA[i:], k)
			i = encodeVarintSpecValue(dAtA, i, uint64(len(k)))
			i--
			dAtA[i] = 0xa
			i = encodeVarintSpecValue(dAtA, i, uint64(baseI-i))
			i--
			dAtA[i] = 0xa
		}
	}
	return len(dAtA) - i, nil
}

func encodeVarintSpecValue(dAtA []byte, offset int, v uint64) int {
	offset -= sovSpecValue(v)
	base := offset
	for v >= 1<<7 {
		dAtA[offset] = uint8(v&0x7f | 0x80)
		v >>= 7
		offset++
	}
	dAtA[offset] = uint8(v)
	return base
}
func (m *SpecValue) Size() (n int) {
	if m == nil {
		return 0
	}
	var l int
	_ = l
	if len(m.ValueMap) > 0 {
		for k, v := range m.ValueMap {
			_ = k
			_ = v
			mapEntrySize := 1 + len(k) + sovSpecValue(uint64(len(k))) + 1 + len(v) + sovSpecValue(uint64(len(v)))
			n += mapEntrySize + 1 + sovSpecValue(uint64(mapEntrySize))
		}
	}
	return n
}

func sovSpecValue(x uint64) (n int) {
	return (math_bits.Len64(x|1) + 6) / 7
}
func sozSpecValue(x uint64) (n int) {
	return sovSpecValue(uint64((x << 1) ^ uint64((int64(x) >> 63))))
}
func (m *SpecValue) Unmarshal(dAtA []byte) error {
	l := len(dAtA)
	iNdEx := 0
	for iNdEx < l {
		preIndex := iNdEx
		var wire uint64
		for shift := uint(0); ; shift += 7 {
			if shift >= 64 {
				return ErrIntOverflowSpecValue
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
			return fmt.Errorf("proto: SpecValue: wiretype end group for non-group")
		}
		if fieldNum <= 0 {
			return fmt.Errorf("proto: SpecValue: illegal tag %d (wire type %d)", fieldNum, wire)
		}
		switch fieldNum {
		case 1:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field ValueMap", wireType)
			}
			var msglen int
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowSpecValue
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
				return ErrInvalidLengthSpecValue
			}
			postIndex := iNdEx + msglen
			if postIndex < 0 {
				return ErrInvalidLengthSpecValue
			}
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			if m.ValueMap == nil {
				m.ValueMap = make(map[string]string)
			}
			var mapkey string
			var mapvalue string
			for iNdEx < postIndex {
				entryPreIndex := iNdEx
				var wire uint64
				for shift := uint(0); ; shift += 7 {
					if shift >= 64 {
						return ErrIntOverflowSpecValue
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
				if fieldNum == 1 {
					var stringLenmapkey uint64
					for shift := uint(0); ; shift += 7 {
						if shift >= 64 {
							return ErrIntOverflowSpecValue
						}
						if iNdEx >= l {
							return io.ErrUnexpectedEOF
						}
						b := dAtA[iNdEx]
						iNdEx++
						stringLenmapkey |= uint64(b&0x7F) << shift
						if b < 0x80 {
							break
						}
					}
					intStringLenmapkey := int(stringLenmapkey)
					if intStringLenmapkey < 0 {
						return ErrInvalidLengthSpecValue
					}
					postStringIndexmapkey := iNdEx + intStringLenmapkey
					if postStringIndexmapkey < 0 {
						return ErrInvalidLengthSpecValue
					}
					if postStringIndexmapkey > l {
						return io.ErrUnexpectedEOF
					}
					mapkey = string(dAtA[iNdEx:postStringIndexmapkey])
					iNdEx = postStringIndexmapkey
				} else if fieldNum == 2 {
					var stringLenmapvalue uint64
					for shift := uint(0); ; shift += 7 {
						if shift >= 64 {
							return ErrIntOverflowSpecValue
						}
						if iNdEx >= l {
							return io.ErrUnexpectedEOF
						}
						b := dAtA[iNdEx]
						iNdEx++
						stringLenmapvalue |= uint64(b&0x7F) << shift
						if b < 0x80 {
							break
						}
					}
					intStringLenmapvalue := int(stringLenmapvalue)
					if intStringLenmapvalue < 0 {
						return ErrInvalidLengthSpecValue
					}
					postStringIndexmapvalue := iNdEx + intStringLenmapvalue
					if postStringIndexmapvalue < 0 {
						return ErrInvalidLengthSpecValue
					}
					if postStringIndexmapvalue > l {
						return io.ErrUnexpectedEOF
					}
					mapvalue = string(dAtA[iNdEx:postStringIndexmapvalue])
					iNdEx = postStringIndexmapvalue
				} else {
					iNdEx = entryPreIndex
					skippy, err := skipSpecValue(dAtA[iNdEx:])
					if err != nil {
						return err
					}
					if (skippy < 0) || (iNdEx+skippy) < 0 {
						return ErrInvalidLengthSpecValue
					}
					if (iNdEx + skippy) > postIndex {
						return io.ErrUnexpectedEOF
					}
					iNdEx += skippy
				}
			}
			m.ValueMap[mapkey] = mapvalue
			iNdEx = postIndex
		default:
			iNdEx = preIndex
			skippy, err := skipSpecValue(dAtA[iNdEx:])
			if err != nil {
				return err
			}
			if (skippy < 0) || (iNdEx+skippy) < 0 {
				return ErrInvalidLengthSpecValue
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
func skipSpecValue(dAtA []byte) (n int, err error) {
	l := len(dAtA)
	iNdEx := 0
	depth := 0
	for iNdEx < l {
		var wire uint64
		for shift := uint(0); ; shift += 7 {
			if shift >= 64 {
				return 0, ErrIntOverflowSpecValue
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
					return 0, ErrIntOverflowSpecValue
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
					return 0, ErrIntOverflowSpecValue
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
				return 0, ErrInvalidLengthSpecValue
			}
			iNdEx += length
		case 3:
			depth++
		case 4:
			if depth == 0 {
				return 0, ErrUnexpectedEndOfGroupSpecValue
			}
			depth--
		case 5:
			iNdEx += 4
		default:
			return 0, fmt.Errorf("proto: illegal wireType %d", wireType)
		}
		if iNdEx < 0 {
			return 0, ErrInvalidLengthSpecValue
		}
		if depth == 0 {
			return iNdEx, nil
		}
	}
	return 0, io.ErrUnexpectedEOF
}

var (
	ErrInvalidLengthSpecValue        = fmt.Errorf("proto: negative length found during unmarshaling")
	ErrIntOverflowSpecValue          = fmt.Errorf("proto: integer overflow")
	ErrUnexpectedEndOfGroupSpecValue = fmt.Errorf("proto: unexpected end of group")
)
