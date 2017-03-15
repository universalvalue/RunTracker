// adds Track records to end of end of list of Track records ... 'AllTracks'
// gets input from keyboard ...

#include <iostream>	// for basic in and output on screen
#include <list>
#include "ClassTrack.h"


int GetInput();
std::list< Track >::iterator ExistTrack( std::list< Track > &AllTracks, std::string trackname );

int AddTrack( std::list< Track >& AllTracks ){
	std::cout << "\nEnter an empty Track Name to exit this 'Input Loop' ..." << std::endl;

	int count = 0, reply;
	std::string trackname, Description, DistanceString;
	double Distance;
	std::map<std::string, double> trackinfo;

	for( ;; ){ // loop forever until break ...
		std::cout << "\nTrack Name   : ";
		std::getline(std::cin, trackname);
		if( ExistTrack( AllTracks, trackname ) != AllTracks.end() ){
			std::cout << "\nThat track title " << trackname << " already exits ... " << std::endl;
			continue; // from the top of the forever loop right now
		}

		if( trackname == ""){
			break;
		}

		std::cout << "\n How many waypoints do you want to enter? (max 9)";
		reply = GetInput() - '0';

		for (int i = 0; i < reply; i++){
			std::cout << "Name of waypoint : ";
			std::getline(std::cin, Description);

			std::cout << "Distance of waypoint : ";
			std::getline(std::cin, DistanceString);

			Distance = stod(DistanceString);

			trackinfo[Description] = Distance;
		}

		std::cout << "Add or Redo (a/R) ? ";
		reply=GetInput();
		if ( toupper(reply) != 'A' ){
			std::cout << "Aborted ..." << std::endl;
			continue;
		}
		// ok ... create and add this record to the end of the list ...
		AllTracks.push_back( Track( trackname, trackinfo) );
		++count;
		std::cout << "Added ..." << std::endl;
	}
	return count;
}
