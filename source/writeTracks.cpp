#include "RunningAppFunctions.h"
#include <iostream>
#include <fstream>

int writeTracks (std::list< Track > &TrackList, const char TRACKS_DATA[]){
	std::ofstream OutFile( TRACKS_DATA ); 

	int i = 0;
	std::list< Track >::iterator it; 
	for( it = TrackList.begin(); it != TrackList.end(); ++it ) //first get 1st string (up to ',')
	{
		OutFile << it->getTitle() << "\n" ;
		std::list< Waypoint > TempWaypoints = it->getWaypoints();
		std::list< Waypoint >::iterator itWaypoint;
		for ( itWaypoint = TempWaypoints.begin(); itWaypoint != std::prev(TempWaypoints.end()); itWaypoint++){
			OutFile << itWaypoint->getTitle() << ",";
		}
		OutFile << std::prev(TempWaypoints.end())->getTitle() << "\n";
		for ( itWaypoint = TempWaypoints.begin(); itWaypoint != std::prev(TempWaypoints.end()); itWaypoint++){
			OutFile << itWaypoint->getDistance() << ",";
		}
		OutFile << std::prev(TempWaypoints.end())->getDistance() << "\n";
		++i;
	}
	OutFile.close();

	if( i == (int)TrackList.size() ){
		std::cout << "\nAll " << i << " records filed ok." << std::endl;
	}
	else{
		std::cout << "\nOnly " << i << " of " << TrackList.size()	<< " records were written ..." << std::endl;
	}

	return i; // report success? ... i.e. return the record count ... w
}
