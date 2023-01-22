#include "redis.h"
#include "helpfunctions.cpp"

using json = nlohmann::json;
json string;
json list;
json hash;
const std::string EMPTY = "nil";

void execute(std::string& command_line) {
    std::vector<std::string> parsed = split_to_words(command_line);
    if (*parsed.begin() == command[CommandNames::SET]) {
        set(parsed);
    }
    else if (*parsed.begin() == command[CommandNames::GET]) {
        get(parsed);
    }
    else if (*parsed.begin() == command[CommandNames::LPUSH]) {
        lpush(parsed);
    }       
    else if (*parsed.begin() == command[CommandNames::RPUSH]) {
        rpush(parsed);
    }
    else if (*parsed.begin() == command[CommandNames::LLEN]) {
        llen(parsed);
    }
    else if (*parsed.begin() == command[CommandNames::HSET]) {
        hset(parsed);
    }
    else if (*parsed.begin() == command[CommandNames::HGET]) {
        hget(parsed);
    }
    else {
        std::cout << "The command was not found." << std::endl; 
    }
}

void set(const std::vector<std::string>& line) {
    auto key = line.begin();
    auto value = line.begin() + 1;
    for (auto i : string) {
        if (*key == i.begin().key()) {
            i.begin().value() = *value;
        }
    }
    json object;
    object[*key] = *value;
    string.push_back(object);
}

std::string get(const std::vector<std::string>& line) {
    auto key = line.begin();
    auto value = line.begin() + 1;
    for (auto i : string) {
        if (*key == i.begin().key()) {
            return i.begin().value();
        }
    }
    return EMPTY;
}

void lpush(const std::vector<std::string>& line) {
    std::string key = *line.begin();
    if (list.find(key) != list.end()) {
        for (auto i = line.begin() + 1; i != line.end(); ++i) {
            list[key].begin().value().insert(list[key].begin().value().begin(), *i);
        }
        return;
    }
    std::list<std::string> _list;
    for (auto i = line.begin() + 1; i != line.end(); ++i) {
        _list.push_front(*i);
    }
    list[key].push_back(_list);
}

void rpush(const std::vector<std::string>& line) {
    std::string key = *line.begin();
    if (list.find(key) != list.end()) {
        for (auto i = line.begin() + 1; i != line.end(); ++i) {
            list[key].begin().value().push_back(*i);
        }
        return;
    }
    std::list<std::string> _list;
    for (auto i = line.begin() + 1; i != line.end(); ++i) {
        _list.push_back(*i);
    }
    list[key].push_back(_list);
}

int llen(const std::vector<std::string>& line) {
    std::string key = *line.begin();
    for (auto i : list) {
        if (i.begin().key() == key) {
            return i.size();
        }
    }
    return 0;
}

void hset(const std::vector<std::string>& line) {
    std::string hash_name = *line.begin();
    json push_array;
    for (auto i = line.begin() + 1; i < line.end(); i += 2) {
        auto j = hash[hash_name].begin();
        for (; j < hash[hash_name].end(); ++j) {
            if ((*j).begin().key() == *i) {
                auto it = j;
                break;
            }
        }
        if (j != hash[hash_name].end()) {
            (*j).begin().value() = *(i + 1);
            continue;
        }
        push_array[*i] = *(i + 1);
        hash[hash_name].push_back(push_array);
        push_array.clear();
    }
}

std::string hget(const std::vector<std::string>& line) {
    auto hash_name = line.begin();
    auto key = line.begin() + 1;
    for (auto i : hash) {
        if (*hash_name == i.begin().key()) {
            return i.begin().value();
        }
    }
    return EMPTY;
}