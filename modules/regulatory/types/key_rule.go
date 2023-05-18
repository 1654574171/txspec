package types

import "encoding/binary"

var _ binary.ByteOrder

const (
	// RuleKeyPrefix is the prefix to retrieve all Rule
	RuleKeyPrefix = "Rule/value/"
)

// RuleKey returns the store key to retrieve a Rule from the index fields
func RuleKey(
	ruleName string,
) []byte {
	var key []byte

	ruleNameBytes := []byte(ruleName)
	key = append(key, ruleNameBytes...)
	key = append(key, []byte("/")...)

	return key
}
