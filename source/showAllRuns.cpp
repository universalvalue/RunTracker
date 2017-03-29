//prints all avaiable Run names on screen. If requested further Details are printed.
#include <list>
#include <iostream>	// for basic in and output on screen
#include "ClassRun.h"

int GetInput();
int printAllRuns( std::list< Run >& AllRuns );
int printDetailedRunInfo ( Run detailedRun, std::list< Run >& AllRuns );


int showAllRuns( std::list< Run >& AllRuns ){
	std::list< Run >::iterator it;
	Run detailedRun;

	int printReturn =  printAllRuns( AllRuns );
	if ( printReturn == 0 ){
		return 0;
	}

	std::cout << "Do you want more information on one of the Runs? Just enter the corresponding number!\nLeaving the input empty leads back to menu!\n>>";
	std::string reply;
	std::getline(std::cin, reply);
	/* reply = GetInput() - '0'; */
	if ( reply == "" ){
		return 1;
	}
	int j = 1;
	for (it = AllRuns.begin(); it != AllRuns.end(); it++){
		if( std::stoi(reply) == j ){
			detailedRun = *it;
		}
		j++;
	}
	int detailedReturn = printDetailedRunInfo( detailedRun, AllRuns);
}
