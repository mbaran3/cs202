#include <chrono>
#include <iostream>
#include "StopWatch.cpp"

#ifndef StopWatch_H
#define StopWatch_H

StopWatch::StopWatch() {
	start = std::chrono::high_resolution_clock::now();
}

double StopWatch::getDuration() {

	end = std::chrono::high_resolution_clock::now();
	duration = end - start;
	return duration.count();
}
void StopWatch::restWatch() {

	start = std::chrono::high_resolution_clock::now();
}

#endif // !StopWatch_H


