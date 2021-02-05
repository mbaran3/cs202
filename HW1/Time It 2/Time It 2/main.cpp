#include "StopWatch.h"
#include <vector>
#include <map>
#include <list>
#include <algorithm>
#include <string>
#include <fstream>
#include <sstream>



std::map<std::string, int> loadFiletoMap(std::string fileName) {

	StopWatch Time;
	std::map<std::string, int> mapOutput;
	std::string output;
	std::ifstream inFile(fileName);
	int i = 0;
	while (std::getline(inFile, output)) {

		std::pair<std::string, int> pair = std::make_pair(output, i);
		mapOutput.insert(pair);
		i++;

	}
	std::cout << fileName << " Took " << Time.getDurationmilli() << "ms to load to a map" << std::endl;
	return mapOutput;
}
void findMap(std::map<std::string, int> theMap, std::string toFind) {

	StopWatch Time;
	auto it = theMap.find(toFind);
	if (it != theMap.end()) {
		std::cout << "Map took " << Time.getDurationmilli() << " to find" << toFind;
		std::cout << std::endl;
	}
	else {
		std::cout << "Map took " << Time.getDurationmilli() << " to not find " << toFind;
		std::cout << std::endl;
	}
}
void printMapbyValue(std::map<std::string, int> mapBook) {

	StopWatch Time;
	std::vector < std::pair<std::string, int> > vMap;
	for (auto i : mapBook)
		vMap.push_back(i);
	std::sort(vMap.begin(), vMap.end(), []
	(const std::pair<std::string, int> a, const std::pair<std::string, int> b) {
			return a.second < b.second;
		});
	for (auto i : vMap)
		std::cout << i.first << "\n";

}
std::list<std::string> loadFiletoList(std::string fileName) {

	StopWatch Time;
	std::list<std::string> listOutput;
	std::string output;
	std::ifstream inFile(fileName);
	while (std::getline(inFile, output))
		listOutput.push_back(output);
	std::cout << fileName << " Took " << Time.getDurationmilli() << "ms to load to a list" << std::endl;
	return listOutput;

}
void sortList(std::list<std::string> lBook) {
	
	StopWatch Time;
	lBook.sort();
	std::cout << "List took " << Time.getDurationmilli() << "ms to sort" << std::endl;

}
void findList(std::list<std::string> theList, std::string toFind) {

	StopWatch Time;
	if (std::find(theList.begin(), theList.end(), toFind) != theList.end()) {
		std::cout << "List took " << Time.getDurationmilli() << "ms to find" << toFind;
		std::cout << std::endl;
	}
	else {
		std::cout << "List took " << Time.getDurationmilli() << "ms to not find " << toFind;
		std::cout << std::endl;
	}
}

std::vector<std::string> loadFiletoVector(std::string fileName) {

	StopWatch Time;
	std::vector<std::string> vOutput;
	std::string output;
	std::ifstream inFile(fileName);
	while (std::getline(inFile, output))
		vOutput.push_back(output);
	std::cout << fileName << " Took " << Time.getDurationmilli() << "ms to load to a vector" << std::endl;
	return vOutput;

}
void sortVector(std::vector<std::string> vBook) {

	StopWatch Time;
	std::sort(vBook.begin(), vBook.end());
	std::cout << "Vecotr took " << Time.getDurationmilli() << "ms to sort" << std::endl;
}

void findVector(std::vector<std::string> theVector, std::string toFind) {

	StopWatch Time;
	if (std::find(theVector.begin(), theVector.end(), toFind) != theVector.end()) {
		std::cout << "Vector took " << Time.getDurationmilli() << "ms to find " << toFind;
		std::cout << std::endl;
	}
	else {
		std::cout << "Vector took" << Time.getDurationmilli() << "ms to not find " << toFind;
		std::cout << std::endl;
	}
}
void testAllFunction(std::string fileName) {

	std::cout << "**********" << fileName << "**********" << std::endl;
	std::vector<std::string> vectorBook = loadFiletoVector(fileName);
	std::list<std::string> listBook = loadFiletoList(fileName);
	std::map<std::string, int> mapBook = loadFiletoMap(fileName);

	std::cout << std::endl;
	findVector(vectorBook, "1111");
	findList(listBook, "1111");
	findMap(mapBook, "1111");
	

	std::cout << std::endl;
	sortVector(vectorBook);
	sortList(listBook);
	std::cout << "Map is already sorted" << std::endl;

}
int main() {

	testAllFunction("TheKingJamesBible");
	holdProgram();
	testAllFunction("TaleoftwoCities");
	holdProgram();
	testAllFunction("MobyDick");
	holdProgram();
	testAllFunction("Frankenstein");
	holdProgram();
	testAllFunction("PrideandPredudice");
	holdProgram();



	return 0;
}