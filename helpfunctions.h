#ifndef HELPFUNCTIONS_H
#define HELPFUNCTIONS_H

#include <vector>
#include <map>
#include <string>

enum class CommandNames {
    SET, 
    GET, 
    LPUSH, 
    RPUSH, 
    LLEN, 
    HSET, 
    HGET,
};

std::map<CommandNames, std::string> command = {
    {CommandNames::SET, "SET"}, 
    {CommandNames::GET, "GET"},
    {CommandNames::LPUSH, "LPUSH"},
    {CommandNames::RPUSH, "RPUSH"},
    {CommandNames::LLEN, "LLEN"},
    {CommandNames::HSET, "HSET"},
    {CommandNames::HGET, "HGET"}
};

std::vector<std::string> split_to_words(std::string);

#endif HELPFUNCTIONS_H  // HELPFUNCTIONS_H