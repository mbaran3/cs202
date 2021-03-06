
#ifndef StopWatch_H
#define StopWatch_H
#include <string>
#include <chrono>
#include <iostream>
#include "StopWatch.cpp"


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
	duration = end - start;
	return duration.count();
}

void holdProgram() {
	std::string hold;
	std::cout << "Press Enter to continue" << std::endl;
	getline(std::cin, hold);
}
#endif // !StopWatch_H
