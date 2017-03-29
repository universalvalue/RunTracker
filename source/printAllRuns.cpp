//prints all avaiable Run names on screen. If requested further Details are printed.
#include <list>
#include <iostream>	// for basic in and output on screen
#include "ClassRun.h"

int printAllRuns( std::list< Run >& AllRuns ){
	std::list<Run>::iterator it;
	int i = 1;
	std::cout << " These Runs are currently in memory:\n";
	for (it = AllRuns.begin(); it != AllRuns.end(); it++){
		std::cout << i <<":\t"<< it->getDate()<<"\t" << it->getTrack().getTitle() << "\t"  << it->getTime() << "\t" << it->getDistance() << "\t" << it->getSpeed() << "\n";
		i++;
	}
	if ( i == 1 ){
		std::cout << "ATTENTION!\nThere are no runs in memory...\nPlease add first a run before using this function!\nReturning to Menu...\n";
		return 0;
	}
	return 1;

}
