#include <iostream>

void to_lower(char* string) {

	int size = 0;
	while (string[size]) // Gets the size of the array
		size++;
	for (int i = 0; i < size; i++) // Goes through the array
		for (char j = 65; j <= 90; j++) //Goes through the alphabet using ASCII
			if (j == string[i])
				string[i] += 32; // adds 32 to the character changing it for uppercase to lowercase
}
int main() {

	char str[] = "HELLO WORLD!";
	

	std::cout << "Before to_lower is called : " << str << std::endl;
	to_lower(str);
	std::cout<< "After to_lower is called : " << str << std::endl;
	


	return 0;
}