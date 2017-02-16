#ifndef TRACK_H
#define TRACK_H

#include <string>
#include <map>
////////////////////////////////////////////////////////////////////////////////////////////////////
//		Introduce class "Track"
////////////////////////////////////////////////////////////////////////////////////////////////////


class Track{
	public:
		/* //constructors ... */
		/* Student(string nam, string num ) { name=nam; id=num; } */
		Track(std::string title, std::map<std::string, double> waypoints ) { TrackTitle = title; TrackWaypoints = waypoints; }

		// setters ...
		void setTitle(std::string title){ TrackTitle = title; }
		void setWaypoints(std::map<std::string, double> waypoints) { TrackWaypoints = waypoints; }

		// getters ...
		std::string getTitle() { return TrackTitle; }
		std::map<std::string, double> getWaypoints() { return TrackWaypoints; }
	private:
		std::string TrackTitle; // add any needed info here, just like in a C/C++ 'struct'
		std::map<std::string, double> TrackWaypoints;	
};
#endif
