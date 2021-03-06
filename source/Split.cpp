#include "RunningAppFunctions.h"

std::vector<std::string> Split(const std::string &s, char delim) {
	std::vector<std::string> elems;
	std::stringstream ss;
	ss.str(s);
	std::string item;
	while (std::getline(ss, item, delim)) {
		elems.push_back(item);
	}

	return elems;
}
