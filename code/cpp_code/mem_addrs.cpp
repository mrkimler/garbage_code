#include <iostream>

void swap(std::string &x, std::string &y) {
	std::string temp;

	temp = x;
	x = y;
	y = temp;
}

void printInfo(const std::string name, const int age) {
	//name = " ";
	//age = 0;

	std::cout << name << '\n';
	std::cout << age << '\n';
}

int main() {
	//memory address = a location in memory where data is stored
	//a memory address can accessed with & (address-of operator)

	std::string name = "Kimler";
	std::string x = "Kool-Aid";
	std::string y = "Water";
	std::string temp;
	int age = 21;
	bool student = 1;
	bool state = 0;

	std::cout << &name << '\n';
	std::cout << &age << '\n';
	std::cout << &student << '\n';
	std::cout << &state << '\n';

	swap(x, y);

	std::cout << "X: " << x << '\n';
	std::cout << "Y: " << y << '\n';

	//const parameter = parameter that is effectively read-only
	//code is more secure & conveys intent useful for references
	//and pointers

	printInfo(name, age);

	return 0;
}
