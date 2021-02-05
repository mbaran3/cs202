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
		std::cout << "Map found " << toFind << " in " << Time.getDurationmilli();
		std::cout << "ms" << std::endl;
	}
	else {
		std::cout << toFind << " was not found in " << Time.getDurationmilli();
		std::cout << "ms" << std::endl;
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
void sortVector(std::vector<std::string> vBook) {

	StopWatch Time;
	std::sort(vBook.begin(), vBook.end());
	std::cout << "Vecotr took " << Time.getDurationmilli() << "ms to sort" << std::endl;


}
void sortList(std::list<std::string> lBook) {
	
	StopWatch Time;
	lBook.sort();
	std::cout << "List took " << Time.getDurationmilli() << "ms to sort" << std::endl;

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
void testAllFunction(std::string fileName) {

	std::vector<std::string> vTaleoftwoCities = loadFiletoVector(fileName);
	std::list<std::string> listTaleoftwoCities = loadFiletoList(fileName);
	std::map<std::string, int> mapTaleoftwoCities = loadFiletoMap(fileName);

	
	findMap(mapTaleoftwoCities, "1111");

	std::cout << std::endl;
	sortList(listTaleoftwoCities);
	sortVector(vTaleoftwoCities);
	holdProgram();
}
int main() {


	testAllFunction("TaleoftwoCities.txt");


	return 0;
}