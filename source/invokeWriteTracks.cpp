#include "RunningAppFunctions.h"
#include <iostream>
#include <fstream>

int invokeWriteTracks (std::list< Track > &TrackList, const char TRACKS_DATA[]){
	int checkResult = writeTracksCheck( TrackList, TRACKS_DATA);
	if (checkResult == 0){
		int i = writeTracks( TrackList, TRACKS_DATA );
		return i; // report success? ... i.e. return the record count ... w
	}
	else {
		return checkResult;
	}
}
