#include "RunningAppFunctions.h"
#include <iostream>
#include <fstream>

int ReadRuns (std::list<Run> &RunList, std::list<Track> &TrackList, const char RUNS_DATA[]){
	std::ifstream InFile( RUNS_DATA ); // recall RUNS_DATA is a Global variable

	if ( !InFile ){
		std::cout << "Error attempting to access run database ... \n"<< "(Perhaps it dosen't exist yet?)" << std::endl;
		return -1;          // report error condition ...
	}
	else if ( RunList.size() ){ // i.e. if not == 0 ...
		std::cout << "\nDo you want over-write the " << RunList.size() << " records in memory (y/N) ? " << std::flush;
		int reply = GetInput(); 
		if( reply != 'Y' ){
			std::cout << "Aborted ... " << std::flush;
			return 0;
		}
	}
	/* else ... if reach here ... */
	std::list< Run >temp;
	RunList = temp; // set term to null ...
	std::string date, time, DistanceString, TimesAll, trackname;
	double distance;
	int i;
	Track runtrack;
	for( i=0; getline( InFile, date, '\n' ); ++i ) //first get 1st string (up to '\n')
	{
		getline( InFile, time, '\n' ); // then get next line (up to '\n')
		getline( InFile, DistanceString, '\n'); //... until whole file is read
		distance = atof(DistanceString.c_str());
		getline( InFile, trackname, '\n');
		getline( InFile, TimesAll, '\n'); 
		std::vector<std::string> Times = Split(TimesAll, ',');

		std::list<Track>::iterator it;
		for (it = TrackList.begin(); it != TrackList.end(); it++){
			if (it->getTitle() == trackname){
				runtrack = *it;	
			}	
		}

		RunList.push_back( Run(date, time, distance, runtrack, Times)); // construct and add new Student
	}
	InFile.close();
	return i; // report success? ... i.e. return the record count ... 
}
