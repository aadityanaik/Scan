#include <iostream>
#include <exception>
#include "scan.hpp"

int main() {
	int x;
	Scanner::Scan input;

	std::cout << "Enter an integer\n";

	x = Scanner::next<int>("Integer expected");
	
	std::cout << "Congratulations! You entered an integer- " << x << std::endl;
}
