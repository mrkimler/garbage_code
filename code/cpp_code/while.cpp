#include <iostream>

int main() {
	std::string name;
	int number;

	while(name.empty()) {
		std::cout << "Enter your name: ";
		std::getline(std::cin, name);

	}

	std::cout << "Hello " << name << '\n';

	//do while loop = do some block of code first,
	//THEN repeat again if condition is true

	do {
		std::cout << "Enter a positive number: ";
		std::cin >> number;
	} while(number < 0);

	std::cout << "The number is: " << number << '\n';

	for(int i = 0; i <= 10; i += 2) {
		std::cout << i << '\n';
	}

	std::cout << "HAPPY NEW YEAR!!!\n\n";
	
	//break = break out of loop
	//continue = skip current iteration

	for(int i = 1; i <= 20; i++) {
		if(i == 13) {
			break;
		}
		std::cout << i << '\n';
	}

	for(int i = 1; i <= 20; i++) {
		if(i == 13) {
			continue;
		}
		std::cout << i << '\n';
	}

	return 0;
}
