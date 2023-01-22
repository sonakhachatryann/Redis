#include "helpfunctions.h"

std::vector<std::string> split_to_words(std::string input) {
	std::vector<std::string> result;
	unsigned int i{};
	unsigned int j{};
	result.push_back("");
	while (i < input.size()) {
		while (input[i] != ' ' && input[i] != '\0') {
			result[j].push_back(input[i]);
			++i;
			if (input[i] == ' ') {
				++j;
				result.push_back("");
				break;
			}
		}
		if (input[i] == '\0') {
			return result;
		}
		++i;
	}
	return result;
}