#include "StopWatch.h"
#include <vector>
#include <map>
#include <list>
#include <algorithm>
#include <string>
#include <fstream>
#include <sstream>



std::map<int, std::string> loadFiletoMap(std::string fileName) {

	StopWatch Time;
	std::map<int, std::string> mapOutput;
	std::string output;
	std::ifstream inFile(fileName);
	int i = 0;
	while (std::getline(inFile, output)) {

		std::pair<int, std::string> pair = std::make_pair(i, output);
		mapOutput.insert(pair);
		i++;

	}
	std::cout << fileName << " Took " << Time.getDurationmilli() << "ms to load to a map" << std::endl;
	return mapOutput;
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
	std::map<int, std::string> mapTaleoftwoCities = loadFiletoMap(fileName);
	std::cout << std::endl;
	sortList(listTaleoftwoCities);
	sortVector(vTaleoftwoCities);
	holdProgram();
}
int main() {


	testAllFunction("TaleoftwoCities.txt");


	return 0;
}