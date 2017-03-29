//prints all avaiable Track names on screen. If requested further Details are printed.
#include <list>
#include <iostream>	// for basic in and output on screen
#include "ClassTrack.h"

int GetInput();
int printAllTracks( std::list< Track >& AllTracks );
int printDetailedTrackInfo ( Track detailedTrack, std::list< Track >& AllTracks );


int showAllTracks( std::list< Track >& AllTracks ){
	std::list<Track>::iterator it;
	Track detailedTrack;

	int printReturn =  printAllTracks( AllTracks );
	if ( printReturn == 0 ){
		return 0;
	}

	std::cout << "Do you want more information on one of the Tracks? Just enter the corresponding number!\nLeaving the input empty leads back to menu!\n>>";
	std::string reply;
	std::getline(std::cin, reply);
	/* reply = GetInput() - '0'; */
	if ( reply == "" ){
		return 1;
	}
	int j = 1;
	for (it = AllTracks.begin(); it != AllTracks.end(); it++){
		if( std::stoi(reply) == j ){
			detailedTrack = *it;
		}
		j++;
	}
	int detailedReturn = printDetailedTrackInfo( detailedTrack, AllTracks);
}
