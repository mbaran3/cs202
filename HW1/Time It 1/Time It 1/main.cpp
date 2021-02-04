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
	return vInt;
}
void SortFunction(std::vector<int>& vInt) {
	StopWatch Time;
	std::sort(vInt.begin(), vInt.end());
	std::cout << "Sort took" << std::endl;
	std::cout << "Seconds :" << Time.getDuration() << std::endl;
	std::cout << "Milliseconds :" << Time.getDurationmilli() << std::endl;
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
int main() {

	std::vector<int> tester = generateVector(10);
	revrseFunction(tester);
	reverseCopyFunction(tester);
	findFunction(tester, 0);
	SortFunction(tester);
	binarySearch(tester, 0);
	


	return 0;
}