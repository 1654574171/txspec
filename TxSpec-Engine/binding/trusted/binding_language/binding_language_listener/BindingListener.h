#pragma once
#include <map>
#include <string>
#include <iostream>
#include "trusted/binding_language/antlr4_generated/BindingParserBaseListener.h"
#include "DataType.h"

class BindingListener : public BindingParserBaseListener {
    public:
        std::vector<binding::EventRuleList*>* eventRuleList;

    public:
        BindingListener(std::vector<binding::EventRuleList*>* result) : eventRuleList(result) {}
        void enterEventToRules(BindingParser::EventToRulesContext * ctx) override;
        void enterRuleItem(BindingParser::RuleItemContext * ctx) override;

        std::string printEventRuleList();
};