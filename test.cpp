#include <iostream>
#include <exception>
#include "scan.hpp"

int main() {
	int x;
	Scan input;

	while(true) {
		try {
			x = input.next<int>();
			break;
		} catch(const InvalidInputException& e) {
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << "Congratulations! You entered an integer- " << x << std::endl;
}