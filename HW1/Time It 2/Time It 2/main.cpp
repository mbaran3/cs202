#include "StopWatch.h"
#include <vector>
#include <list>
#include <string>
#include <fstream>
#include <sstream>



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
int main() {


	std::vector<std::string> vTaleoftwoCities = loadFiletoVector("TaleoftwoCities.txt");
	std::list<std::string> listTaleoftwoCities = loadFiletoList("Taleoftwocities.txt");


	return 0;
}