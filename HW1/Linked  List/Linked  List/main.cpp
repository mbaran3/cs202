#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include <queue>
#include <stack>

// Moves through the file to get to a desired line 
std::ifstream& gotoLine(std::ifstream& file, int line) {
	
	std::string hold;
	file.seekg(std::ios::beg);
	for (int i = line - 1; i > 0; i--) {
		std::getline(file, hold);
	}
	return file;
}
struct MetaData { // Meta data for books

	
	std::string title;
	std::string author;
	std::string published;
	std::string language;
	MetaData(std::string fileName);


};
//Sets the data for MetaData 
//Only works for plain txt Project Gutenberg books that have the right format
//Some book might need to be edited to fit this format
MetaData::MetaData(std::string fileName) {


	std::string output;
	std::ifstream inFile(fileName);
	if (!inFile) {
		std::cout << "ERROR LOADING THE FILE" << std::endl;
	}
	gotoLine(inFile, 11); // The Line the Title should be on
	std::getline(inFile, title);
	gotoLine(inFile, 14); // The line that author should be on
	std::getline(inFile, author);
	gotoLine(inFile, 16); // the line that publication data should be on
	std::getline(inFile, published);
	gotoLine(inFile, 19); // the line that language should be one
	std::getline(inFile, language); 

}



int main() {

	MetaData frankenstein("Frankenstein.txt");
	MetaData bible("TheKingJamesBible");
	MetaData prideandPredjuice("PrideandPredjudice.txt");
	MetaData taleOfTwoCities("TaleoftwoCities.txt");


}