#include <iostream>
#include <cmath>

int main() {
	double cat_1;
	double cat_2;
	double hyp;
	
	std::cout << "Value of catete 1: ";
	std::cin >> cat_1;
	std::cout << "Value of catete 2: ";
	std::cin >> cat_2;

	hyp = sqrt(pow(cat_1, 2) + pow(cat_2, 2));

	std::cout << hyp;

	return 0;
}
