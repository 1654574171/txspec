#pragma once

#include "binding_language_listener/BindingListener.h"
#include "e2e_message/RuleCheck.pb.h"

class BindingResolver {
    public:
        std::vector<binding::EventRuleList*>* eventRuleList;

    public:
        void resolveBindingString(std::string bindingString);
        void fillRuleCheckRequest(e2e_message::RuleCheckRequest* request, std::vector<std::string>& events);

};