#ifndef WAYPOINT_H
#define WAYPOINT_H

#include <string>
////////////////////////////////////////////////////////////////////////////////////////////////////
//		Introduce class "Waypoint"
////////////////////////////////////////////////////////////////////////////////////////////////////


class Waypoint{
	public:
		/* //constructors ... */
		/* Student(string nam, string num ) { name=nam; id=num; } */
		Waypoint(){}
		Waypoint(std::string title, double distance ) { WaypointTitle = title; WaypointDistance = distance; }

		// setters ...
		void setTitle(std::string title){ WaypointTitle = title; }
		void setDistance(double distance) { WaypointDistance = distance; }

		// getters ...
		std::string getTitle() { return WaypointTitle; }
		double getDistance() { return WaypointDistance; }
	private:
		std::string WaypointTitle; // add any needed info here, just like in a C/C++ 'struct'
		double WaypointDistance;	
};
#endif
