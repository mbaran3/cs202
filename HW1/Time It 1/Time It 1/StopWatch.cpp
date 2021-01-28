#include <chrono>


class StopWatch {


public:
	

	double getDuration();
	void restWatch();
	StopWatch();
	
private:
	std::chrono::time_point<std::chrono::steady_clock> start, end;
	std::chrono::duration<double> duration;
};