#include "RunningAppFunctions.h"
#include <iostream>
#include <fstream>

int WriteRuns (std::list<Run> &RunList, const char RUNS_DATA[]){
	std::ofstream OutFile( RUNS_DATA ); // recall RUNS_DATA is a Global variable

	if ( !OutFile ){
		std::cout << "Error attempting to access run database ... \n"<< "(Perhaps it dosen't exist yet?)" << std::endl;
		return -1;          // report error condition ...
	}
	else if ( RunList.size() ){ // i.e. if not == 0 ...
		std::cout << "\nDo you want to write the " << RunList.size() << " records in memory to file (y/n) ? " << std::flush;
		int reply = GetInput(); 
		if( reply != 'Y' ){
			std::cout << "Aborted ... " << std::flush;
			return 0;
		}
	}
	/* else ... if reach here ... */
	int i;
	for( i=0; i < RunList.size(); ++i ) //first get 1st string (up to ',')
	{
	}
	OutFile.close();
	return i; // report success? ... i.e. return the record count ... w
}
