#include <iostream>

int myNum = 3;

void bakePizza() {
	std::cout << "Here is your pizza!\n";
}

void bakePizza(std::string topping1) {
	std::cout << "Here is your " << topping1 << " pizza!\n";
}

void bakePizza(std::string topping1, std::string topping2) {
	std::cout << "Here is your " << topping1 << " and " << topping2 << " pizza!\n";
}

void printNum() {
	int myNum = 2;
	std::cout << myNum << '\n';
}

int main() {
	bakePizza("pepperoni", "mushroom");

	int myNum = 1;

	//Local variables = declared inside a function or block {}
	//Global variables = declared outside of all functions

	std::cout << myNum << '\n';
	printNum();
	std::cout << ::myNum << '\n';

	return 0;
}
