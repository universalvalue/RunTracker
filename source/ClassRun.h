#ifndef RUN_H
#define RUN_H

#include <string>
#include "ClassTrack.h"
#include <cmath>
#include <algorithm>
////////////////////////////////////////////////////////////////////////////////////////////////////
//		Introduce class "Run"
////////////////////////////////////////////////////////////////////////////////////////////////////

class Run{
	public:
		//constructors ...
		/* Student(){} */
		Run(std::string date, std::string time, double distance, Track track, std::vector<std::string> times ) { RunDate = date; RunTime = time; RunDistance = distance; RunTrack = track; TrackTimes = times; }

		// setters ...
		void setDate(std::string date){ RunDate = date; }
		void setTotTime(std::string time) { RunTime = time; }
		void setTotDistance(double distance) { RunDistance = distance; }
		void setRunTrack(Track track) { RunTrack = track; }
		void setTracktimes(std::vector<std::string> times) { TrackTimes = times;}

		// getters ...
		std::string getDate() { return RunDate; }
		std::string getTime() { return RunTime; }
		double getDistance() { return RunDistance; }
		std::string getSpeed();
		Track getTrack() {return RunTrack; }
		std::vector<std::string> getTrackTimes() {return TrackTimes;}
	private:
		std::string RunDate, // add any needed info here, just like in a C/C++ 'struct'
		RunTime;
		double RunDistance;	
		Track RunTrack;
		std::vector<std::string> TrackTimes;
};

#endif
