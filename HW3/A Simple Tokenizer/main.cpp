#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <sstream>
#include <fstream>
#include "StopWatch.h"

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
/*
* @param the fstream to be read into a vector
* returns vector<TokenAndPosition>
*/
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
/*
* @param a ostream, can be cout to print to console
* @param the vector<TokenAndPoosition> you want to be printed.
*/
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
	StopWatch timer;
	std::fstream inFile(fileName);

	if (!inFile) { // ends the program is the file is not read
		std::cout << "Error reading file" << std::endl;
		return 1;
	}
	std::vector<TokenAndPosition> tokenized = readLines(inFile);
	if (argc >= 3) {
	
		if (strcmp(argv[2], "--lineonly") == 0) {
			std::cout << "The program took " << timer.getDurationmilli() << "ms" << std::endl;
			std::cout << "Program Complete" << std::endl;
			return 0;
		}
		else { 
			std::cout << "Error to many argumnets please only use --lineonly as a second param" << std::endl;
			return 1;
		}
		
	}
	else // if --lineonly isnt a param prints the tokens
		printTokens(std::cout, tokenized);
	std::cout << "The program took " << timer.getDuration() << "s" << std::endl;

	return 0;
}