#ifndef SCAN_HPP
#define SCAN_HPP

#include <iostream>
#include <exception>

namespace Scanner {

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
		//function to clear the buffer stream
		void fix() {
			std::cin.clear();
			std::cin.ignore(32767, '\n');
		}

		//function to set the value of a particular x
		template<class T>
		void set(T& x);
		
	public:
		//function that will be used by the user
		template<class T>
		T next() {
			T data;
			set(data);
			return data;
		}
	};
	
	template<class T>
	void Scan::set(T& x) {
		std::cin >> x;
		if(std::cin.fail()) {
			fix();
			throw InvalidInputException();
		}
	}

	//for integers- check if there is a period
	//if so, and if the decimal numbers are not 0, fix
	//else return
	template<>
	void Scan::set(int& x) {
		std::cin >> x;
		if(std::cin.fail()) {
			fix();
			throw InvalidInputException();
		} else if(std::cin.peek() == '.') {
			double dec = next<double>();
			if(dec != 0) {
				fix();
				throw InvalidInputException();
			}
		}
	}
}

#endif
