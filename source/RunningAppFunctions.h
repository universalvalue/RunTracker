#ifndef RunningAppFunctions_H
#define RunningAppFunctions_H

#include "ClassTrack.h"
#include "ClassRun.h"
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <sstream>

void ClearScreen();
void ImportTracks(std::list<Track> &AllTracks, const char TRACKS_DATA[]);
void ImportRuns(std::list<Run> &AllRuns, std::list<Track> &AllTracks,  const char RUNS_DATA[]);
std::vector<std::string> Split(const std::string &s, char delim);
void PrintMainMenu();
int showAllTracks( std::list< Track >& AllTracks );
int GetInput();
int WriteRuns( std::list<Run> &RunList, const char RUNS_DATA[]);
int invokeWriteRuns( std::list<Run> &RunList, const char RUNS_DATA[]);
int writeRunsCheck( std::list<Run> &RunList, const char RUNS_DATA[]);
int invokeWriteTracks (std::list< Track > &TrackList, const char TRACKS_DATA[]);
int writeTracksCheck( std::list< Track > &TrackList, const char TRACKS_DATA[]);
int writeTracks( std::list< Track > &TrackList, const char TRACKS_DATA[]);
int ReadRuns( std::list<Run> &RunList, std::list<Track> &TrackList, const char RUNS_DATA[]);
int ReadTracks(std::list<Track> &TrackList, const char TRACKS_DATA[]);
int AddTrack( std::list< Track >& AllTracks );
int AddRun( std::list< Track >& AllTracks, std::list< Run >& AllRuns);
std::list< Track >::iterator ExistTrack( std::list< Track > &AllTracks, std::string trackname );

#endif
