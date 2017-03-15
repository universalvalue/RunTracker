#ifndef TRACK_H
#define TRACK_H

#include <string>
#include <map>
#include "ClassWaypoint.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
//		Introduce class "Track"
////////////////////////////////////////////////////////////////////////////////////////////////////


class Track{
	public:
		/* //constructors ... */
		/* Student(string nam, string num ) { name=nam; id=num; } */
		Track(){}
		Track(std::string title, std::list< Waypoint > waypoints ) { TrackTitle = title; TrackWaypoints = waypoints; }

		// setters ...
		void setTitle(std::string title){ TrackTitle = title; }
		void setWaypoints(std::list< Waypoint > waypoints) { TrackWaypoints = waypoints; }

		// getters ...
		std::string getTitle() { return TrackTitle; }
		std::list< Waypoint > getWaypoints() { return TrackWaypoints; }
	private:
		std::string TrackTitle; // add any needed info here, just like in a C/C++ 'struct'
		std::list< Waypoint > TrackWaypoints;	
};
#endif
