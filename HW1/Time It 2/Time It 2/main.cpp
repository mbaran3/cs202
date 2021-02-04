#include "StopWatch.h"
#include <vector>
#include <string>
#include <fstream>
#include <sstream>




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

	return 0;
}