#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include "StopWatch.h";


std::vector<int> generateVector(int size) {

	std::random_device seed;
	std::mt19937 generator(seed());
	std::uniform_int_distribution<int> randNum(1, size);
	StopWatch Time;
	std::vector<int> vInt(size);
	for (int i = 0; i < size; i++)
		vInt[i] = randNum(generator);
	std::cout << "*****GENERATED VECTOR WITH SIZE OF " << size << "*****" << std::endl;
	return vInt;
}
void SortFunction(std::vector<int>& vInt) {
	StopWatch Time;
	std::sort(vInt.begin(), vInt.end());
	std::cout << "Sort took" << std::endl;
	std::cout << "Seconds :" << Time.getDuration() << std::endl;
	std::cout << "Milliseconds :" << Time.getDurationmilli() << std::endl;
	std::cout << std::endl;
}
void findFunction(std::vector<int> vInt, int needle) {
	
	StopWatch Time;
	auto finder = std::find(vInt.begin(), vInt.end(), needle);
	std::cout << "std::find took" << std::endl;
	std::cout << "Seconds :" << Time.getDuration() << std::endl;
	std::cout << "Milliseconds :" << Time.getDurationmilli() << std::endl;
	std::cout << std::endl;
}
void binarySearch(std::vector<int> vInt, int needle) {

	StopWatch Time;
	std::sort(vInt.begin(), vInt.end());
	std::binary_search(vInt.begin(), vInt.end(), needle);
	std::cout << "std::binary_search took" << std::endl;
	std::cout << "Seconds :" << Time.getDuration() << std::endl;
	std::cout << "Milliseconds :" << Time.getDurationmilli() << std::endl;
	std::cout << std::endl;

}

void revrseFunction(std::vector<int> vInt) {
	StopWatch Time;
	std::reverse(vInt.begin(), vInt.end());
	std::cout << "std::reverse took" << std::endl;
	std::cout << "Seconds :" << Time.getDuration() << std::endl;
	std::cout << "Milliseconds :" << Time.getDurationmilli() << std::endl;
	std::cout << std::endl;
}
// Creates a vector set size and runs all other functions and times them
void testVector(int size) {
	

	std::vector<int> testVector = generateVector(size);
	findFunction(testVector, 0);
	revrseFunction(testVector);
	SortFunction(testVector);
	binarySearch(testVector, 0);
	holdProgram();

}
int main() {

	StopWatch Time;

	testVector(1000);
	testVector(10000);
	testVector(100000);
	testVector(1000000);
	testVector(10000000);
	testVector(100000000);

	std::cout << "\n\n Total Program run time :" << Time.getDuration() << "s" << std::endl;

	

	return 0;
}