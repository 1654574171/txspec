package types

import "encoding/binary"

var _ binary.ByteOrder

const (
    // RewardListKeyPrefix is the prefix to retrieve all RewardList
	RewardListKeyPrefix = "RewardList/value/"
)

// RewardListKey returns the store key to retrieve a RewardList from the index fields
func RewardListKey(
contractAddress string,
) []byte {
	var key []byte
    
    contractAddressBytes := []byte(contractAddress)
    key = append(key, contractAddressBytes...)
    key = append(key, []byte("/")...)
    
	return key
}