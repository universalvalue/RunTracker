/* #include <iostream> */
#include "RunningAppFunctions.h"

int GetInput(){
	int reply;
	reply = std::toupper(std::cin.get());
	std::cin.clear();
	std::cin.ignore(256,'\n');   // ignore until space
	return reply;
}
