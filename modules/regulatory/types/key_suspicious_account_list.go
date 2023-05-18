package types

import "encoding/binary"

var _ binary.ByteOrder

const (
    // SuspiciousAccountListKeyPrefix is the prefix to retrieve all SuspiciousAccountList
	SuspiciousAccountListKeyPrefix = "SuspiciousAccountList/value/"
)

// SuspiciousAccountListKey returns the store key to retrieve a SuspiciousAccountList from the index fields
func SuspiciousAccountListKey(
contractAddress string,
) []byte {
	var key []byte
    
    contractAddressBytes := []byte(contractAddress)
    key = append(key, contractAddressBytes...)
    key = append(key, []byte("/")...)
    
	return key
}