parser grammar BindingParser;

options { tokenVocab = BindingLexer; }

root
    : ruleBinding EOF;

ruleBinding
    : RULES L_CURLY bindingList R_CURLY;

bindingList
    : (eventToRules SEMI)+;

eventToRules
    : event MAP L_BRACKET ruleList R_BRACKET;

event
    : IDENTIFIER;

ruleList
    : ruleItem
    | (ruleItem COMMA)+ ruleItem;

ruleItem
    : ruleFileName DOT ruleID;

ruleFileName
    : IDENTIFIER;

ruleID
    : IDENTIFIER;



