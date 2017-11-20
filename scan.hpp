#ifndef SCAN_HPP
#define SCAN_HPP

#include <iostream>
#include <exception>
#include <limits>
#include <cctype>

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
		// function to check if next char input is actually char or int
		bool isNextChar() {
			return (std::cin.peek() >= 33 && std::cin.peek() <= 126);
		}

		//function to clear the buffer stream
		void fix() {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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

	/*************************************************************************************************
	 * Definition of functions in class Scanner
	 *************************************************************************************************/

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
		} else if(!std::isspace(std::cin.peek())) {
			// taking care of any integer followed by a character
			// like so- 123424agger
			// the above should fail the test for ints
			// so check if next character after int is anything but whitespace

			fix();
			throw InvalidInputException();
		}
	}

	template<>
	void Scan::set(double& x) {
		// separate function definition for double to incorporate a similar test to resolve issues like
		// 11.23agger

		std::cin >> x;
		if(std::cin.fail()) {
			fix();
			throw InvalidInputException();
		} else if(!std::isspace(std::cin.peek())) {
			fix();
			throw InvalidInputException();
		}
	}







	/*************************************************************************************************
	 * next function for those who do not want to deal with the class and exception
	 * handling directly, and would prefer it done automatically
	 *************************************************************************************************/


	template<class T>
	T next(const std::string& message = "Invalid datatype entered") {
		Scan input;

		while(true) {
			try {
				T data = input.next<T>();
				return data;
			} catch(const InvalidInputException& e) {
				std::cerr << message << "\n";
			}
		}
	}
}

#endif
