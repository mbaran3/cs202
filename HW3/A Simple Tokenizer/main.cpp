#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>


struct TokenAndPosition {

	std::string token;
	int line;
	int column;
};

std::vector<std::string> lineToTokens(const std::string& line) {

	std::string token;
	std::vector<std::string> vToken;
	std::stringstream ss(line);
	while (ss >> token) 
		vToken.push_back(token);
	return vToken;

}

int main() {

	std::string fileName = "testing.txt";
	std::fstream inFile(fileName);
	std::vector<std::string> vTest = lineToTokens("Hello this is a test hi");
	
	for (auto i : vTest)
		std::cout << i << " ";
	std::cout << vTest.size();

	std::cout << std::endl;
	
	if (!inFile)
		std::cout << "Error reading file" << std::endl;
	else
		std::cout << "Working" << std::endl;

}