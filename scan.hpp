#ifndef SCAN_HPP
#define SCAN_HPP

#include <iostream>
#include <exception>

//custom exception
class InvalidInputException : public std::exception {
public:
	const char* what() const throw() {
		return "Invalid datatype entered";
	}
};

//an adaptation of cin to make accepting input less hectic
class Scan {
private:
	void fix() {
		std::cin.clear();
		std::cin.ignore(32767, '\n');
	}

	template<class T>
	void set(T& x);

public:
	template<class T>
	T next() {
		T x;
		set(x);
		return x;
	}
};

template<class T>
inline void Scan::set(T& x) {
	std::cin >> x;
	if(std::cin.fail()) {
		fix();
		throw InvalidInputException();
	}
}

template<>
inline void Scan::set(int& x) {
	std::cin >> x;
	if(std::cin.fail() || std::cin.peek() == '.') {
		fix();
		throw InvalidInputException();
	}
}

#endif