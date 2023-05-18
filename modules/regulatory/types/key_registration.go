package types

import "encoding/binary"

var _ binary.ByteOrder

const (
    // RegistrationKeyPrefix is the prefix to retrieve all Registration
	RegistrationKeyPrefix = "Registration/value/"
)

// RegistrationKey returns the store key to retrieve a Registration from the index fields
func RegistrationKey(
regulatoryServiceName string,
) []byte {
	var key []byte
    
    regulatoryServiceNameBytes := []byte(regulatoryServiceName)
    key = append(key, regulatoryServiceNameBytes...)
    key = append(key, []byte("/")...)
    
	return key
}