#include "RunningAppFunctions.h"
#include <iostream>
#include <fstream>

int WriteRuns (std::list<Run> &RunList, const char RUNS_DATA[]){
		std::ofstream OutFile( RUNS_DATA ); 

		int i = 0;
		std::list< Run >::iterator it; 
		for( it = RunList.begin(); it != RunList.end(); ++it ) //first get 1st string (up to ',')
		{
			OutFile << it->getDate() << "\n" << it->getTime() << "\n" << it->getDistance() << "\n" << it->getTrack.getTitle() << "\n" ;
			for ( int j = 0; j < it->getTrackTimes().size() - 1; j++){
				OutFile << it->getTrackTimes()[j] << ",";
			}
			OutFile << it->getTrackTimes()[getTrackTimes().size -1] << "\n";
			++i;
		}
		OutFile.close();

		if( i == (int)RunList.size() ){
			std::cout << "\nAll " << i << " records filed ok." << std::endl;
		}
		else{
			std::cout << "\nOnly " << i << " of " << RunList.size()	<< " records were written ..." << std::endl;
		}

		return i; // report success? ... i.e. return the record count ... w
}
