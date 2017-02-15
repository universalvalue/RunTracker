#include "RunningAppFunctions.h" 

void ImportRuns(std::list<Run> &AllRuns, std::list<Track> &AllTracks, const char RUNS_DATA[]){
	// now get all records from file ... if it exists ?
	int count = ReadRuns( AllRuns, AllTracks, RUNS_DATA );
	if ( count >= 0 ){
	std::cout << count << " run record(s) read into memory ..." << std::endl;
	}
	else {
	std::cout <<"(The file will be created when some runs records exist.)" <<std::endl;
	}
}
