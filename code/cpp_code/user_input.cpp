#include <iostream>
#include <cmath>

//cout << (insertion operator)
//cin >> (extraction operator)

int main() {
	std::string name;
	int age;
	double x = 3;
	double y = 6;
	double z;
	double h = 3.64;

	std::cout << "How old are you?: ";
	std::cin >> age;
	
	std::cout << "What's your full name?: ";
	std::getline(std::cin >> std::ws, name);

	std::cout << "Hello " << name << ", " << age << " years old.";

	z = std::max(x, y);
	z = std::min(x, y);
	z = pow(2, 4);
	z = sqrt(9);
	z = abs(-1);
	z = round(h);
	z = ceil(h);

	std::cout << z;

	return 0;
}
