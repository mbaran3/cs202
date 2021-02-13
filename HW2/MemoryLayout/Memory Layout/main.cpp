#include <iostream>

static int _static;
int main() {

	int* free = new int;
	int stack = 0;


	std::cout << "static data location :" << &_static << std::endl;
	std::cout << "free storage location :" << &free << std::endl;
	std::cout << "Stack storage location :" << &stack << std::endl;
	
	return 0;
}