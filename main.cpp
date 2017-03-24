// A C++ program to track running training distances and times
// using lists and external functions
//
// All data is saved in data/RunsData.txt and TracksData.txt
// External functions are placed in source/

////////////////////////////////////////////////////////////////////////////////////////////////////
//	Includes
////////////////////////////////////////////////////////////////////////////////////////////////////	

#include <iostream>	// for basic in and output on screen
#include <fstream>	// for basic in and output to files
#include <string>	// for handling strings
#include <list>		// for using list
#include <cctype>	// for handling chars
#include <vector>	// for handling vectors

////////////////////////////////////////////////////////////////////////////////////////////////////
//	Own Includes
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "RunningAppFunctions.h"
#include "ClassRun.h"
#include "ClassTrack.h"
#include "ClassWaypoint.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
//		Global variables
////////////////////////////////////////////////////////////////////////////////////////////////////

const char RUNS_DATA[] = "data/RunsData.txt"; // file name for the data file containing all the runs
const char TRACKS_DATA[] = "data/TracksData.txt"; // file name for the data file containing all the runs

////////////////////////////////////////////////////////////////////////////////////////////////////
//		Main
////////////////////////////////////////////////////////////////////////////////////////////////////

int main(){
	//create a list to hold Runs 
	// also holds number of records, via '.size()'
	std::list <Run> AllRuns;
	//
	//create a list to hold Tracks 
	// also holds number of records, via '.size()'
	std::list <Track> AllTracks;

	ImportTracks(AllTracks, TRACKS_DATA);

	ImportRuns(AllRuns, AllTracks, RUNS_DATA);


	bool changesTracks = false; // set 'update file flag' to initial value ...
	bool changesRuns = false; // set 'update file flag' to initial value ...
	int reply;
	ClearScreen();
	for( ;; ){ // loop forever ... until break ...
		PrintMainMenu();
		reply = GetInput();

		if( reply == '1' || reply == 'A' ){
			std::cout << "The input was 1\n";//<< std::endl;
			int numAddedRuns = AddRun( AllTracks, AllRuns );
			std::cout << std::endl << numAddedRuns << " run record(s) added ...";
			/* << " The total number of student records now is " */
			/* << fall.size() << endl; */
			if( numAddedRuns ){
				changesRuns = true; // if >0 update bool variable changes
			}
		}
		else if( reply == '2' || reply == 'T' )
		{
			std::cout << "The input was 2,which means you want to add a new track. Unfortunately this choice is not implemented yet, so I'm gonna end this program now!\n";
			int numAddedTracks = AddTrack( AllTracks );
			std::cout << std::endl << numAddedTracks << " track record(s) added ...";
			if( numAddedTracks ){
				changesTracks = true; // if >0 update bool variable changes
			}
		}
		else if( reply == '3' || reply == 'S' ){
			std::cout << "The input was 3, which means I'm gonna print all Tracks in memory now!\n";
			ClearScreen();
			showAllTracks( AllTracks );
		}
		else if( reply == '4' || reply == 'R' ){
			std::cout << "The input was 4, which means I'm gonna print all Tracks in memory now!\n";
			ClearScreen();
			showAllRuns( AllRuns );

		}
		else if( reply == '7' || reply == 'E' )
		{
			std::cout << "The input was 7,which means I'm gonna end this program now!\n";

			break; //Exit Program
		}
		else if( reply == '8' || reply == 'X' )
		{
			std::cout << "The input was 8,which means I'm gonna end this program now!\n";
			std::cout << "Before closing all changes are saved!\n";
			if (changesTracks == true){
				invokeWriteTracks( AllTracks, TRACKS_DATA);
			}
			if (changesRuns == true){
				invokeWriteRuns( AllRuns, RUNS_DATA);
			}
			if ( ( changesRuns == false ) && (changesTracks == false) ){
				std::cout << " But there are no changes to be saved!\n";
			}

			std::cout << "Good Bye and keep on running! \n";
			break; //Exit Program
		}
		else{
			std::cout << "\nThis choice not implemented yet ... \n";
		} // end of if( reply == ? ) switch structure ...
		ClearScreen();
	}
}
