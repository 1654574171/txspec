// LICENSE: Apache 2.0
// https://github.com/RegTech-OXH/compliance-engine
//
// Author:
//
// This file inplements methods for obtaining config.

#include "regex"
#include "compliance_engine_server/Config.h"

// template <typename T>
// void operator>>(const YAML::Node &node, T &i)
// {
//   i = node.as<T>();
// };
YAML::Node config;

// loadYamlFile is used to obtain configuration for yaml file.
uint32_t loadConfigFromYamlFile(std::string name)
{

  try
  {
    config = YAML::LoadFile(name);
  }
  catch (YAML::BadFile &e)
  {
    std::cout << "read config error!" << std::endl;
    return uint32_t(ConfigStatus::kConfigReadError);
  }
/*
  try
  {
    g_core_mysql_address = config["dataaccess"]["CORE_MYSQL_ADDRESS"].as<string>();
  }
  catch (YAML::TypedBadConversion<string> &e)
  {
    std::cout << "dataaccess:CORE_MYSQL_ADDRESS is NULL" << std::endl;
    return uint32_t(EngineStatus::kConfigReadError);
  }

  try
  {
    g_thread_pool_size = config["requestprocessor"]["THREAD_POOL_SIZE"].as<int32_t>();
  }
  catch (YAML::TypedBadConversion<int32_t> &e)
  {
    std::cout << "requestprocessor:THREAD_POOL_SIZE is NULL" << std::endl;
    return uint32_t(EngineStatus::kConfigReadError);
  }

  try
  {
    g_core_regulator_endpoint = config["requestprocessor"]["CORE_REGULATOR_ENDPOINT"].as<string>();
  }
  catch (YAML::TypedBadConversion<string> &e)
  {
    std::cout << "requestprocessor:CORE_REGULATOR_ENDPOINT is NULL" << std::endl;
    return uint32_t(EngineStatus::kConfigReadError);
  }
  */
  return uint32_t(ConfigStatus::kOK);
}

// simple function to verify ipv4
bool CheckIPAddrIsValid(std::string str)
{
    std::regex reg("^((25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.){3}(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)$");
    return regex_match(str, reg);
}

// simple function to verify port
bool CheckPortIsValid(std::string str)
{
    std::regex reg("^([0-9]{1,4}|[1-5][0-9]{4}|6[0-4][0-9]{3}|65[0-4][0-9]{2}|655[0-2][0-9]|6553[0-5])$");
    return regex_match(str, reg);
}