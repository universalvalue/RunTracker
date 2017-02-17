// adds Run records to end of end of list of Run records ... 'AllRuns'
// gets input from keyboard ...

#include <iostream>	// for basic in and output on screen
#include <list>
#include "ClassTrack.h"
#include "ClassRun.h"

int GetInput();

int AddRun( std::list< Track >& AllTracks, std::list< Run >& AllRuns){
	std::cout << "\nEnter an empty Run Date to exit this 'Input Loop' ..." << std::endl;

	int count = 0, reply;
	std::string rundate, runtime, distancestring, trackname, temptime;
	double Distance;
	Track runtrack;
	std::vector< std::string > runtimes;
	for( ;; ){ // loop forever until break ...
		std::cout << "\n Run Date (DD/MM/YY): ";
		std::getline(std::cin, rundate);

		if( rundate == ""){
			break;
		}
		std::cout << "How much time did it take? (MM:SS)";
		std::getline(std::cin,runtime); 

		std::cout << "How many kilometers was the run?";
		std::getline(std::cin,distancestring);
		Distance = stod(distancestring);

		std::cout << "What track did you run?\n";
		std::list<Track>::iterator it;
		int i = 1;
		for (it = AllTracks.begin(); it != AllTracks.end(); it++){
			std::cout << i <<":\t"<< it->getTitle()<<"\n";
			i++;
		}
		int reply = GetInput(); 
		int j = 1;
		for (it = AllTracks.begin(); it != AllTracks.end(); it++){
			if( reply == j ){
				runtrack = *it;
			}
			j++;
		}

		std::cout << "Times to reach the waypoints on this track? (if unknown please enter 0/0)\n";
		for (std::map< std::string, double >::iterator it = runtrack.getWaypoints().begin(); it != runtrack.getWaypoints().end(); it++){
			std::cout << it->first << "\t" << it->second << "\n";
			std::getline(std::cin, temptime);
			runtimes.push_back(temptime);
		}


		std::cout << "Add or Redo (a/R) ? ";
		reply=GetInput();
		if ( toupper(reply) != 'A' ){
			std::cout << "Aborted ..." << std::endl;
			continue;
		}
		// ok ... create and add this record to the end of the list ...
		AllRuns.push_back( Run( rundate, runtime, Distance, runtrack, runtimes) );
		++count;
		std::cout << "Added ..." << std::endl;
	}
	return count;
}
