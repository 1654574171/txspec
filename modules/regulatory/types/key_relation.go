package types

import "encoding/binary"

var _ binary.ByteOrder

const (
	// RelationKeyPrefix is the prefix to retrieve all Relation
	RelationKeyPrefix = "Relation/value/"
)

// RelationKey returns the store key to retrieve a Relation from the index fields
func RelationKey(
	contractAddress string,
) []byte {
	var key []byte

	contractAddressBytes := []byte(contractAddress)
	key = append(key, contractAddressBytes...)
	key = append(key, []byte("/")...)

	return key
}
