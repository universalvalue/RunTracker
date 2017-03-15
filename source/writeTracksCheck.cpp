#include "RunningAppFunctions.h"

int writeTracksCheck(std::list< Track > &TrackList, const char TRACKS_DATA[]){
	std::ofstream OutFile( TRACKS_DATA ); 

	if ( !OutFile ){
		std::cout << "Error attempting to access track database ... \n"<< "(Perhaps it dosen't exist yet?)" << std::endl;
		std::cout << "Do you want to create a new database file (y/N)? (The name will be TracksData.txt) \n" << std::endl;
		int reply = GetInput(); 
		if( reply != 'Y' ){
			std::cout << "No new database created! Writing aborted ... " << std::flush;
			return -3;
		}
		std::cout << "Creating new database file ... \n";
		/* return 0;          // report error condition ... */
	}
	else if ( TrackList.size() ){ // i.e. if not == 0 ...
		std::cout << "\nDo you want to write the " << TrackList.size() << " records in memory to file (y/N) ? " << std::flush;
		int reply = GetInput(); 
		if( reply != 'Y' ){
			std::cout << "Aborted ... " << std::flush;
			return -2;
		}
	}
	else {
		std::cout << "\n No data to write in list of tracks?!\n"<<std::flush;
		return -1;
	}
	return 0;

}
