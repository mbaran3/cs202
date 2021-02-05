#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include "StopWatch.h";

/*
* generates a vector of users size
*/
std::vector<int> generateVector(int size) {

	std::random_device seed;
	std::mt19937 generator(seed());
	std::uniform_int_distribution<int> randNum(0, size);
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
void searchFunction(std::vector<int> vInt) {
	
	std::vector<int> needle = { -1 };
	StopWatch Time;
	std::search(vInt.begin(), vInt.end(), needle.begin(), needle.end());
	std::cout << "std::search took" << std::endl;
	std::cout << "Seconds :" << Time.getDuration() << std::endl;
	std::cout << "Milliseconds :" << Time.getDurationmilli() << std::endl;
	std::cout << std::endl;
	
}
void binarySearch(std::vector<int> vInt, int needle) {

	
	StopWatch Time;
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
/*
* creates a vector of users defined size and times how long it takes to
* sort, revrse, std::find, and binary_search.
* generates a new vector of ints after every run.
* @param (size of vector, how many times to test a vector of that size);
*/
void testVector(int size, int runTimes) {
	

	for (int i = 0; i < runTimes; i++) {
	std::cout << "************" << i + 1 << "************" << std::endl;
	std::vector<int> testVector = generateVector(size);
	searchFunction(testVector);
	revrseFunction(testVector);
	SortFunction(testVector);
	binarySearch(testVector, 0);
	}
}
int main() {

	
	testVector(10000, 5);
	holdProgram();
	testVector(100000, 5);
	holdProgram();
	testVector(10000000, 5);
	holdProgram();
	testVector(100000000, 5);
	holdProgram();

	

	return 0;
}