#include <iostream>
#include <string>
#include <vector>

double cpp_ftoc(const char* str) {
	double  temp = std::stod(str);
	double converted_temp = (5.0 / 9.0) * (temp - 32);
	return converted_temp;
}
double c_ctof(const char* str) {

	double temp = std::strtod(str, NULL);
	return (temp * 9.0 / 5.0) + 32;
}
double ftoc(double temp) {
	return (5.0 / 9.0) * (temp - 32);
}
double ctof(double temp) {
	return (temp * 9.0 / 5.0) + 32;
}

int main(int argc, char* argv[]) {
	
	if (argc < 3 || argc > 3) {
		std::cout << "Error to many arguements\n";
		return 0;
	}


	
	

	if (strcmp(argv[1], "ftoc") == 0) {

		try {
			double tester = std::stod(argv[2]);
		}
		catch (const std::invalid_argument&) {
			std::cout << "Error: '" << argv[2] << "' is an invalid arguement\n";
			return 0;
		}

		std::cout << argv[2] << " degrees Fahrenheit equals " << cpp_ftoc(argv[2]) << " degrees Celsius\n";
	}
		
	if (strcmp(argv[1], "ctof") == 0) {
		char* endprt;
		double tester = std::strtod(argv[2], &endprt);
		if (argv[2] == endprt) {
			std::cout << "ERROR: '" << argv[2] << "' is an invalid arguement\n";
			return 0;
		}
			
		std::cout << argv[2] << " degrees Celsius equals " << c_ctof(argv[2]) << " degress Fahrenheit\n";
	}
		

	return 0;
}


	//Converts ctof and ftoc using ftoc and ctof 
	/*if (argc < 3) {
		std::cout << "Few Arguements\n";
		return 0;
	}
	double start_deg = atof(argv[2]);

	if (strcmp(argv[1], "ftoc") == 0)
		std::cout << start_deg << " degrees Fahrenheit equals " << ftoc(start_deg) << " degrees Celsius\n";
	if (strcmp(argv[1], "ctof") == 0)
		std::cout << start_deg << " degrees Celsius equals" << ctof(start_deg) << " degress Fahrenheit\n";
	*/