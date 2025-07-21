#include <iostream>

int main() {
	
	//ternary operator ?: = replacement to an if/else statement
	//condition ? expression1 : expression2;

	int grade = 75;
	int number;
	int temp;

	bool hungry = 1;	
	bool sunny = 1;

	grade >= 60 ? std::cout << "You pass!" << '\n' : std::cout << "You fail!" << '\n';
	
	//std::cout << "I try to goes it's even or odd, type your numer: ";
	//std::cin >> number;
	//number % 2 == 0 ? std::cout << "Even" << '\n' : std::cout << "Odd" << '\n';
	//number % 2 ? std::cout << "ODD" << '\n' : std::cout << "EVEN" << '\n';
	//hungry ? std::cout << "You are hungry" : std::cout << "You are full";
	std::cout << (hungry ? "You are hungry" : "You are full") << '\n';
	
	//&& = check if two conditions are true (logical AND)
	//|| = check if at lest one of two conditions is true (logical OR)
	//! = reverses the logical state of its operand (logical NOT)

	std::cout << "Enter the temeprature: ";
	std::cin >> temp;

	if(temp > 0 && temp < 30) {
		std::cout << "The temperature is good" << '\n';
	} else {
		std::cout << "The temperature is bad" << '\n';
	}

	if(temp <= 0 || temp >= 30) {
		std::cout << "The temperature is bad" << '\n';;
	} else {
		std::cout << "The temperature is good" << '\n';
	}

	if(!sunny) {
		std::cout << "Is is cloudy outside!";
	} else {
		std::cout << "It is sunny outside!";
	}

	return 0;
}
