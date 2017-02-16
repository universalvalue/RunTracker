#include "RunningAppFunctions.h"
#include <iostream>
#include <fstream>

int ReadTracks ( std::list<Track> &TrackList, const char TRACKS_DATA[]){
	std::ifstream InFile( TRACKS_DATA ); // recall RUNS_DATA is a Global variable

	if ( !InFile ){
		std::cout << "Error attempting to access track database ... \n"<< "(Perhaps it dosen't exist yet?)" << std::endl;
		return -1;          // report error condition ...
	}
	else if ( TrackList.size() ){ // i.e. if not == 0 ...
		std::cout << "\nDo you want to over-write the " << TrackList.size() << " records in memory (y/N) ? " << std::flush;
		int reply = GetInput(); 
		if( reply != 'Y' ){
			std::cout << "Aborted ... " << std::flush;
			return 0;
		}
	}
	/* else ... if reach here ... */
	std::list< Track >temp;
	TrackList = temp; // set term to null ...
	std::string trackname, DistancesAll, DescriptionsAll;
	std::vector<std::string> Descriptions, DistancesStrings;
	std::vector<double> Distances;
	std::map<std::string, double> trackinfo;
	for( i = 0; getline( InFile, trackname, '\n' ); ++i ) //first get 1st string (up to '\n')
	{
		getline( InFile, DescriptionsAll, '\n'); 
		std::vector<std::string> Descriptions = Split(DescriptionsAll, ',');
		getline( InFile, DistancesAll, '\n'); 
		std::vector<std::string> DistancesStrings = Split(DistancesAll, ',');
		std::transform(DistancesStrings.begin(), DistancesStrings.end(), Distances.begin(), [](const std::string& val){
		      return std::stod(val);
	      });
		for (int j = 0; j < Descriptions.size(); ++j){
			    trackinfo[Descriptions[j]] = Distances[j]; 
		}

		TrackList.push_back( Track( trackname, trackinfo)); // construct and add new Student
	}
	InFile.close();
	return i; // report success? ... i.e. return the record count ... 
}
