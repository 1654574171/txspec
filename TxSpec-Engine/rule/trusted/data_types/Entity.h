#pragma once

#include <set>
#include <string>

#include "EntityType.h"
#include "common/json_lib/json11.hpp"

// using namespace std;

class Entity : public EntityType {
   private:
    std::string id_;  // we use entity name as its id, i.e., id_ = name_
    std::string name_;
    std::set<std::string> attribute_set_;
    std::set<std::string> constraints_;

   public:
    Entity(const std::string &name);
    Entity() = default;
    ~Entity() = default;

    /* Data Member Getters */

    const std::string &get_id() const;
    const std::string &get_name() const override;
    const std::set<std::string>& get_attribute_set() const override;
    const std::set<std::string> &get_constraints_set() const;

    const std::string toJSONString() const;

    void addAttribute(const std::string &attribute_name);
    void addConstraint(const std::string &attribute_name);
    void clearAttributes();

    friend bool operator<(const Entity &left, const Entity &right);
    friend bool operator==(const Entity &left, const Entity &right);

    /* debug */
    std::string dump();
};