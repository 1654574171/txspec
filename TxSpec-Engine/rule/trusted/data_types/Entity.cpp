#include "Entity.h"

using namespace std;
using namespace json11;

/* Constructors and Destructors */

Entity::Entity(const string &name) {
    this->id_ = name;  // we use entity name as its id as well
    this->name_ = name;
}

/* Data Member Getters */

const string &Entity::get_id() const { return this->id_; }

const string &Entity::get_name() const { return this->name_; }

const set<string>& Entity::get_attribute_set() const {
    return this->attribute_set_;
}

const set<string> &Entity::get_constraints_set() const {
    return this->constraints_;
}

const string Entity::toJSONString() const {
    Json entity_json = Json::object{{"id", this->id_},
                                    {"name", this->name_},
                                    {"attributes", this->attribute_set_}};

    return entity_json.dump();
}

void Entity::addAttribute(const string &attribute_name) {
    this->attribute_set_.insert(attribute_name);
}

void Entity::clearAttributes() { this->attribute_set_.clear(); }

void Entity::addConstraint(const string &c) { this->constraints_.insert(c); }

/* Operator Overloadings */

bool operator<(const Entity &left, const Entity &right) {
    return left.name_ < right.name_;
    // return left.id_ < right.id_;
}

bool operator==(const Entity &left, const Entity &right) {
    return left.name_ == right.name_;
    // return left.id_ == right.id_;
}

string Entity::dump() {
    string entity_string;

    entity_string += this->get_name();
    entity_string += "[";
    uint64_t counter = 0;
    for (const auto &attribute : this->get_attribute_set()) {
        if (counter++ > 0) {
            entity_string += ", ";
        }
        entity_string += attribute;
    }

    entity_string += "]";
    return entity_string;
}