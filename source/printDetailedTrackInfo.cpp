#include <iostream>	// for basic in and output on screen
#include <list>
#include "ClassTrack.h"

int showAllTracks( std::list< Track >& AllTracks );
void ClearScreen();

int printDetailedTrackInfo ( Track detailedTrack, std::list< Track >& AllTracks ){
	std::cout << " Showing detailed information on Track " << detailedTrack.getTitle()<<":\n";
	std::cout << " Title: \t " << detailedTrack.getTitle() << "\n";

	std::list< Waypoint > TempWaypoints = detailedTrack.getWaypoints();
	std::list< Waypoint >::iterator itWaypoint;
	for ( itWaypoint = TempWaypoints.begin(); itWaypoint != std::prev(TempWaypoints.end()); itWaypoint++){
		std::cout << itWaypoint->getTitle() << "\t\t";
	}
	std::cout << std::prev(TempWaypoints.end())->getTitle() << "\n";
	for ( itWaypoint = TempWaypoints.begin(); itWaypoint != std::prev(TempWaypoints.end()); itWaypoint++){
		std::cout << itWaypoint->getDistance() << "\t\t";
	}
	std::cout << std::prev(TempWaypoints.end())->getDistance() << "\n";


	std::cout << " Heading Back to Track overview.\n";
	ClearScreen();
	showAllTracks( AllTracks );
	return 1;
}
