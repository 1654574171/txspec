#pragma once
#include <set>
#include <map>
#include <string>

namespace binding {

    class RuleItemList {
        public:
            std::string ruleFileName;
            std::set<std::string> ruldIDs;
            RuleItemList(std::string fileName) : ruleFileName(fileName) {}
            RuleItemList() = default;
            ~RuleItemList() = default;
    };

    class EventRuleList {
        public:
            std::string event;
            std::map<std::string, RuleItemList> ruleItemList; // rulefilename -> ruleitems
            EventRuleList(std::string eventName) : event(eventName) {}
            EventRuleList() = default;
            ~EventRuleList() = default;
    };
}