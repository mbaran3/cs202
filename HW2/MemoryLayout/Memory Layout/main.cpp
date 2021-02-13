#include <iostream>

static int _static;
int main() {

	int* free = new int;
	int* free2 = new int;
	int* array = new int[100];

	int stack = 0;
	int stack2 = 0;

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
	
	std::cout << std::endl;

	if (&stack > &stack2)
		std::cout << "The stack grows downwards towards lower addresses in memory" << std::endl;
	else
		std::cout << "The stack grows upwards towards higher addresses in memory" << std::endl;

	std::cout << std::endl;

	if (free > free2)
		std::cout << "Free memory grows downwards towards lower addresses in memory" << std::endl;
	else
		std::cout << "Free memory grows upwards towards higher address in memory" << std::endl;

	if (array[0] > array[99])
		std::cout << "Elements with higher indices allocate to lower addresses" << std::endl;
	else
		std::cout << "Elemets with higher indices allocate to higher addresses" << std::endl;


	return 0;
}