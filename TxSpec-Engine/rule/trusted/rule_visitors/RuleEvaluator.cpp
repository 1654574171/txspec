// LICENSE: Apache 2.0
// https://github.com/RegTech-OXH/compliance-engine
//
// Author:
//
// This file implements RuleEvaluator class.

#include "RuleEvaluator.h"

using namespace std;
using namespace antlr4;
using namespace json11;

/* Constructors and Destructors */
RuleEvaluator::RuleEvaluator(RequestContext *const request_context)
{
    this->request_context_ = request_context;
    // this->overall_evaluation_result_ = true; // request defaults to satisfied
}

RuleEvaluator::~RuleEvaluator() {}

/* Data Member Getters */

RequestContext *const RuleEvaluator::get_request_context()
{
    return this->request_context_;
}

const string &RuleEvaluator::get_set_element_name(const string &set_name)
{
    return this->set_element_map_[set_name];
}

/* helper functions for internal use */

RuleEnclaveStatus RuleEvaluator::KeepTrackOfNewSet(const string &set_name, const string &element_name)
{
    ocall_print_string(("KeepTrackOfNewSet: " + set_name + "[" + element_name + "]").c_str(), __FILE__, __LINE__);

    if (this->set_element_map_.find(set_name) == this->set_element_map_.end())
    {
        this->set_element_map_[set_name] = element_name;
        return RuleEnclaveStatus::kOK;
    }
    else
    {
        /* handle duplicate set name */
        // TODO how to handle this?
        // assert(false);
        return RuleEnclaveStatus::kError;
    }
}

void RuleEvaluator::ParseBooleanExpression(vector<tree::ParseTree *> context_list,
                                           vector<bool> *const boolean_value_list)
{
    // vector<bool> boolean_evaluation_list;
    boolean_value_list->clear();

    // traverse through context list
    for (const auto &context : context_list)
    {
        // decide on context type (we only care about BOOLEAN_LIT and selectorIdent)
        if (dynamic_cast<tree::TerminalNode *>(context) != nullptr)
        {
            auto terminal_node = dynamic_cast<tree::TerminalNode *>(context);
            // check if this is BOOLEAN_LIT
            if (terminal_node->getSymbol()->getType() != RuleLexer::BOOLEAN_LIT)
            {
                continue;
            }

            // bool evaluation result => BOOLEAN_LIT
            bool bool_value;
            this->ParseBooleanLiteral(terminal_node, &bool_value);
            boolean_value_list->push_back(bool_value);
        }
        else if (dynamic_cast<RuleParser::SelectorIdentContext *>(context) != nullptr)
        {
            auto selector_identity = dynamic_cast<RuleParser::SelectorIdentContext *>(context);

            // retrieve entity binding
            string entity_name = selector_identity->entityName()->getText();
            string attribute_name = selector_identity->attributeName()->getText();

            // entity Json object
            auto entity = this->get_entity_binding(entity_name);

            // TODO add error handling
            assert(entity[entity_name][attribute_name].is_string());
            bool bool_value;
            this->ParseBooleanLiteral(entity[entity_name][attribute_name].string_value(), &bool_value);
            boolean_value_list->push_back(bool_value);
        }
    }
}

const Json &RuleEvaluator::get_entity_binding(const string &entity_name)
{
    // first look up temporary entity binding map
    // then forward to request context function
    if (this->temporary_entity_binding_map_.find(entity_name) !=
        this->temporary_entity_binding_map_.end())
    {
        ocall_print_string((string("get entity binding from temporary map in RuleEvaluator: ") +
                            entity_name)
                               .c_str(),
                           __FILE__, __LINE__);
        return this->temporary_entity_binding_map_[entity_name];
    }
    else
    {
        ocall_print_string((string("get entity binding from request context map in RuleEvaluator: ") +
                            entity_name)
                               .c_str(),
                           __FILE__, __LINE__);
        return this->request_context_->get_entity_binding(entity_name);
    }
}

const Json &RuleEvaluator::get_entity_set_binding(const string &entity_set_id)
{
    // first look up temporary entity binding map
    // then forward to request context function
    if (this->temporary_entity_set_binding_map_.find(entity_set_id) !=
        this->temporary_entity_set_binding_map_.end())
    {
        ocall_print_string((string("get entity binding set from temporary map in RuleEvaluator: ") +
                            entity_set_id)
                               .c_str(),
                           __FILE__, __LINE__);
        return this->temporary_entity_set_binding_map_[entity_set_id];
    }
    else
    {
        ocall_print_string((string("get entity binding set from request context map in RuleEvaluator: ") +
                            entity_set_id)
                               .c_str(),
                           __FILE__, __LINE__);
        return this->request_context_->get_entity_set_binding(entity_set_id);
    }
}

void RuleEvaluator::set_temporary_entity_binding(const string &entity_name, const Json &binding)
{
    // update temporary entity binding map
    if (this->temporary_entity_binding_map_.find(entity_name) ==
        this->temporary_entity_binding_map_.end())
    {
        // TODO (Xufei) temporary_entity_binding_map_ should have a upper limit
        // if (this->temporary_entity_binding_map_.size() > 50) {
        //     this->temporary_entity_binding_map_.erase(this->temporary_entity_binding_map_.begin(), this->temporary_entity_binding_map_.end());
        // }
        this->temporary_entity_binding_map_[entity_name] = binding;
    }
    else
    {
        /* TODO Handle existing entity binding */

        ocall_print_string("set_temporary_entity_binding: existing entity binding", __FILE__, __LINE__);
    }
}

void RuleEvaluator::set_temporary_entity_set_binding(const string &entity_set_id, const Json &binding)
{
    // update temporary entity set binding map
    if (this->temporary_entity_set_binding_map_.find(entity_set_id) ==
        this->temporary_entity_set_binding_map_.end())
    {
        // TODO (Xufei) temporary_entity_set_binding_map_ should have a upper limit
        // if (this->temporary_entity_set_binding_map_.size() > 50) {
        //     this->temporary_entity_set_binding_map_.erase(this->temporary_entity_set_binding_map_.begin(), this->temporary_entity_set_binding_map_.end());
        // }
        this->temporary_entity_set_binding_map_[entity_set_id] = binding;
    }
    else
    {
        /* TODO Handle existing entity set binding */

        ocall_print_string("set_temporary_entity_set_binding: existing entity set binding", __FILE__, __LINE__);
    }
}

void RuleEvaluator::clear_temporary_entity_binding_map()
{
    this->temporary_entity_binding_map_.clear();
}

void RuleEvaluator::clear_temporary_entity_set_binding_map()
{
    this->temporary_entity_set_binding_map_.clear();
}

// void RuleEvaluator::set_rule_evaluation_result(string rule_id, bool evaluation_result)
// {
//     // update rule evaluation result map
//     if (this->rule_evaluation_result_map_.find(rule_id) ==
//         this->rule_evaluation_result_map_.end())
//     {
//         this->rule_evaluation_result_map_[rule_id] = evaluation_result;
//     }
//     else
//     {
//         /* TODO Handle existing rule evaluation result */

//         ocall_print_string("set_rule_evaluation_result: existing rule evaluation result");
//     }

//     // update overall evaluation result
//     this->overall_evaluation_result_ &= evaluation_result;
// }

/* Overridden Visitor Member Functions */

antlrcpp::Any RuleEvaluator::visitEntityDecl(RuleParser::EntityDeclContext *context)
{
    ocall_print_string(("enter visitEntityDecl: " + context->getText()).c_str(), __FILE__, __LINE__);

    // check if we encounter a set entity declaration
    if (context->IS())
    {
        string set_name = context->entityName()->getText();

        auto composite_type_annotation = context->compositeType();
        auto set_type_annotation = composite_type_annotation->setType();

        // decide on set element type annotation
        if (set_type_annotation->IDENTIFIER())
        {
            // store new set declaration for later rule parsing use
            this->KeepTrackOfNewSet(set_name, set_type_annotation->IDENTIFIER()->getText());
        }
        else if (set_type_annotation->basicType())
        {
            // TODO currently, we do nothing for basic type element set
            this->KeepTrackOfNewSet(set_name, set_type_annotation->basicType()->getText());
        }
    }

    // TODO should we return nullptr?
    return nullptr;
}

antlrcpp::Any RuleEvaluator::visitBasicRule(RuleParser::BasicRuleContext *context)
{
    string rule_id = context->ruleName()->getText();
    // long start = 0, end = 0;
    // ocall_get_time(&start);

    ocall_print_string(("----------------------- start checking: " +
                        rule_id + " -----------------------\n")
                           .c_str(),
                       __FILE__, __LINE__);

    // traverse requested rule id list to decide whether we should check this rule
    for (const auto &target_rule_id : this->get_request_context()->get_rule_id_list())
    {
        // once current rule id is in the list of target rule ids (to be checked)
        if (rule_id == target_rule_id)
        {
            // basic rule result => rule statement list result
            vector<bool> rule_statement_result_list = this->visit(context->ruleStmtList()).as<vector<bool>>();

            // summarize each rule statement evaluation result as this basic rule result
            bool basic_rule_result = true; // rule defaults to satisfaction (i.e., true)
            for (const auto &evaluation_result : rule_statement_result_list)
            {
                basic_rule_result &= evaluation_result;

                // bypass traverse if basic rule dooms un-satisfied
                if (!basic_rule_result)
                {
                    break;
                }
            }

            // update rule evaluation result for request context
            string rule_name = context->ruleName()->getText();
            this->request_context_->set_rule_evaluation_result(rule_name, basic_rule_result);

            ocall_print_string((string("exit visitBasicRule with evaluation: ") +
                                string(basic_rule_result ? "true" : "false"))
                                   .c_str(),
                               __FILE__, __LINE__);

            ocall_print_string(("----------------------- end checking: " +
                                rule_id + " ----------------------- with result: " +
                                (basic_rule_result ? "SATISFIED" : "UNSATISFIED"))
                                   .c_str(),
                               __FILE__, __LINE__);

            return basic_rule_result;
        }
    }

    // ocall_get_time(&end);
    // ocall_push_metrics(kMT_HISTOGRAM, "part", "get_binding_file_time",
    //                    double(end - start) / 1000);
    ocall_print_string(("visitBasicRule: skip basic rule: " + rule_id).c_str(), __FILE__, __LINE__);

    // default to evalution result of true, i.e., satisfy compliance
    return true;
}

antlrcpp::Any RuleEvaluator::visitRuleStmtList(RuleParser::RuleStmtListContext *context)
{
    ocall_print_string(("enter visitRuleStmtList: " + context->getText()).c_str(), __FILE__, __LINE__);

    vector<bool> rule_statement_result_list;

    // rule statement list result => and[rule statement result]
    for (const auto &parse_tree : context->children)
    {
        bool evaluation_result = this->visit(parse_tree).as<bool>();
        rule_statement_result_list.push_back(evaluation_result);
    }

    return rule_statement_result_list;
}

antlrcpp::Any RuleEvaluator::visitRuleStmt(RuleParser::RuleStmtContext *context)
{
    ocall_print_string(("enter visitRuleStmt: " + context->getText()).c_str(), __FILE__, __LINE__);

    bool rule_statement_result;

    // decide on rule statement type
    if (context->simpleStmt())
    {
        ocall_print_string("visitRuleStmt: alterantive 1", __FILE__, __LINE__);

        // rule statement result => simple statement result
        rule_statement_result = this->visit(context->simpleStmt()).as<bool>();
    }
    else if (context->complexStmt())
    {
        ocall_print_string("visitRuleStmt: alterantive 2", __FILE__, __LINE__);

        // rule statement result => complex statement result
        rule_statement_result = this->visit(context->complexStmt()).as<bool>();
    }

    ocall_print_string((string("exit visitRuleStmt with evaluation: ") +
                        string(rule_statement_result ? "true" : "false"))
                           .c_str(),
                       __FILE__, __LINE__);

    return rule_statement_result;
}

antlrcpp::Any RuleEvaluator::visitSimpleStmt(RuleParser::SimpleStmtContext *context)
{
    ocall_print_string(("enter visitSimpleStmt: " + context->getText()).c_str(), __FILE__, __LINE__);

    bool simple_statement_result;

    // decide on simple rule statement type
    if (context->setStmt())
    {
        ocall_print_string("visitSimpleStmt: alterantive 1", __FILE__, __LINE__);

        // simple statement result => set statement result
        simple_statement_result = this->visit(context->setStmt()).as<bool>();
    }
    else if (context->relationStmt())
    {
        ocall_print_string("visitSimpleStmt: alterantive 2", __FILE__, __LINE__);

        // simple statement result => relation statement result
        simple_statement_result = this->visit(context->relationStmt()).as<bool>();
    }
    else if (context->logicalStmt())
    {
        ocall_print_string("visitSimpleStmt: alterantive 3", __FILE__, __LINE__);

        // simple statement result => logical statement result
        simple_statement_result = this->visit(context->logicalStmt()).as<bool>();
    }

    ocall_print_string(("exit visitSimpleStmt with evaluation: " +
                        string(simple_statement_result ? "true" : "false"))
                           .c_str(),
                       __FILE__, __LINE__);

    return simple_statement_result;
}

antlrcpp::Any RuleEvaluator::visitComplexStmt(RuleParser::ComplexStmtContext *context)
{
    // TODO redesign rule language to embrace complext rule statement

    // Re-use base visitor function for traversing child nodes
    return RuleParserBaseVisitor::visitComplexStmt(context);
}

antlrcpp::Any RuleEvaluator::visitSetStmt(RuleParser::SetStmtContext *context)
{
    ocall_print_string(("enter visitSetStmt: " + context->getText()).c_str() ,__FILE__, __LINE__);

    // set statement result = set expression result
    return this->visit(context->setExpr());
}

antlrcpp::Any RuleEvaluator::visitSetExpr(RuleParser::SetExprContext *context)
{
    ocall_print_string(("enter visitSetExpr: " + context->getText()).c_str() ,__FILE__, __LINE__);

    // decide on different alternatives
    if (context->L_PAREN())
    {
        ocall_print_string("visitSetExpr: alterantive 1" ,__FILE__, __LINE__);

        // (set expression result) => set expression result
        return this->visit(context->setExpr());
    }
    else if (context->selectorIdent())
    {
        ocall_print_string("visitSetExpr: alterantive 2" ,__FILE__, __LINE__);

        // evaluate on left value
        auto selector_identity = context->selectorIdent();

        string left_entity_name = selector_identity->entityName()->getText();
        string left_attribute_name = selector_identity->attributeName()->getText();

        // retrieve left value binding
        // NOTE for entity, we use its name as id
        auto left_entity = this->get_entity_binding(left_entity_name);

        // evaluate on right value
        string right_entity_name = context->entityName()->getText();

        // TODO assert right entity name refers to a set type entity

        // retrieve right value binding
        // NOTE for entity set, we use its corresponding rule context text as id
        auto right_entity_set = this->get_entity_set_binding(context->getText());

        ocall_print_string("visitSetExpr: start evaluate set expression",__FILE__, __LINE__);

        // evaluate on set expression accordingly
        // parse entity set binding
        assert(right_entity_set.is_array());
        auto right_entity_list = right_entity_set.array_items();

        ocall_print_string((string("retrieved element: ") + left_entity.dump() +
                            string(", entity set: ") + Json{right_entity_list}.dump())
                               .c_str(),__FILE__, __LINE__);


        // decide on set operator types

        if (context->SET_IN()) // A in B
        {
            return right_entity_list.size() > 0;
        }
        else if (context->SET_NOT_IN()) // A not in B
        {
            return right_entity_list.size() <= 0;
        } 

        ocall_print_string("Error! : Grammatical errors!",__FILE__, __LINE__);
        return false;
    }
}

antlrcpp::Any RuleEvaluator::visitRelationStmt(RuleParser::RelationStmtContext *context)
{
    ocall_print_string(("enter visitRelationStmt: " + context->getText()).c_str(),__FILE__, __LINE__);

    // relation statement result => relation expression result
    return this->visit(context->relationExpr());
}

antlrcpp::Any RuleEvaluator::visitRelationExpr(RuleParser::RelationExprContext *context)
{
    ocall_print_string(("enter visitRelationExpr: " + context->getText()).c_str(),__FILE__, __LINE__);

    // decide on different alternatives
    if (context->L_PAREN())
    {
        ocall_print_string("visitRelationExpr: alterantive 1",__FILE__, __LINE__);

        // (relation expression result) => relation expression result
        return this->visit(context->relationExpr());
    }
    else if (context->numberExpr().size())
    {
        ocall_print_string("visitRelationExpr: alterantive 2",__FILE__, __LINE__);

        // evaluate on child number expressions
        // NOTE here we evaluate number expression as double values
        vector<double> number_list;
        for (const auto &child_number_expression : context->numberExpr())
        {
            // collect each number expression result value
            number_list.push_back(this->visit(child_number_expression).as<double>());
        }

        ocall_print_string("start evaluate number expression",__FILE__, __LINE__);

        // evaluate on relation expression accordingly
        // NOTE we require children order = rule text element order
        bool satisfy_relation_expression = true;

        // traverse on each relation operator
        for (auto i = 1; i < context->children.size(); i += 2)
        {
            // next evaluated relation operator
            auto terminal_node = dynamic_cast<tree::TerminalNode *>(context->children[i]);
            assert(terminal_node); // this should be a terminal node, i.e., relation operator

            // TODO assert no number list index out of range

            double left_number = number_list[uint64_t((i - 1) / 2)];
            double right_number = number_list[uint64_t((i + 1) / 2)];

            // decide on relation operator types
            switch (terminal_node->getSymbol()->getType())
            {
            case RuleLexer::EQUALS: // A == B
                if (abs(left_number - right_number) > 1e-6)
                {
                    satisfy_relation_expression = false;
                }
                break;

            case RuleLexer::NOT_EQUALS: // A != B
                if (abs(left_number - right_number) < 1e-6)
                {
                    satisfy_relation_expression = false;
                }
                break;

            case RuleLexer::LESS_THAN: // A < B
                if (left_number - right_number > -1e-6)
                {
                    satisfy_relation_expression = false;
                }
                break;

            case RuleLexer::LESS_OR_EQUALS: // A <= B
                if (left_number - right_number > 1e-6)
                {
                    satisfy_relation_expression = false;
                }
                break;

            case RuleLexer::GREATER_THAN: // A > B
                if (left_number - right_number < 1e-6)
                {
                    satisfy_relation_expression = false;
                }
                break;

            case RuleLexer::GREATER_OR_EQUALS: // A >= B
                if (left_number - right_number < -1e-6)
                {
                    satisfy_relation_expression = false;
                }
                break;
            }

            // bypass further evaluation if relation expression dooms un-satisfied
            if (!satisfy_relation_expression)
            {
                ocall_print_string((string("exit visitRelationExpr with evaluation: ") +
                                    string(satisfy_relation_expression ? "true" : "false"))
                                       .c_str(),__FILE__, __LINE__);
                return satisfy_relation_expression;
            }
        }

        ocall_print_string((string("exit visitRelationExpr with evaluation: ") +
                            string(satisfy_relation_expression ? "true" : "false"))
                               .c_str(),__FILE__, __LINE__);
        return satisfy_relation_expression; // this expression evaluates to true
    }
}

antlrcpp::Any RuleEvaluator::visitNumberExpr(RuleParser::NumberExprContext *context)
{
    ocall_print_string(("enter visitNumberExpr: " + context->getText()).c_str(),__FILE__, __LINE__);

    // decide on different alternatives
    if (context->L_PAREN())
    {
        ocall_print_string("visitNumberExpr: alterantive 1",__FILE__, __LINE__);

        // (number expression result) => number expression result
        return this->visit(context->numberExpr()[0]);
    }
    else if (context->selectorIdent())
    {
        ocall_print_string("visitNumberExpr: alterantive 2",__FILE__, __LINE__);

        // retrieve entity binding for exact number value
        auto selector_identity = context->selectorIdent();

        ocall_print_string((string("selector indentity: ") +
                            selector_identity->getText())
                               .c_str(),__FILE__, __LINE__);

        string entity_name = selector_identity->entityName()->getText();
        string attribute_name = selector_identity->attributeName()->getText();

        ocall_print_string((string("retrieve entity binding from inside context: ") +
                            entity_name + string("[") + attribute_name + string("]"))
                               .c_str(),__FILE__, __LINE__);

        auto entity = this->get_entity_binding(entity_name);

        ocall_print_string((string("assert returned JSON object integrity: ") +
                            entity.dump())
                               .c_str(),__FILE__, __LINE__);

        // look up number value from entity binding
        // NOTE example returned entity JSON
        //      {"World": 100}
        // TODO add error handling
        assert(entity.is_object());
        assert(entity[entity_name][attribute_name].is_string());

        ocall_print_string("return entity binding value as context result",__FILE__, __LINE__);

        // number expression result => selector ideneity attribute value
        // return entity[entity_name][attribute_name].number_value();
        double number_value;
        this->ParseNumberLiteral(entity[entity_name][attribute_name].string_value(), &number_value);
        return number_value;
    }
    else if (context->DECIMAL_LIT() || context->DECIMAL_FLOAT_LIT())
    {
        ocall_print_string("visitNumberExpr: alterantive 3",__FILE__, __LINE__);

        // parse number literal to number value
        tree::TerminalNode *terminal_node =
            context->DECIMAL_LIT() ? context->DECIMAL_LIT() : context->DECIMAL_FLOAT_LIT();

        // number expression result => number literal value
        double number_value;
        this->ParseNumberLiteral(terminal_node, &number_value);
        return number_value;
    }
    else if (context->MULTIPLY() || context->DIVIDE() || context->MODULO())
    {
        ocall_print_string("visitNumberExpr: alterantive 4",__FILE__, __LINE__);

        // evaluate left child number expression
        auto left_number_expression = context->numberExpr()[0];
        double left_number = this->visit(left_number_expression).as<double>();

        // evaluate right child number expression
        auto right_number_expression = context->numberExpr()[2];
        double right_number = this->visit(right_number_expression).as<double>();

        // evaluate on number expression accordingly
        auto terminal_node = dynamic_cast<tree::TerminalNode *>(context->children[1]);
        assert(terminal_node); // this should be a terminal node, i.e., relation operator

        // decide on number operator types
        switch (terminal_node->getSymbol()->getType())
        {
        case RuleLexer::MULTIPLY: // A * B
            return left_number * right_number;

        case RuleLexer::DIVIDE: // A / B
            // divided number should not be zero
            // TODO change to a more descriptive way, e.g., display error info
            assert(abs(right_number) > 1e-6);
            return left_number / right_number;

        case RuleLexer::MODULO: // A % B
            // TODO both left and right number should be integers, employ check
            // TODO change to a more descriptive way, e.g., display error info
            return static_cast<double>(static_cast<int64_t>(left_number) % static_cast<int64_t>(right_number));
        }
    }
    else if (context->PLUS() || context->MINUS())
    {
        ocall_print_string("visitNumberExpr: alterantive 5",__FILE__, __LINE__);

        // evaluate left child number expression
        auto left_number_expression = context->numberExpr()[0];
        double left_number = this->visit(left_number_expression).as<double>();

        // evaluate right child number expression
        auto right_number_expression = context->numberExpr()[2];
        double right_number = this->visit(right_number_expression).as<double>();

        // evaluate on number expression accordingly
        auto terminal_node = dynamic_cast<tree::TerminalNode *>(context->children[1]);
        assert(terminal_node); // this should be a terminal node, i.e., relation operator

        // decide on number operator types
        switch (terminal_node->getSymbol()->getType())
        {
        case RuleLexer::PLUS: // A + B
            return left_number + right_number;

        case RuleLexer::MINUS: // A - B
            return left_number - right_number;
        }
    }
    else if (context->aggregationExpr())
    {
        ocall_print_string("visitNumberExpr: alterantive 6",__FILE__, __LINE__);

        // number expression result => aggregation expression value
        return this->visit(context->aggregationExpr());
    }
}

antlrcpp::Any RuleEvaluator::visitAggregationExpr(RuleParser::AggregationExprContext *context)
{
    ocall_print_string(("enter visitAggregationExpr: " + context->getText()).c_str(),__FILE__, __LINE__);

    // evaluate on child parse trees
    this->visitChildren(context);

    // decide on different alternatives
    if (context->ACCUMULATE())
    {
        ocall_print_string("visitAggregationExpr: alterantive 1",__FILE__, __LINE__);

        // (1) history accumulate result
        // NOTE: QueryEntitySet only handles history transaction (excluding pending one)

        // retrieve entity set value binding
        // NOTE for entity set, we use its corresponding rule context text as id
        auto entity_set = this->get_entity_set_binding(context->getText());
        assert(entity_set.is_array());

        // evaluate on accumulate aggregation expression
        double accumated_value = 0;
        auto entity_list = entity_set.array_items(); // [{"Transfer": {"Value": "20,000"}}]
        for (const auto &entity : entity_list)
        {
            // set temporary entity binding for number expression evaluation
            // NOTE: {"Transfer": {"Value": "20,000"}}
            string entity_name = entity.object_items().begin()->first; // e.g., "Transfer"
            this->set_temporary_entity_binding(entity_name, entity);   // {"Transfer": {"Value": "20,000"}}

            // evaluate on child number expression with temporary entity binding
            accumated_value += this->visit(context->numberExpr()).as<double>();

            // reset entity binding to before number expression evaluation
            this->clear_temporary_entity_binding_map();
        }

        ocall_print_string((string("visitAggregationExpr: accumated_value for history: ") +
                            to_string(accumated_value))
                               .c_str(),__FILE__, __LINE__);

        // (2) pending transaction

        // retrieve entity for pending transaction
        // auto entity = this->get_entity_binding(context->getText()); // {"Transfer": {"Value": "20,000"}}
        assert(context->entityName());
        auto entity = this->get_entity_binding(context->entityName()->getText()); // {"Transfer": {"Value": "20,000"}}
        assert(entity.is_object());

        // count pending transaction entity to arrive at final result
        string entity_name = entity.object_items().begin()->first; // e.g., "Transfer"
        assert(entity[entity_name].is_object());                   // {"Transfer": {"Value": "20,000"}}

        // set temporary entity binding for number expression evaluation
        this->set_temporary_entity_binding(entity_name, entity);

        // evaluate on child number expression with temporary entity binding
        accumated_value += this->visit(context->numberExpr()).as<double>();

        // reset entity binding to before number expression evaluation
        this->clear_temporary_entity_binding_map();

        ocall_print_string((string("visitAggregationExpr: accumated_value overall: ") +
                            to_string(accumated_value))
                               .c_str(),__FILE__, __LINE__);

        // aggregation expression reulst = accumulate[number expression]
        return accumated_value;
    }
    else if (context->COUNT())
    {
        ocall_print_string("visitAggregationExpr: alterantive 2",__FILE__, __LINE__);

        // (1) history count result
        // NOTE: QueryEntitySet only handles history transaction (excluding pending one)

        // retrieve entity set value binding
        // NOTE for entity set, we use its corresponding rule context text as id
        auto entity_set = this->get_entity_set_binding(context->getText()); // [{"Transfer": {"Value": "20,000"}}]

        // evaluate on aggregation expression
        assert(entity_set.is_array());

        uint64_t number_count = entity_set.array_items().size();

        // (2) pending transaction

        // decide on whether where constraint exists
        if (context->WHERE())
        {
            // TODO we assume where boolean expression can only be relation expression
            // assert(context->booleanExpr());
            // assert(context->booleanExpr()->relationExpr());

            // decide on child relation expression result
            bool where_constraint_result = this->visit(context->booleanExpr()).as<bool>();
            if (where_constraint_result)
            {
                number_count += 1;
            }
        }
        else
        {
            number_count += 1; // pending transaction counts for this case
        }

        // aggregation expresion result => count(entity set)
        // return double(entity_set.array_items().size());
        return static_cast<double>(number_count);
    }

    /* this should never be reached */
    assert(false);
}

antlrcpp::Any RuleEvaluator::visitBooleanExpr(RuleParser::BooleanExprContext *context)
{
    ocall_print_string(("enter visitBooleanExpr: " + context->getText()).c_str(),__FILE__, __LINE__);

    // decide on different alternatives
    if (context->L_PAREN())
    {
        ocall_print_string("visitBooleanExpr: alterantive 1",__FILE__, __LINE__);

        // (boolean expression result) => boolean expression result
        return this->visit(context->booleanExpr());
    }
    else if (context->BOOLEAN_LIT())
    {
        ocall_print_string("visitBooleanExpr: alterantive 2",__FILE__, __LINE__);

        // parse boolean literal to boolean value
        tree::TerminalNode *terminal_node = context->BOOLEAN_LIT();

        // boolean expression result => boolean literal value
        bool boolean_value;
        this->ParseBooleanLiteral(terminal_node, &boolean_value);
        return boolean_value;
    }
    else if (context->selectorIdent())
    {
        ocall_print_string("visitBooleanExpr: alterantive 3",__FILE__, __LINE__);

        // retrieve entity binding for exact boolean value
        auto selector_identity = context->selectorIdent();

        string entity_name = selector_identity->entityName()->getText();
        string attribute_name = selector_identity->attributeName()->getText();

        auto entity = this->get_entity_binding(entity_name);

        // look up boolean value from entity binding
        assert(entity.is_object());
        assert(entity[entity_name][attribute_name].is_string());

        // boolean expression result => selector ideneity attribute value
        // return entity[attribute_name].bool_value();
        bool boolean_value;
        this->ParseBooleanLiteral(entity[entity_name][attribute_name].string_value(), &boolean_value);
        return boolean_value;
    }
    else if (context->setExpr())
    {
        ocall_print_string("visitBooleanExpr: alterantive 4",__FILE__, __LINE__);

        // boolean expression result => set expression result
        return this->visit(context->setExpr());
    }
    else if (context->relationExpr())
    {
        ocall_print_string("visitBooleanExpr: alterantive 5",__FILE__, __LINE__);

        // boolean expression result => relation expression result
        return this->visit(context->relationExpr());
    }
    else if (context->logicalExpr())
    {
        ocall_print_string("visitBooleanExpr: alterantive 6",__FILE__, __LINE__);

        // boolean expression result => logical expression result
        return this->visit(context->logicalExpr());
    }

    /* this should never be reached */
    assert(false);
}

antlrcpp::Any RuleEvaluator::visitLogicalStmt(RuleParser::LogicalStmtContext *context)
{
    ocall_print_string(("enter visitLogicalStmt: " + context->getText()).c_str(),__FILE__, __LINE__);

    // logical statement result => logical expression result
    return this->visit(context->logicalExpr());
}

antlrcpp::Any RuleEvaluator::visitLogicalExpr(RuleParser::LogicalExprContext *context)
{
    ocall_print_string(("enter visitLogicalExpr: " + context->getText()).c_str(),__FILE__, __LINE__);

    // decide on different alternatives
    if (context->LOGICAL_NOT())
    {
        ocall_print_string("visitLogicalExpr: alterantive 1 and 2",__FILE__, __LINE__);

        // retrieve and parse each BOOLEAN_LIT or BOOLEAN_LIT child node
        vector<bool> boolean_value_list;
        this->ParseBooleanExpression(context->children, &boolean_value_list);

        // TODO add error handling
        assert(boolean_value_list.size() == 1);

        // logical expression result => not boolean expression result
        return !boolean_value_list[0];
    }
    else if (context->LOGICAL_AND())
    {
        ocall_print_string("visitLogicalExpr: alterantive 3 and 4",__FILE__, __LINE__);

        // retrieve and parse each BOOLEAN_LIT or BOOLEAN_LIT child node
        vector<bool> boolean_value_list;
        this->ParseBooleanExpression(context->children, &boolean_value_list);

        // TODO add error handling
        assert(boolean_value_list.size() == 2);

        // logical expression result => left boolean result && right boolean result
        return boolean_value_list[0] && boolean_value_list[1];
    }
    else if (context->LOGICAL_OR())
    {
        ocall_print_string("visitLogicalExpr: alterantive 5 and 6",__FILE__, __LINE__);

        // retrieve and parse each BOOLEAN_LIT or BOOLEAN_LIT child node
        vector<bool> boolean_value_list;
        this->ParseBooleanExpression(context->children, &boolean_value_list);

        // TODO add error handling
        assert(boolean_value_list.size() == 2);

        // logical expression result => left boolean result || right boolean result
        return boolean_value_list[0] || boolean_value_list[1];
    }

    /* this should never be reached */
    assert(false);
}

antlrcpp::Any RuleEvaluator::visitIfStmt(RuleParser::IfStmtContext *context)
{
    ocall_print_string(("enter visitIfStmt: " + context->getText()).c_str(),__FILE__, __LINE__);

    // evaluate on if condition
    bool boolean_expression = this->visit(context->booleanExpr()).as<bool>();

    // decide on if condition result
    if (boolean_expression)
    {
        // evaluate on if child rule statement list
        vector<bool> rule_statement_result_list = this->visit(context->ruleStmtList()[0]).as<vector<bool>>();

        // evaluate on if statement
        bool satisfy_if_statement = true;
        for (const auto &rule_statement_result : rule_statement_result_list)
        {
            satisfy_if_statement &= rule_statement_result;

            // bypass traverse if basic rule dooms un-satisfied
            if (!satisfy_if_statement)
            {
                break;
            }
        }

        // if statement result = if[rule statement list]
        return satisfy_if_statement;
    }
    else if (context->ELSE())
    {
        // decide on further else block
        if (context->ifStmt())
        {
            // if statement result = else[if statement list]
            return this->visit(context->ifStmt());
        }
        else
        {
            // evaluate on else child rule statement list
            vector<bool> rule_statement_result_list = this->visit(context->ruleStmtList()[1]).as<vector<bool>>();

            // evaluate on if statement
            bool satisfy_if_statement = true;
            for (const auto &rule_statement_result : rule_statement_result_list)
            {
                satisfy_if_statement &= rule_statement_result;

                // bypass traverse if basic rule dooms un-satisfied
                if (!satisfy_if_statement)
                {
                    break;
                }
            }

            // if statement result = else[rule statement list]
            return satisfy_if_statement;
        }
    }

    /* this should never be reached */
    assert(false);
}
