#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include "StopWatch.h";


void generateVector(int size) {



}

int main() {

	StopWatch Time;
	std::vector<int> vInt;
	for (int i = 0; i < 100000; i++)
		vInt.push_back(i);
	std::cout << Time.getDuration() << "s\n";


	return 0;
}