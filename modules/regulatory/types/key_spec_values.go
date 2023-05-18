package types

import "encoding/binary"

var _ binary.ByteOrder

const (
    // SpecValuesKeyPrefix is the prefix to retrieve all SpecValues
	SpecValuesKeyPrefix = "SpecValues/value/"
)

// SpecValuesKey returns the store key to retrieve a SpecValues from the index fields
func SpecValuesKey(
contractAddress string,
) []byte {
	var key []byte
    
    contractAddressBytes := []byte(contractAddress)
    key = append(key, contractAddressBytes...)
    key = append(key, []byte("/")...)
    
	return key
}