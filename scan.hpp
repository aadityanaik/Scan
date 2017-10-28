#ifndef SCAN_HPP
#define SCAN_HPP

//an adaptation of cin to make accepting input less hectic
class Scan {
private:
	void fix() {
		std::cin.clear();
		std::cin.ignore(32767, '\n');
	}

	template<class T>
	void set(T& x) {
		std::cin >> x;
		if(std::cin.fail()) {
			fix();
			throw "Wrong datatype entered!!!";
		}
	}

public:
	template<class T>
	T next() {
		T x;
		set(x);
		return x;
	}
};

#endif