#include "ClassRun.h"
#include "RunningAppFunctions.h"
////////////////////////////////////////////////////////////////////////////////////////////////////
//		Introduce class "Run"
////////////////////////////////////////////////////////////////////////////////////////////////////

std::string Run::getSpeed () {
	std::vector<std::string> TotalTime = Split(RunTime,':');

	int TotalSeconds = atoi(TotalTime[0].c_str()) * 60 + atoi(TotalTime[1].c_str());

	double SecondsPerKilometer = std::ceil(TotalSeconds / RunDistance);
	std::div_t TimePerKilometer = div(SecondsPerKilometer, 60);

	std::string AverageTime;
	AverageTime.append(std::to_string(TimePerKilometer.quot));
	AverageTime.append(":");

	std::string SecondsOfAverage;
	for (int i = 0 ; i < 2 ; i ++){
		 SecondsOfAverage += ('0' + TimePerKilometer.rem % 10);
		 TimePerKilometer.rem /= 10;
	}
	std::reverse(SecondsOfAverage.begin(), SecondsOfAverage.end());
	AverageTime.append(SecondsOfAverage);

	return AverageTime;
}

