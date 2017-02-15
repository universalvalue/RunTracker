#include "RunningAppFunctions.h" 

void ImportTracks(std::list<Track> &AllTracks, const char TRACKS_DATA[]){
	// now get all records from file ... if it exists ?
	int count2 = ReadTracks( AllTracks, TRACKS_DATA );
	if ( count2 >= 0 ){
	std::cout << count2 << " track record(s) read into memory ..." << std::endl;
	}
	else {
	std::cout <<"(The file will be created when some track records exist.)" <<std::endl;
	}
}
