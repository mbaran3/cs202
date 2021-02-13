#include <iostream>

static int _static;
int main() {

	int* free = new int;
	int stack = 0;


	std::cout << "static data location :" << &_static << std::endl;
	std::cout << "free storage location :" << &free << std::endl;
	std::cout << "Stack storage location :" << &stack << std::endl;

	std::cout << std::endl;

	std::cout << "Static vs Free" << std::endl;
	if (&_static > free)
		std::cout << "Static Data is stored higher in memory" << std::endl;
	else
		std::cout << "Free storage is stored higher in memory" << std::endl;


	std::cout << "Free vs Stack" << std::endl;
	if (&stack > free)
		std::cout << "Stack data is stored higher in memory" << std::endl;
	else
		std::cout << "Free storage is stored higher in memory" << std::endl;


	std::cout << "Static vs Stack" << std::endl;
	if (&stack > &_static)
		std::cout << "Static Data is stored higher in memory" << std::endl;
	else
		std::cout << "Stack data is stored higher in memory" << std::endl;
	
	return 0;
}