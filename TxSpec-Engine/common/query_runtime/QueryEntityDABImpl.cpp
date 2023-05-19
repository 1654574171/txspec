#include "QueryEntityDABImpl.h"

using namespace request_proto;
using namespace json11;
using namespace std;

string QueryEntityDABImpl::QueryEntityString(TransactionInfo *tx)
{
    // SPDLOG_INFO("enter QueryEntityString_DAB");
    map<string, Json> outter;
    
    if (tx->func_name() == "Transfer" || tx->func_name() == "transfer")
    {
        map<string, string> inner;
        inner["channel_id"] = tx->ch_id();
        inner["chaincode_id"] = tx->cc_id();

        // Hard-code for DAB contract
        if (tx->cc_id() == "OXTokenContract" || tx->cc_id() == "OXTokenContractTest"){
            inner["to"] = tx->args()[1];
            inner["value"] = tx->args()[2];
        } 
        else {
            inner["to"] = tx->args()[0];
            inner["value"] = tx->args()[1];
        }
        
        inner["timestamp"] = tx->timestamp();
        inner["block_num"] = tx->version().block_number();
        inner["tx_index"] = "0";
        for (auto wset : tx->wset().pb_wset())
        {
            char min_unicode_rune_value = '0' - '0';
            string pattern = "0";
            pattern[0] = min_unicode_rune_value;
            vector<string> units = split(wset.key(), pattern);
            if (units.size() == 4 && units[0] == "" && units[1] == "Balances" and units[2] != inner["to"])
            {
                inner["from"] = units[2];
            }
        }
        outter["transfer"] = Json(inner);
    }
    //update blacklist
    // ocall_print_string(to_string(tx->version().block_number()).c_str());
    if (tx->func_name() == "UpdateBlacklist" || tx->func_name() == "updateblacklist") {
        map<string, string> inner;
        inner["channel_id"] = tx->ch_id();
        inner["chaincode_id"] = tx->cc_id();
        // Hard-code for DAB contract
        if (tx->cc_id() == "OXTokenContract" || tx->cc_id() == "OXTokenContractTest"){
            inner["to"] = tx->args()[1];
            inner["value"] = tx->args()[2];
        }
        else {
            inner["to"] = tx->args()[0];
            inner["value"] = tx->args()[1];
        }
        inner["timestamp"] = tx->timestamp();
        inner["block_num"] = tx->version().block_number();
        inner["tx_index"] = "0";
        for (auto wset : tx->wset().pb_wset())
        {
            char min_unicode_rune_value = '0' - '0';
            string pattern = "0";
            pattern[0] = min_unicode_rune_value;
            vector<string> units = split(wset.key(), pattern);
            if (units.size() == 4 && units[0] == "" && units[1] == "BlacklistStateKey")
            {
                inner["account"] = units[2];
                inner["value"] = wset.value();
            }
        }
        outter["blacklist"] = Json(inner);
    }

    // SPDLOG_INFO("exit QueryEntityString_DAB");
    return Json(outter).dump();
}