#pragma once

#include <string>

#include "RuleEnclave_t.h" /* sgx generated proxy header */

#include "common/base64/Transform.h"
#include "common/json_lib/json11.hpp"

#include "protos/trusted/e2e_call_proto/EntityQuery.pb.h"
#include "protos/trusted/e2e_call_proto/E2EMessage.pb.h"

// using namespace std;

/* Mock Binding Functions for Rule Enclave Debug */

// @Params: serialized QueryEntityInput message in base64 encoding
// @Returns: mock serialized QueryEntityOutput message in base64 encoding
const std::string MockBindingQueryEntity(const std::string &base64_serialized_input);

// @Params: serialized QueryEntitySetInput message in base64 encoding
// @Returns: mock serialized QueryEntitySetOutput message in base64 encoding
const std::string MockBindingQueryEntitySet(const std::string &base64_serialized_input);