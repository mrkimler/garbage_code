#include <iostream>
#include <ctime>

int main() {
	int num;
	int guess;
	int tries = 0;
	
	char difficult;

	srand(time(NULL));
	num = rand() % 100 + 1;
	while(tries == 0) {
		std::cout << "Choose difficult:\nE - 15 tries\nM - 12 tries\nH - 8 tries\n:";
		std::cin >> difficult;
		//std::cout << (int) 'E' << '\n' << (int) 'M' << '\n'  << (int)  'H' << '\n';

		switch(difficult) {
			case 'E': tries = 15;
				break;
			case 'M': tries = 12;
				break;
			case 'H': tries = 8;
				break;
		}
	}

	for(int i = 0; i <= tries - 1; i++) {
		std::cout << "Guess the number between 1 to 100: ";
		std::cin >> guess;

		if(guess < 1 || guess > 100) {
			std::cout << "Only between 1 to 100\n";
			i--;
			continue;
		} else if(guess < num) {
			std::cout << "Number is bigger!\n";
		} else if(guess > num) {
			std::cout << "Number is smaller!\n";
		} else if(guess == num) {
			std::cout << "You win!\n";
			break;
		} else {
			std::cout << "What are you doing?\n";
			i--;
			continue;
		}
		
		//std::cout << i << '\n';
	}
	std::cout << "You lose!\n";

	return 0;
}
