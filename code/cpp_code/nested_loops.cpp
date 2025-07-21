#include <iostream>

int main() {
	/*
		loop() {
			loop() {
			
			}
		}
	*/

	int width;
	int height;

	char symbol;

	std::cout << symbol << '\n';

	for(int i = 1; i <= 3; i++) {
		for(int i = 1; i <= 10; i++) {
			std::cout << i << ' ';
		}
		std::cout << '\n';
	}

	do {
		std::cout << "Enter width of rectangle: ";
		std::cin >> width;
	} while(width <= 0);
	do {
		std::cout << "Enter height of rectangle: ";
		std::cin >> height;
	} while(height <= 0); 
	do {
		std::cout << "Enter symbol for rectangle: ";
        	std::cin >> symbol;
	} while(symbol == ' ');

	for(int i = 0; i <= height - 1; i++) {
		for(int i = 0; i <= width - 1; i++) {
			std::cout << symbol;
		}
		std::cout << '\n';
	}

	return 0;
}
