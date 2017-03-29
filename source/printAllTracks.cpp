//prints all avaiable Track names on screen. If requested further Details are printed.
#include <list>
#include <iostream>	// for basic in and output on screen
#include "ClassTrack.h"

int printAllTracks( std::list< Track >& AllTracks ){
	std::list<Track>::iterator it;
	int i = 1;
	std::cout << " These Tracks are currently in memory:\n";
	for (it = AllTracks.begin(); it != AllTracks.end(); it++){
		std::cout << i <<":\t"<< it->getTitle()<<"\n";
		i++;
	}
	if ( i == 1 ){
		std::cout << "ATTENTION!\nThere are no tracks in memory...\nPlease add first a track before using this function!\nReturning to Menu...\n";
		return 0;
	}
	return 1;

}
