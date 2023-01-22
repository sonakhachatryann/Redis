#include "redis.h"

int main() {
	std::string command;
	std::cin >> command;
	execute(command);
	return 0;
}
