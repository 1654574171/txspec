#include <algorithm>
#include "BindingResolver.h"
#include "trusted/test_utils/TestUtils.h"
#include "trusted/binding_language/antlr4_generated/BindingLexer.h"

using namespace std;
using namespace antlr4;

void BindingResolver::resolveBindingString(string bindingString) {

    BINDING_INFO("enter function resolveBindingString");
    BINDING_INFO_STRING(bindingString);
    // initialize antlr4 ang get the AST of binding string
    ANTLRInputStream is(bindingString);
    BindingLexer lexer(&is);
    CommonTokenStream tokens(&lexer);
    BindingParser parser(&tokens);
    tree::ParseTree *tree = parser.root();

    // travel AST and listened by BindingListener
    this->eventRuleList = new vector<binding::EventRuleList*>();
    BindingListener bindingListener(eventRuleList);
    tree::ParseTreeWalker::DEFAULT.walk(&bindingListener, tree);
}

void BindingResolver::fillRuleCheckRequest(e2e_message::RuleCheckRequest* request, std::vector<std::string>& events) {
    for (auto rulelist : *this->eventRuleList) {
        BINDING_INFO("event name");
        BINDING_INFO_STRING(rulelist->event);
        if (find(events.begin(), events.end(), rulelist->event) != events.end()) {
            e2e_message::RuleItem* curRuleItem = request->add_ruleitems();
            for (auto ruleitem : rulelist->ruleItemList) {
                curRuleItem->set_rulefilename(ruleitem.second.ruleFileName);
                for (auto ruleid : ruleitem.second.ruldIDs) {
                    curRuleItem->add_ruleid(ruleid);
                }
            }
        }
    }  
}
