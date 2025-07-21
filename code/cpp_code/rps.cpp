#include <iostream>
#include <ctime>

int getComputer() {
	srandom(time(0));

	int choiceComputer = rand() % 3 + 1;
	
	return choiceComputer;
}

int getPlayer() {
	int choicePlayer = 0;
	
	while(!(choicePlayer > 0 && choicePlayer < 4)) {
		std::cout << "Choice the action:\n1. Rock\n2. Paper\n3. Scissors\n: ";
		std::cin >> choicePlayer;
	}

	return choicePlayer;
}

int setStart() {
	int choiceStart = 0;

	while(choiceStart != 1 || choiceStart != 2) {
		std::cout << "Rock, Paper, Scissors game!\n1. StartGame\n2. Exit\n: ";
		std::cin >> choiceStart;
		switch(choiceStart) {
			case 1: std::cout << '\n' << "Welcome to the game!\n";
				return choiceStart;
			case 2: std::cout << '\n' << "Exit...\n";
				return choiceStart;
		}
	}

	std::cout << "Error";
	return 0;
}

void getResult(int choicePlayer, int choiceComputer) {
	std::cout << "Your choice is: ";
	switch(choicePlayer) {
		case 1: std::cout << "Rock\n";
			break;
		case 2: std::cout << "Paper\n";
			break;
		case 3: std::cout << "Scissors\n";
			break;
	}
	
	std::cout << "Computer choice is: ";
	switch(choiceComputer) {
		case 1: std::cout << "Rock\n\n";
			break;
		case 2: std::cout << "Paper\n\n";
			break;
		case 3: std::cout << "Scissors\n\n";
			break;
	}

	//std::cout << choicePlayer << '\n';
	//std::cout << (choicePlayer+1) % 3 + 1 << '\n';

	if(choicePlayer == choiceComputer) {
		std::cout << "Draw\n\n";
	} else if (choiceComputer == (choicePlayer+1) % 3 + 1) {
		std::cout << "You win!\n\n";
	} else {
		std::cout << "You lose!\n\n";
	}
}

bool getRestart() {
	char choice;	
	bool restart;

	std::cout << "Do you want to restart game? (Y/n): ";
	std::cin >> choice;
	
	if(choice == 'y' || choice == 'Y') {
		restart = 1;
	} else {
		restart = 0;
	}

	return restart;
}

int main() {
	int start;
	int player;
	int computer;
	
	bool restart = 1;

	start = setStart();	

	if(start == 2) {
		return 0;
	}

	while(restart) {
		computer = getComputer();
		player = getPlayer();

		getResult(player, computer);
		restart = getRestart();
	}

	return 0;
}
