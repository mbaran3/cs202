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
double StopWatch::getDurationmilli() {
	end = std::chrono::high_resolution_clock::now();
	duration = end - start;
	return duration.count() * 1000;
}
void StopWatch::stopTime() {
	end = std::chrono::high_resolution_clock::now();
}
double StopWatch::getStopTime() {
	duartion = end - start;
	return duration.count();
}
#endif // !StopWatch_H

