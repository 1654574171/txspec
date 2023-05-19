// LICENSE: Apache 2.0
// https://github.com/RegTech-OXH/compliance-engine
//
// Author:
//
// This file implements EntityCollector class.

#include "EntityCollector.h"

using namespace std;
using namespace antlr4;
using namespace rule_check_proto;

/* Constructors and Destructors */
EntityCollector::EntityCollector(RequestContext *const request_context)
{
    this->request_context_ = request_context;
}

EntityCollector::~EntityCollector()
{
    // De-allocate collected entity pointers
    for (const auto &entity_pair : this->entity_map_)
    {
        delete entity_pair.second;
    }
    this->entity_map_.clear();

    // De-allocate collected eneity set pointers
    for (const auto &entity_set : this->entity_set_list_)
    {
        delete entity_set;
    }
    this->entity_set_list_.clear();
}

/* Data Member Getters */

const vector<Entity> EntityCollector::get_entity_list() const
{
    vector<Entity> entity_list;
    for (const auto &entity_pair : this->entity_map_)
    {
        entity_list.push_back(*(entity_pair.second));
    }

    return entity_list;
}

const vector<EntitySet> EntityCollector::get_entity_set_list() const
{
    vector<EntitySet> entity_set_list;
    for (const auto &entity_set : this->entity_set_list_)
    {
        entity_set_list.push_back(*entity_set);
    }

    return entity_set_list;
}

RequestContext *const EntityCollector::get_request_context()
{
    return this->request_context_;
}

const string &EntityCollector::get_set_element_name(const string &set_name)
{
    return this->set_element_map_[set_name];
}

/* Internal Handler Member Functions */

RuleEnclaveStatus EntityCollector::KeepTrackOfNewSet(const string &set_name, const string &element_name)
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

// // mark entire entity as request needed, omit specific attribute name
// // NOTE: entity with empty attribute = request the whole entity with entire attributes
// void EntityCollector::KeepTrackOfNewEntity(const string &entity_name)
// {
//     ocall_print_string((string("KeepTrackOfNewEntity: ") + entity_name).c_str(), __FILE__, __LINE__);

//     // decide on whether entity exists
//     if (this->entity_map_.find(entity_name) == this->entity_map_.end())
//     {
//         // NOTE: `entity` is deleted with `EntityCollector` destructor
//         Entity *entity = new Entity(entity_name);
//         // TODO (Xufei) entity_map_ should have a upper limit
//         // if (this->entity_map_.size() > 50) {
//         //     this->entity_map_.erase(this->entity_map_.begin(), this->entity_map_.end());
//         // }
//         this->entity_map_[entity_name] = entity;
//     }
//     else
//     {
//         Entity *entity = this->entity_map_[entity_name];
//         // entity->get_attribute_set().clear();
//         entity->clearAttributes();
//     }
// }

// mark entity as request needed, only concern specific attribute name
void EntityCollector::KeepTrackOfNewEntityAttribute(const string &entity_name, const string &attribute_name)
{
    ocall_print_string((string("KeepTrackOfNewEntityAttribute: ") +
                        entity_name + string("[") +
                        attribute_name + string("]")).c_str(), __FILE__, __LINE__);

    // decide on whether entity exists
    if (this->entity_map_.find(entity_name) == this->entity_map_.end())
    {
        // NOTE: `entity` is deleted with `EntityCollector` destructor
        Entity *entity = new Entity(entity_name);
        entity->addAttribute(attribute_name);
        this->entity_map_[entity_name] = entity;
    }
    else
    {
        Entity *entity = this->entity_map_[entity_name];
        entity->addAttribute(attribute_name);
    }
}

// Constraint EntityCollector::GetNewProvidedConstraint(string ref_entity_name, string ref_attribute_name)
void EntityCollector::GetNewProvidedConstraint(RuleParser::SelectorIdentContext *const context,
                                               Constraint *const constraint)
{
    // get selector identity from context
    string ref_entity_name = context->entityName()->getText();
    string ref_attribute_name = context->attributeName()->getText();

    // build provided type constraint
    // Constraint constraint;
    constraint->Clear();

    // NOTE: `provided` is managed and deleted by `constraint`
    Provided *provided_constraint = new Provided();

    provided_constraint->set_entity(ref_entity_name);
    provided_constraint->set_member(ref_attribute_name);

    constraint->set_allocated_provided(provided_constraint);
}

void EntityCollector::GetNewWithinConstraint(tree::TerminalNode *const terminal_node,
                                             Constraint *const constraint)
{
    // get time literal from terminal node
    string time_literal = terminal_node->getText();

    // NOTE: `within_constraint` is managed and deleted by `constraint`
    Within *within_constraint = new Within();

    // according to rule language design, time literal is splitted by "[ \t]+" white spaces
    char delimiter_blank = ' ';
    char delimiter_table = '\t';

    // we assume the given time literal is of struct: DECIMAL_LIT [ \t]+ TIME_UNIT
    uint64_t delimiter_blank__first_pos = time_literal.find_first_of(delimiter_blank);
    uint64_t delimiter_table_first_pos = time_literal.find_first_of(delimiter_blank);

    uint64_t delimiter_blank__last_pos = time_literal.find_last_of(delimiter_blank);
    uint64_t delimiter_table_last_pos = time_literal.find_last_of(delimiter_blank);

    // determine the first and last position of white spaces
    uint64_t first_pos = min(delimiter_blank__first_pos, delimiter_table_first_pos);
    uint64_t last_pos = max(delimiter_blank__last_pos, delimiter_table_last_pos);

    // retrieve decimal literal and time unit using known white space positions
    string decimal_literal = time_literal.substr(0, first_pos);
    string time_unit_literal = time_literal.substr(last_pos + 1);

    // set constraint attribute
    within_constraint->set_value(stoi(decimal_literal));
    // decide on time unit literal
    if (time_unit_literal == "day" || time_unit_literal == "days")
    {
        within_constraint->set_unit(Within::DAY);
    }
    else if (time_unit_literal == "hour" || time_unit_literal == "hours")
    {
        within_constraint->set_unit(Within::HOUR);
    }
    else if (time_unit_literal == "minute" || time_unit_literal == "minutes")
    {
        within_constraint->set_unit(Within::MINIT);
    }
    else if (time_unit_literal == "second" || time_unit_literal == "seconds")
    {
        within_constraint->set_unit(Within::SEC);
    }

    // construct constraint
    // Constraint constraint;
    constraint->Clear();
    constraint->set_allocated_within(within_constraint);
}

void EntityCollector::GetNewWhereConstraint(RuleParser::BooleanExprContext *const context,
                                            vector<Constraint> *const constraint_list)
{
    // decide on different alternatives
    if (context->L_PAREN())
    {
        // booleanExpr => ( booleanExpr )
        this->GetNewWhereConstraint(context->booleanExpr(), constraint_list);
    }
    else if (context->relationExpr())
    {
        auto relation_expression_context = context->relationExpr();

        // vector<Constraint> constraint_list;
        constraint_list->clear();

        uint64_t number_child_context = relation_expression_context->children.size();

        // traverse through each child context node to collect where constraint
        // i = start index of left number expression
        auto child_context_list = relation_expression_context->children;
        for (uint64_t i = 0; i < number_child_context - 2; i += 2)
        {
            // TODO add error handling
            //      we assume child contexts are well formed
            RuleParser::NumberExprContext *left_number_expression =
                dynamic_cast<RuleParser::NumberExprContext *>(child_context_list[i]); // numberExpr
            tree::TerminalNode *relation_operator =
                dynamic_cast<tree::TerminalNode *>(child_context_list[i + 1]); // operator
            RuleParser::NumberExprContext *right_number_expression =
                dynamic_cast<RuleParser::NumberExprContext *>(child_context_list[i + 2]); // numberExpr
            assert(left_number_expression != nullptr);
            assert(relation_operator != nullptr);
            assert(right_number_expression != nullptr);

            // construct a new where constraint
            Constraint constraint;

            // NOTE: `where_constraint` is managed and deleted by `constraint`
            Where *where_constraint = new Where();

            // TODO we assume that both number expresisons consist of either selector identity
            //      or number literal, and treat other alternatives as illegal currently
            assert(left_number_expression->selectorIdent() ||
                   left_number_expression->DECIMAL_LIT() ||
                   left_number_expression->DECIMAL_FLOAT_LIT());
            assert(right_number_expression->selectorIdent() ||
                   right_number_expression->DECIMAL_LIT() ||
                   right_number_expression->DECIMAL_FLOAT_LIT());

            // decide on different alternatives for left number expression
            if (left_number_expression->selectorIdent())
            {
                auto selector_identity = left_number_expression->selectorIdent();
                where_constraint->set_left_entity(selector_identity->entityName()->getText());
                where_constraint->set_left_member(selector_identity->attributeName()->getText());
            }
            else if (left_number_expression->DECIMAL_LIT())
            {
                double number_value;
                this->ParseNumberLiteral(left_number_expression->DECIMAL_LIT(), &number_value);

                // omit entity name if number expression is a number literal
                where_constraint->set_left_member(to_string(number_value));
            }
            else if (left_number_expression->DECIMAL_FLOAT_LIT())
            {
                double number_value;
                this->ParseNumberLiteral(left_number_expression->DECIMAL_FLOAT_LIT(), &number_value);

                // omit entity name if number expression is a number literal
                where_constraint->set_left_member(to_string(number_value));
            }

            // decide on different alternatives for opeartor
            switch (relation_operator->getSymbol()->getType())
            {
            case RuleLexer::EQUALS:
                where_constraint->set_operator_(Where_OPERATOR_EQ);
                break;

            case RuleLexer::NOT_EQUALS:
                where_constraint->set_operator_(Where_OPERATOR_NEQ);
                break;

            case RuleLexer::GREATER_THAN:
                where_constraint->set_operator_(Where_OPERATOR_GT);
                break;

            case RuleLexer::GREATER_OR_EQUALS:
                where_constraint->set_operator_(Where_OPERATOR_EGT);
                break;

            case RuleLexer::LESS_THAN:
                where_constraint->set_operator_(Where_OPERATOR_LT);
                break;

            case RuleLexer::LESS_OR_EQUALS:
                where_constraint->set_operator_(Where_OPERATOR_ELT);
                break;
            }

            // decide on different alternatives for right number expression
            if (right_number_expression->selectorIdent())
            {
                auto selector_identity = right_number_expression->selectorIdent();
                where_constraint->set_right_entity(selector_identity->entityName()->getText());
                where_constraint->set_right_member(selector_identity->attributeName()->getText());
            }
            else if (right_number_expression->DECIMAL_LIT())
            {
                double number_value;
                this->ParseNumberLiteral(right_number_expression->DECIMAL_LIT(), &number_value);

                // omit entity name if number expression is a number literal
                where_constraint->set_right_member(to_string(number_value));
            }
            else if (right_number_expression->DECIMAL_FLOAT_LIT())
            {
                double number_value;
                this->ParseNumberLiteral(right_number_expression->DECIMAL_FLOAT_LIT(), &number_value);

                // omit entity name if number expression is a number literal
                where_constraint->set_right_member(to_string(number_value));
            }

            // store collected new where constraint
            constraint.set_allocated_where(where_constraint);
            constraint_list->push_back(constraint);
        }
    }
}

void EntityCollector::GetNewWhereConstraint(RuleParser::SetExprContext *context,
                                            Constraint *const constraint)
{
    // decide on different alternatives
    if (context->L_PAREN())
    {
        this->GetNewWhereConstraint(context->setExpr(), constraint);
    }
    else
    {
        // Constraint constraint;
        // NOTE: `where_constraint` is managed and deleted by `constraint`
        Where *where_constraint = new Where();

        // left entity
        auto selector_identity = context->selectorIdent();

        // right entity, i.e., set entity
        // retrieve set's element from previous definition
        string set_entity_name = context->entityName()->getText();
        string set_element_name = this->get_set_element_name(set_entity_name);

        ocall_print_string(("GetNewWhereConstraint: " + set_entity_name +
                            "[" + set_element_name + "]").c_str(), __FILE__, __LINE__);

        // construct where constraint
        // left entity
        where_constraint->set_left_entity(selector_identity->entityName()->getText());
        where_constraint->set_left_member(selector_identity->attributeName()->getText());
        // middle operator
        where_constraint->set_operator_(Where_OPERATOR_EQ);
        // right entity
        where_constraint->set_right_entity(set_entity_name);
        where_constraint->set_right_member(set_element_name);

        // collected where constraint
        constraint->set_allocated_where(where_constraint);
    }
}

void EntityCollector::CollectEntitySetFromAggregationExpr(RuleParser::AggregationExprContext *const context)
{
    // entity set constraint list
    vector<Constraint> constraint_list;
    // prepare new entity set
    string entity_name = context->entityName()->getText();

    // decide on different constraints
    if (context->PROVIDED())
    {
        ocall_print_string("visitAggregationExpr: alterantive 1: provided constraint", __FILE__, __LINE__);

        // traverse each provided selector identity
        for (const auto &selector_identity : context->selectorIdent())
        {
            // build provided type constraint
            Constraint constraint;
            this->GetNewProvidedConstraint(selector_identity, &constraint);

            // append new constraint
            constraint_list.push_back(constraint);
        }
    }
    if (context->WHERE())
    {
        ocall_print_string("visitAggregationExpr: alterantive 2: where constraint", __FILE__, __LINE__);

        // TODO add error handling
        vector<Constraint> where_constraint_list;
        this->GetNewWhereConstraint(context->booleanExpr(), &where_constraint_list);

        // append where constraint list into overall constraint list
        constraint_list.insert(constraint_list.end(),
                               where_constraint_list.begin(),
                               where_constraint_list.end());
    }
    // if (context->BEFORE() || context->AFTER())
    // {
    //     ocall_print_string("visitAggregationExpr: alterantive 3: date constraint");

    //     // TODO deal with entities in date clause
    // }
    if (context->WITHIN())
    {
        ocall_print_string("visitAggregationExpr: alterantive 4: time constraint", __FILE__, __LINE__);

        // TODO parse time literal
        // TODO change within constraint proto
        Constraint constraint;
        this->GetNewWithinConstraint(context->TIME_LIT(), &constraint);

        // append new constraint
        constraint_list.push_back(constraint);
    }

    // NOTE: here we use rule context text as entity set id
    // NOTE: `entity_set` is deleted with `EntityCollector` destructor
    EntitySet *entity_set = new EntitySet(context->getText(), entity_name, constraint_list);
    if (context->ACCUMULATE() && context->numberExpr()->selectorIdent()) {
        auto selector = context->numberExpr()->selectorIdent();
        entity_set->add_attributes(selector->attributeName()->getText());
    }

    // store new collected entity set
    this->entity_set_list_.push_back(entity_set);
}

/* Overridden Visitor Member Functions */

antlrcpp::Any EntityCollector::visitEntityDecl(RuleParser::EntityDeclContext *context)
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
    } else {
        string entity_name = context->entityName()->getText();
        const auto& attributes = context->attributeList()->attributeDecl();
        for (auto attribute : attributes) {
            string attribute_name = attribute->attributeName()->getText();
            KeepTrackOfNewEntityAttribute(entity_name, attribute_name);
        }
    }

    // TODO should we return nullptr?
    return nullptr;
}

antlrcpp::Any EntityCollector::visitBasicRule(RuleParser::BasicRuleContext *context)
{

    string rule_id = context->ruleName()->getText();

    // traverse requested rule id list to decide whether we should check this rule
    for (const auto &target_rule_id : this->get_request_context()->get_rule_id_list())
    {
        // once current rule id is in the list of target rule ids (to be checked)
        if (rule_id == target_rule_id)
        {
            // Re-use base visitor function for traversing child nodes
            return RuleParserBaseVisitor::visitBasicRule(context);
        }
    }

    ocall_print_string(("visitBasicRule: skip basic rule: " + rule_id).c_str(), __FILE__, __LINE__);

    // TODO should we return nullptr?
    return nullptr;
}

antlrcpp::Any EntityCollector::visitSetExpr(RuleParser::SetExprContext *context)
{
    // TODO for erc20 blacklist rule, populate QueryEntitySet with provided Transfer.From

    // decide on different alternatives
    if (context->L_PAREN())
    {
        ocall_print_string("visitSetExpr: alterantive 1", __FILE__, __LINE__);
    }
    else if (context->selectorIdent())
    {
        ocall_print_string("visitSetExpr: alterantive 2", __FILE__, __LINE__);

        RuleEnclaveStatus status_code = RuleEnclaveStatus::kOK;

        // (1) collect entity and attribute
        auto selector_identity = context->selectorIdent();

        string ref_entity_name = selector_identity->entityName()->getText();
        string ref_attribute_name = selector_identity->attributeName()->getText();

        // update entity attribute list
        this->KeepTrackOfNewEntityAttribute(ref_entity_name, ref_attribute_name);

        // (2) collect entity set and constraint
        // TODO assert context->entityName is of type set, e.g., Transfer.From in Blacklist

        // entity set constraint list
        vector<Constraint> constraint_list;

        // build provided type constraint
        // Constraint constraint = this->GetNewProvidedConstraint(ref_entity_name, ref_attribute_name);
        // Constraint constraint = this->GetNewProvidedConstraint(selector_identity);
        Constraint constraint;
        this->GetNewWhereConstraint(context, &constraint);
        constraint_list.push_back(constraint);

        // prepare new entity set
        string entity_name = context->entityName()->getText();

        // NOTE: `entity_set` is deleted with `EntityCollector` destructor
        EntitySet *entity_set = new EntitySet(context->getText(), entity_name, constraint_list);

        // store new collected entity set
        this->entity_set_list_.push_back(entity_set);
    }

    // Re-use base visitor function for traversing child nodes
    return RuleParserBaseVisitor::visitSetExpr(context);
}

antlrcpp::Any EntityCollector::visitNumberExpr(RuleParser::NumberExprContext *context)
{
    ocall_print_string(("enter visitNumberExpr: " + context->getText()).c_str(), __FILE__, __LINE__);

    // decide on different alternatives
    if (context->L_PAREN())
    {
        ocall_print_string("visitNumberExpr: alterantive 1", __FILE__, __LINE__);
    }
    else if (context->selectorIdent())
    {
        ocall_print_string("visitNumberExpr: alterantive 2", __FILE__, __LINE__);

        // collect entity and attribute
        auto selector_identity = context->selectorIdent();

        string entity_name = selector_identity->entityName()->getText();
        string attribute_name = selector_identity->attributeName()->getText();

        // update entity attribute list
        this->KeepTrackOfNewEntityAttribute(entity_name, attribute_name);
    }
    else if (context->DECIMAL_LIT() || context->DECIMAL_FLOAT_LIT())
    {
        ocall_print_string("visitNumberExpr: alterantive 3", __FILE__, __LINE__);
    }
    else if (context->MULTIPLY() || context->DIVIDE() || context->MODULO())
    {
        ocall_print_string("visitNumberExpr: alterantive 4", __FILE__, __LINE__);
    }
    else if (context->PLUS() || context->MINUS())
    {
        ocall_print_string("visitNumberExpr: alterantive 5", __FILE__, __LINE__);
    }
    else if (context->aggregationExpr())
    {
        ocall_print_string("visitNumberExpr: alterantive 6", __FILE__, __LINE__);
    }

    // Re-use base visitor function for traversing child nodes
    return RuleParserBaseVisitor::visitNumberExpr(context);
}

antlrcpp::Any EntityCollector::visitAggregationExpr(RuleParser::AggregationExprContext *context)
{
    ocall_print_string(("enter visitAggregationExpr: " + context->getText()).c_str(), __FILE__, __LINE__);

    // decide on different alternatives
    if (context->ACCUMULATE())
    {
        ocall_print_string("visitAggregationExpr: alterantive 1", __FILE__, __LINE__);

        // employ internal handler to collect entity set
        this->CollectEntitySetFromAggregationExpr(context);
    }
    else if (context->COUNT())
    {
        ocall_print_string("visitAggregationExpr: alterantive 2", __FILE__, __LINE__);

        // employ internal handler to collect entity set
        this->CollectEntitySetFromAggregationExpr(context);
    }

    // Re-use base visitor function for traversing child nodes
    return RuleParserBaseVisitor::visitAggregationExpr(context);
}

antlrcpp::Any EntityCollector::visitBooleanExpr(RuleParser::BooleanExprContext *context)
{
    ocall_print_string(("enter visitBooleanExpr: " + context->getText()).c_str(), __FILE__, __LINE__);

    // decide on different alternatives
    if (context->L_PAREN())
    {
        ocall_print_string("visitBooleanExpr: alterantive 1", __FILE__, __LINE__);
    }
    else if (context->BOOLEAN_LIT())
    {
        ocall_print_string("visitBooleanExpr: alterantive 2", __FILE__, __LINE__);
    }
    else if (context->selectorIdent())
    {
        ocall_print_string("visitBooleanExpr: alterantive 3", __FILE__, __LINE__);

        // collect entity and attribute
        auto selector_identity = context->selectorIdent();

        string entity_name = selector_identity->entityName()->getText();
        string attribute_name = selector_identity->attributeName()->getText();

        // update entity attribute list
        this->KeepTrackOfNewEntityAttribute(entity_name, attribute_name);
    }
    else if (context->setExpr())
    {
        ocall_print_string("visitBooleanExpr: alterantive 4", __FILE__, __LINE__);
    }
    else if (context->relationExpr())
    {
        ocall_print_string("visitBooleanExpr: alterantive 5", __FILE__, __LINE__);
    }
    else if (context->logicalExpr())
    {
        ocall_print_string("visitBooleanExpr: alterantive 6", __FILE__, __LINE__);
    }

    // Re-use base visitor function for traversing child nodes
    return RuleParserBaseVisitor::visitBooleanExpr(context);
}

antlrcpp::Any EntityCollector::visitLogicalExpr(RuleParser::LogicalExprContext *context)
{
    ocall_print_string(("enter visitLogicalExpr: " + context->getText()).c_str(), __FILE__, __LINE__);

    // for logical expression, we only care about referenced identities
    for (const auto &selector_identity : context->selectorIdent())
    {
        string entity_name = selector_identity->entityName()->getText();
        string attribute_name = selector_identity->attributeName()->getText();

        // mark identity as needed for entity query
        this->KeepTrackOfNewEntityAttribute(entity_name, attribute_name);
    }

    // Re-use base visitor function for traversing child nodes
    return RuleParserBaseVisitor::visitLogicalExpr(context);
}
