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
	std::vector<TokenAndPosition> tokenInfo; // The totality of the tokens
	int lineCounter = 1;
	while (std::getline(is, line)) {

		std::vector<std::string> tokens = lineToTokens(line);
		int column = 1;
		for (auto i : tokens) {
			TokenAndPosition singleToken{ i, lineCounter, column }; // input as {token, line, column}
			tokenInfo.push_back(singleToken);
			column += i.size()+1; // Adds size of the word + 1 to account for spaces;
		}
		++lineCounter;
	}
	
	return tokenInfo;
}
void printTokens(std::ostream& os, const std::vector<TokenAndPosition>& tokens) {

	os << std::setw(3) << "Ln "  << "Col " << "Word" << std::endl;
	for (auto i : tokens) {
		os << std::setw(3) << i.line << " ";
		os << std::setw(3) << i.column << " ";
		os << i.token << std::endl;
	}
}
int main(int argc, char *argv[]) {

	std::string fileName = argv[1];
	std::fstream inFile(fileName);

	if (!inFile) {
		std::cout << "Error reading file" << std::endl;
		return 1;
	}
	std::vector<TokenAndPosition> tokenized = readLines(inFile);
	if (argc < 4) {
	
		if (strcmp(argv[2], "--lineonly") == 0) {
			std::cout << "Program Complete" << std::endl;
			return 0;
		}
		else {
			std::cout << "Error to many argumnets please only use --lineonly as a second param" << std::endl;
			return 1;
		}
		
	}
	else 
		printTokens(std::cout, tokenized);

	return 0;
}