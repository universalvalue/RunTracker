#include <iostream>	// for basic in and output on screen
#include <list>
#include "ClassRun.h"

int showAllRuns( std::list< Run >& AllRuns );
void ClearScreen();

int printDetailedRunInfo ( Run detailedRun, std::list< Run >& AllRuns ){
	std::cout << " Showing detailed information on Run on " << detailedRun.getDate()<<":\n";
	std::cout << " Date: \t " << detailedRun.getDate() << "\n";
	std::cout << " Distance:\t " << detailedRun.getDistance() << "\n";
	std::cout << " Time:\t " << detailedRun.getTime() << "\n";
	std::cout << " Track:\t " << detailedRun.getTrack().getTitle() << "\n" ;
	for ( int j = 0; j < detailedRun.getTrackTimes().size() - 1; j++){
		std::cout << detailedRun.getTrackTimes()[j] << "\t";
	}
	std::cout << detailedRun.getTrackTimes()[detailedRun.getTrackTimes().size() -1] << "\n";

	std::cout << " Heading Back to Run overview.\n";
	ClearScreen();
	showAllRuns( AllRuns );
	return 1;
}
