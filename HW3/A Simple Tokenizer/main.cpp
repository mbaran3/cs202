#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
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
std::vector<TokenAndPosition> readLines(std::fstream& is) {

	std::string line;
	std::vector<TokenAndPosition> tokenInfo;
	int lineCounter = 1;
	while (std::getline(is, line)) {

		std::vector<std::string> tokens = lineToTokens(line);
		int column = 0;
		for (auto i : tokens) {
			TokenAndPosition singleToken{ i, lineCounter, column };
			tokenInfo.push_back(singleToken);
			column += i.size()+1;
		}
		++lineCounter;
	}
	
	return tokenInfo;
}

int main() {

	std::string fileName = "testing.txt";
	std::fstream inFile(fileName);

	if (!inFile)
		std::cout << "Error reading file" << std::endl;
	else
		std::cout << "Working" << std::endl;

	std::vector<TokenAndPosition> tokenized = readLines(inFile);
	std::cout << std::setw(3) << "Ln "  << "Col " << "Word" << std::endl;
	for (auto i : tokenized) {
		std::cout << std::setw(3) << i.line << " ";
		std::cout << std::setw(3) << i.column << " ";
		std::cout << i.token << std::endl;
	}


	return 0;

}