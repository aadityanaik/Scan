#include <iostream>
#include <exception>
#include "scan.hpp"

int main() {
	int x;
	Scan input;

	while(true) {
		try {
			x = input.next<double>();
			break;
		} catch(...) {
			std::cout <<"Wrong input datatype" << std::endl;
		}
	}

	std::cout << x << std::endl;
}