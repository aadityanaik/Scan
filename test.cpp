#include <iostream>
#include <exception>
#include "scan.hpp"

int main() {
	int x;

	//Using Scanner::next<type>
	std::cout << "Enter an integer\n";

	x = scanner::next<int>("Integer expected");
	std::cout << "Congratulations! You entered an integer- " << x << std::endl;

	//Using Scanner::Scan
	double y;
	std::cout << "Enter a double this time\n";

	scanner::Scan input;
	while(true) {
		try {
			y = input.next<double>();
			break;
		} catch(const scanner::InvalidInputException& e) {
			std::cerr << "Double expected\n";
		}
	}

	std::cout << "Congratulations! You entered a double- " << y << "\n";

	return 0;
}
