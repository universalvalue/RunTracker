// checks whether the is already a track existing with the given track name
//
#include <list>
#include "ClassTrack.h"

std::list< Track >::iterator ExistTrack( std::list< Track > &AllTracks, std::string trackname ){
	std::list< Track >::iterator it;
	for( it = AllTracks.begin(); it != AllTracks.end(); ++it ){
		if( it -> getTitle() == trackname )
			return it;
		}

		return AllTracks.end();
	}
