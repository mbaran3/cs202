#include <chrono>


class StopWatch {


public:
	
	std::chrono::time_point<std::chrono::steady_clock> start, end;
	std::chrono::duration<double> duration;
	StopWatch();
	~StopWatch();
	

};