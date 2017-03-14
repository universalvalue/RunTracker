#include "RunningAppFunctions.h"

int writeRunsOverwriteCheck( std::list<Run> &RunList ){
	std::cout << "\nDo you want to write the " << RunList.size() << " records in memory to file (y/n) ? " << std::flush;
	int reply = GetInput(); 
	if( reply != 'Y' ){
		std::cout << "Aborted ... " << std::flush;
		return 0;
	}
}
