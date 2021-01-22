#include <iostream>
#include <string>
#include <vector>

double cpp_ftoc(const char* str) {
		
	std::cout << str;
	return 0;
}
double c_ctof(const char* str) {

	return 0;
}
double ftoc(double temp) {
	return (5.0 / 9.0) * (temp - 32);
}
double ctof(double temp) {
	return (temp * 9.0 / 5.0) + 32;
}

int main(int argc, char* argv[]) {
	
	
	if (argc < 3) {
		std::cout << "Few Arguements\n";
		return 0;
	}
	double start_deg = atof(argv[2]);

	if (strcmp(argv[1], "ftoc") == 0)
		std::cout << start_deg << " degrees Fahrenheit equals " << ftoc(start_deg) << " degrees Celsius\n";
	if (strcmp(argv[1], "ctof") == 0)
		std::cout << start_deg << " degrees Celsius equals" << ctof(start_deg) << " degress Fahrenheit\n";
	
	return 0;
}