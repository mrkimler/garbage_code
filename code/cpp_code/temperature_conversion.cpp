#include <iostream>

int main() {
	
	double temp;
	char unit;

	std::cout << "Type the temperature: ";
	std::cin >> temp;
	std::cout << "Type the symbol of measurement (C/F): ";
	std::cin >> unit;

	if(unit == 'F' || unit == 'f') {
		temp = (temp - 32) * 5 / 9;
		std::cout << temp << 'C' << '\n';
	} else if(unit == 'C' || unit == 'c') {
		temp = temp * 9 / 5 + 32;
		std::cout << temp << 'F' << '\n';
	} else {
		std::cout << "This is wrong symbol";
	}

	return 0;
}
