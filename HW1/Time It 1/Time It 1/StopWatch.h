#include <chrono>
#include <iostream>
#include "StopWatch.cpp"

#ifndef StopWatch_H
#define StopWatch_H

StopWatch::StopWatch() {
	start = std::chrono::high_resolution_clock::now();
}
StopWatch::~StopWatch(){

	end = std::chrono::high_resolution_clock::now();
	duration = end - start;
	std::cout << duration.count() << "s\n";

}

#endif // !StopWatch_H


