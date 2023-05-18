package types

import "encoding/binary"

var _ binary.ByteOrder

const (
	// BindingKeyPrefix is the prefix to retrieve all Binding
	BindingKeyPrefix = "Binding/value/"
)

// BindingKey returns the store key to retrieve a Binding from the index fields
func BindingKey(
	bindingName string,
) []byte {
	var key []byte

	bindingNameBytes := []byte(bindingName)
	key = append(key, bindingNameBytes...)
	key = append(key, []byte("/")...)

	return key
}
