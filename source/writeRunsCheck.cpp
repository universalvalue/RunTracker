#include "RunningAppFunctions.h"

int writeRunsCheck(std::list<Run> &RunList, const char RUNS_DATA[]){
	std::ofstream OutFile( RUNS_DATA ); 

	if ( !OutFile ){
		std::cout << "Error attempting to access run database ... \n"<< "(Perhaps it dosen't exist yet?)" << std::endl;
		std::cout << "Do you want to create a new database file (y/N)? (The name will be RunsData.txt) \n" << std::endl;
		int reply = GetInput(); 
		if( reply != 'Y' ){
			std::cout << "No new database created! Writing aborted ... " << std::flush;
			return -3;
		}
		std::cout << "Creating new database file ... \n";
		/* return 0;          // report error condition ... */
	}
	else if ( RunList.size() ){ // i.e. if not == 0 ...
		std::cout << "\nDo you want to write the " << RunList.size() << " records in memory to file (y/N) ? " << std::flush;
		int reply = GetInput(); 
		if( reply != 'Y' ){
			std::cout << "Aborted ... " << std::flush;
			return -2;
		}
	}
	else {
		std::cout << "\n No data to write in list of runs?!\n"<<std::flush;
		return -1;
	}
	return 0;

}
