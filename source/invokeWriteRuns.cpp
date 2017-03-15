#include "RunningAppFunctions.h"
#include <iostream>
#include <fstream>

int invokeWriteRuns (std::list<Run> &RunList, const char RUNS_DATA[]){
	int checkResult = writeRunsCheck(RunList, RUNS_DATA);
	if (checkResult == 0){
		int i = WriteRuns( RunList, RUNS_DATA );
		return i; // report success? ... i.e. return the record count ... w
	}
	else {
		return checkResult;
	}
}
