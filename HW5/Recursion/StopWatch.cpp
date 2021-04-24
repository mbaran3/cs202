#include <chrono>


class StopWatch {


public:


	double getDuration();
	double getDurationmilli();
	double getStopTime();
	void stopTime();
	void restWatch();
	StopWatch();

private:
	std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
	std::chrono::duration<double> duration;
};