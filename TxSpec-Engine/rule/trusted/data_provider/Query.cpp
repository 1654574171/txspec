#include "Query.h"

using namespace std;
using namespace rule_check_proto;
using namespace json11;

const string QueryBuilder::QUERY_PREFIX = R"-( {"query":"{ )-";
const string QueryBuilder::QUERY_SUBFIX = R"-( }"} )-";
const string QueryBuilder::QUERY_CONSTRAINS_PREFIX = R"-((where:{ )-";
const string QueryBuilder::QUERY_CONSTRAINS_SUBFIX = R"-(}))-";
const string QueryBuilder::QUERY_ATTRIBUTES_PREFIX = R"-({)-";
const string QueryBuilder::QUERY_ATTRIBUTES_SUBFIX = R"-(})-";

// for now, it is a particular function for rule
string QueryBuilder::GenerateQueryString(const EntityRule& entity) {
    string rule_query_string_prefix(R"-({"query":"{rules(where:{name:\")-");
    string rule_query_string_subfix(R"-(\"}){content \n }}"})-");
    return rule_query_string_prefix + entity.get_name() +
           rule_query_string_subfix;
}

string QueryBuilder::concatenateQueryString (const EntityType& entity, const RequestContext* context, const vector<string>& constraintStrs) {
    string query_tables(entity.get_name() + "s");
    
    string query_constrains;
    query_constrains.append(QUERY_CONSTRAINS_PREFIX);
    for (auto constrain : constraintStrs) {
        query_constrains.append(constrain);
    }
    query_constrains.append(QUERY_CONSTRAINS_SUBFIX);

    string query_attributes;
    query_attributes.append(QUERY_ATTRIBUTES_PREFIX);
    for (auto attribute : entity.get_attribute_set()) {
        query_attributes.append(attribute).append(" ");
    }
    query_attributes.append(QUERY_ATTRIBUTES_SUBFIX);

    string query_string;
    query_string.append(QUERY_PREFIX)
        .append(query_tables)
        .append(query_constrains)
        .append(query_attributes)
        .append(QUERY_SUBFIX);
    
    return query_string;
}

string QueryBuilder::GenerateQueryString(const Entity& entity, const RequestContext* context) {

    vector<string> constraintStrs;
    collectConstrainStrings(entity, context, constraintStrs);
    string query_string = concatenateQueryString(dynamic_cast<const EntityType&>(entity), context, constraintStrs);
    
    ocall_print_string(("GenerateQueryString(const Entity& entity, const RequestContext* context) : " + query_string).c_str(), __FILE__, __LINE__);
    return query_string;
}

string QueryBuilder::GenerateQueryString(EntitySet& entity, const RequestContext* context) {
    vector<string> constraintStrs;
    collectConstrainStrings(entity, context, constraintStrs);
    string query_string = concatenateQueryString(dynamic_cast<const EntityType&>(entity), context, constraintStrs);

    ocall_print_string(("GenerateQueryString(const EntitySet& entity, const RequestContext* context) : " + query_string).c_str(), __FILE__, __LINE__);
    return query_string;
}


uint64_t QueryBuilder::getTimestampValue(const RequestContext* context, const string& entity_name) {
    const auto initial_binding = context->get_entity_binding(entity_name);
    auto timestamp_json = initial_binding[entity_name]["timestamp"];

    uint64_t timestamp = 0;
    int entity_timestamp_value = stoi(timestamp_json.string_value());
    if (entity_timestamp_value < 0) {
        uint64_t mask = 0x000000007FFFFFFFUL;
        uint64_t minus_bit = 0x0000000080000000UL;
        timestamp = entity_timestamp_value & mask | minus_bit;
    } else {
        timestamp = static_cast<uint64_t>(entity_timestamp_value);
    }

    return timestamp;
}

uint64_t QueryBuilder::handleWithinValue(uint64_t timestamp, const rule_check_proto::Within& within) {
    uint64_t within_value = within.value();
    Within_UNIT unit = within.unit();
    ocall_print_string("handle within", __FILE__, __LINE__);
    uint64_t result = 0;
    switch (unit) {
        case Within_UNIT_SEC:
            result = timestamp - within_value * 1000;
            break;
        case Within_UNIT_MINIT:
            result = timestamp - within_value * 60 * 1000;
            break;
        case Within_UNIT_HOUR:
            result = timestamp - within_value * 60 * 60 * 1000;
            break;
        case Within_UNIT_DAY:
            result = timestamp - within_value * 24 * 60 * 60 * 1000;
            break;
        default:
            break;
    }
    return result;
}

void QueryBuilder::collectConstrainStrings(EntitySet& entity, const RequestContext* context, vector<string>& constraintStrs) {
    // constraintStrs.push_back(R"-(contract_address:\")-" +
    //                               context->contract_id + R"-(\" )-");
    for (auto constrain : entity.get_constraint_list()) {
        if (constrain.has_within()) {
            ocall_print_string("handle within", __FILE__, __LINE__);
            auto within = constrain.within();
            uint64_t timestamp = getTimestampValue(context, entity.get_name());
            timestamp = handleWithinValue(timestamp, within);
            constraintStrs.push_back(R"-(timestamp_gt:)-" + to_string(timestamp) + R"-( )-");
        }

        if (constrain.has_provided()) {
            ocall_print_string("handle provided", __FILE__, __LINE__);
            auto provide = constrain.provided();
            constraintStrs.push_back(provide.entity() + ":" + R"(\")" + provide.member() + R"(\" )");
        }

        if (constrain.has_where()) {
            ocall_print_string("handle where", __FILE__, __LINE__);
            auto where = constrain.where();
            const auto entity_name = where.left_entity();
            const auto attribute_name = where.left_member();

            ocall_print_string((entity_name + "." + attribute_name).c_str(), __FILE__, __LINE__);
            auto binding_json = context->get_entity_binding(entity_name);
            ocall_print_string(binding_json.dump().c_str(), __FILE__, __LINE__);
            auto binding_data = binding_json[entity_name][attribute_name].string_value();
            ocall_print_string(binding_data.c_str(), __FILE__, __LINE__);
            constraintStrs.push_back(string(attribute_name + ":") + R"(\")" + binding_data + R"(\" )");

            entity.add_attributes(attribute_name);
        }
    }
}

void QueryBuilder::collectConstrainStrings(const Entity& entity, const RequestContext* context, vector<string>& constraintStrs) {
    constraintStrs.push_back(R"-(contract_address:\")-" +
                                  context->contract_id + R"-(\" )-");
    constraintStrs.push_back(R"-(hash:\")-" + context->tx_hash + R"-(\" )-");
}