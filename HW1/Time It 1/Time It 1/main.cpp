#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include "StopWatch.h";


std::vector<int> generateVector(int size) {

	std::random_device seed;
	std::mt19937 generator(seed());
	std::uniform_int_distribution<int> randNum(0, size);
	StopWatch Time;
	std::vector<int> vInt(size);
	for (int i = 0; i < size; i++)
		vInt[i] = randNum(generator);
	std::cout << size << " Vector took " << Time.getDuration() << "s to generate" << std::endl;
	return vInt;

}
void binarySearch(std::vector<int> vInt, int needle) {

	StopWatch Time;
	std::binary_search(vInt.begin(), vInt.end(), needle);
	std::cout << "Search took " << Time.getDuration() << "s" << std::endl;
}	

int main() {

	
	
	std::vector<int> ten = generateVector(10);
	std::vector<int> hundred = generateVector(100);
	std::vector<int> thousand = generateVector(1000);
	std::vector<int> ten_thousand = generateVector(10000);
	std::vector<int> hundred_thousand = generateVector(100000);
	std::vector<int> million = generateVector(1000000);
	std::vector<int> ten_million = generateVector(10000000);
	std::vector<int> hundred_million = generateVector(100000000);
	



	std::cout << "Finished generating" << std::endl;



	return 0;
}