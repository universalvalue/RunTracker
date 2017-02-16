// adds Track records to end of end of list of Track records ... 'AllTracks'
// gets input from keyboard ...
std::list< Track >::iterator ExistTrack( std::list< Track > &AllTracks, std::string trackname );

int AddTrack( list< Track >& AllTracks ){
	std::cout << "\nEnter an empty Track Name to exit this 'Input Loop' ..." << std::endl;

	int count = 0, reply;
	std::string trackname, Description, DistanceString;
	double Distance;
	std::map<std::string, double> trackinfo;

	for( ;; ){ // loop forever until break ...
		std::cout << "\nTrack Name   : ";
		std::getline(std::cin, trackname);
		if( ExistTrack( AllTracks, trackname ) != NULL ){
			std::cout << "\nThat track title " << trackname << " already exits ... " << endl;
			continue; // from the top of the forever loop right now
		}

		if( trackname == ""){
			break;
		}

		std::cout << "\n How many waypoints do you want to enter?";
		reply = GetInput();

		for (int i = 0; i < atof(reply); i++){
			std::cout << "Name of waypoint : ";
			std::getline(std::cin, Description);

			std::cout << "Distance of waypoint : ";
			std::getline(std::cin, DistanceString);

			Distance = atof(DistanceString);

			trackinfo[Description] = Distance;
		}

		std::cout << "Add or Redo (a/R) ? ";
		reply=GetInput();
		if ( toupper(reply) != 'A' ){
			cout << "Aborted ..." << endl;
			continue;
		}
		// ok ... create and add this record to the end of the list ...
		AllTracks.push_back( Track( trackname, trackinfo) );
		++count;
		std::cout << "Added ..." << std::endl;
	}
	return count;
}
