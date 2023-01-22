#ifndef REDIS_H
#define REDIS_H

#include <iostream>
#include <list>
#include "helpfunctions.h"
//#include "readwrite.h"
#include <nlohmann/json.hpp>

void execute(std::string&);
void set(const std::vector<std::string>&);
std::string get(const std::vector<std::string>&);
void lpush(const std::vector<std::string>&);
void rpush(const std::vector<std::string>&);
int llen(const std::vector<std::string>&);
void hset(const std::vector<std::string>&);
std::string hget(const std::vector<std::string>&);

#endif REDIS_H // REDIS_H