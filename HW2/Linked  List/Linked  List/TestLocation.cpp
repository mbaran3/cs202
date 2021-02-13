#include <iostream>
#include <string>
#include <iterator>
#include <fstream>
#include <list>
#include <algorithm>
#include "Catch2.h"




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
//Searches the list and returns an iterator to the location of the searched title
//This only works with title
std::list<MetaData>::iterator searchtitle(const std::list<MetaData>& theList, std::string toFind) {
	
	std::list<MetaData>::iterator it = theList.begin();
	while (it != theList.end()) {

		if (it->title == toFind) {
			return it;
		}

		it++;
	}
}
bool operator > (MetaData a, MetaData b) {
	return a.title > b.title;
}
bool operator < (MetaData a, MetaData b) {
	return a.title < b.title;
 }

std::ostream& operator << (std::ostream & os, const MetaData data) {

	os << data.title << "\n" << data.author << std::endl;
	os << data.published << "\n" << data.language << std::endl;
	return os;
}
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
std::list<MetaData> fillList() {

	MetaData frankenstein("Frankenstein.txt");
	MetaData bible("TheKingJamesBible.txt");
	MetaData prideandPredjuice("PrideandPredjudice.txt");
	MetaData taleOfTwoCities("TaleoftwoCities.txt");
	
	std::list<MetaData> myList; 
	
	myList.push_back(frankenstein); // First Item in the list
	myList.push_back(bible);
	myList.push_back(prideandPredjuice);
	myList.push_back(taleOfTwoCities); //Last item in the list

	return myList;
}

TEST_CASE("Testing Queue: First-in First-out") {

	MetaData mobydick("MobyDick.txt");
	std::list<MetaData> qList = fillList();
	qList.push_back(mobydick); // Pushs Moby Dick to the back of the list
	REQUIRE(qList.back().title == "Title: Moby Dick; or The Whale"); // Test that Moby Dick was push to the back of the list.
	qList.pop_front(); // Pops Frankenstein off the front of the list.
	REQUIRE(qList.front().title == "Title: The King James Bible");// Test to see that the Bible is the front.

}
TEST_CASE("Test Stack: Last-in First Out") {

	MetaData mobydick("MobyDick.txt");
	std::list<MetaData> sList = fillList();
	sList.push_front(mobydick); // Pushes Moby Dick to the front of the list
	REQUIRE(sList.front().title == "Title: Moby Dick; or The Whale"); // test that Moby Dick was push to the front.
	sList.pop_back(); // Pops Tale of two Cities off the back of the list.
	REQUIRE(sList.back().title == "Title: Pride and Prejudice"); // Test that new Back of the list

}
TEST_CASE("Testing Sorting and Inserting and Finding") {

	MetaData mobydick("MobyDick.txt");
	std::list<MetaData> bookList = fillList();

	bookList.sort();
	
	auto it = bookList.begin();
	REQUIRE(it->title == "Title: A Tale of Two Cities"); // Test to see if the list is sorted
	
	it++; it++; // Moves iterator to the third book
	bookList.insert(it, mobydick); // Inserts moby dick infront of the third book
	--it; // Moves the iterator to point at Moby Dick
	REQUIRE(it->title == "Title: Moby Dick; or The Whale"); // Check that the iterator is pointing at Moby Dick

	auto it2 = searchtitle(bookList, "Title: The King James Bible"); // gets an iterator for where the book is
	REQUIRE(it2->title == "Title: The King James Bible"); // test to see if the iterator is correct
	
}

