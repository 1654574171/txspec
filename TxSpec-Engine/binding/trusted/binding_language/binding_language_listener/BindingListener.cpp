#include "BindingListener.h"
#include "trusted/test_utils/TestUtils.h"

using namespace std;

string BindingListener::printEventRuleList() {
    string format;
    for (auto eventRules : *eventRuleList) {
        format.append(eventRules->event).append(":[ \n");
        for (auto ruleitemlist : eventRules->ruleItemList) {
            format.append (ruleitemlist.second.ruleFileName).append(":[\n");
            for (auto ruleIds : ruleitemlist.second.ruldIDs) {
                format.append (ruleIds).append(",\n");
            }
            format.append("]\n");
        }
        format.append("]");
    }

    return format;
}

void BindingListener::enterEventToRules(BindingParser::EventToRulesContext * ctx) {
    BINDING_INFO("enter function: enterEventToRules");
    binding::EventRuleList* eventRule = new binding::EventRuleList(ctx->event()->getText());
    eventRuleList->push_back(eventRule);
}


void BindingListener::enterRuleItem(BindingParser::RuleItemContext * ctx) {
    BINDING_INFO("enter function: enterRuleItem");
    string ruleFileName = ctx->ruleFileName()->getText();
    string ruleID = ctx->ruleID()->getText();
    binding::EventRuleList* curEvenRule = eventRuleList->back();

    if (curEvenRule->ruleItemList.count(ruleFileName) > 0) {
        curEvenRule->ruleItemList[ruleFileName].ruldIDs.insert(ruleID);
    } else {
        binding::RuleItemList newRuleFile = binding::RuleItemList(ruleFileName);
        newRuleFile.ruldIDs.insert(ruleID);
        curEvenRule->ruleItemList[ruleFileName] = newRuleFile;
    }

    BINDING_INFO_STRING(printEventRuleList());
}





