#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>

int main() {

	std::string fileName = "testing.txt";
	std::fstream inFile(fileName);

	if (!inFile)
		std::cout << "Error reading file" std::endl;
	else
		std::cout << "Working" << std::endl;




}