#include <iostream>
#include <ctime>

void drawBoard(char *spaces) {
	int score = 0;	

	std::cout << '\n';

	for(int i = 0; i < 3; i++) {
		std::cout << "     |     |     \n";
		std::cout << "  " << spaces[score] << "  |  "<< spaces[score+1] << "  |  " << spaces[score+2] << "  \n"; 
		
		if(i == 2) {
			std::cout << "     |     |     \n";
		} else {
			std::cout << "_____|_____|_____\n";
		}
		
		score += 3;
	}
	std::cout << '\n';
}

void playerMove(char *spaces, char player) {
	int number;

	do {
		std::cout << "Enter a spot to place a marker (1-9): ";
		std::cin >> number;
		number--;
		if(spaces[number] == ' ') {
			spaces[number] = player;
			break;
		}
	} while(!number > 0 || !number < 8);
}

void computerMove(char *spaces, char computer) {
	int number;
	srand(time(0));
	
	while(true) {
		number = rand() % 9;
		if(spaces[number] == ' ') {
			spaces[number] = computer;
			break;
		}
	}
}

bool checkWinner(char *spaces, char player, char computer) {
	int score = 0;
	bool win = 0;

	for(int i = 0; i < 3; i++) {
		if(spaces[score] != ' ' && spaces[score] == spaces[score + 1] && spaces[score + 1] == spaces[score + 2]) {
			if(spaces[score] == player) {
				std::cout << "YOU WIN!\n";
			} else {
				std::cout << "YOU LOSE!\n";
			}

			return 1;
		} else if (spaces[i] != ' ' && spaces[i] == spaces[i + 3] && spaces[i + 3] == spaces[i + 6]) {
			if(spaces[i] == player) {
				std::cout << "YOU WIN!\n";
			} else {
				std::cout << "YOU LOSE!\n";
			}

			return 1;
		}
		score += 3;
	}

	if (spaces[0] != ' ' && spaces[0] == spaces[4] && spaces[4] == spaces[8]) {
		if(spaces[0] == player) {
			std::cout << "YOU WIN!\n";
		} else {
			std::cout << "YOU LOSE!\n";
		}

		return 1;
	} else if (spaces[2] != ' ' && spaces[2] == spaces[4] && spaces[4] == spaces[6]) {
		if(spaces[2] == player) {
			std::cout << "YOU WIN!\n";
		} else {
			std::cout << "YOU LOSE!\n";
		}

		return 1;
	}

	return 0;
}

bool checkTie(char *spaces) {
	for(int i = 0; i < 9; i++) {
		if(spaces[i] == ' ') {
			return 0;
		}
	}

	std::cout << "IT'S A TIE!\n";
	return 1;
}

int main() {
	char spaces[9] = {};
	std::fill(spaces, spaces + sizeof(spaces)/sizeof(spaces[0]),' ');
	char player = 'X';
	char computer = 'O';
	bool running = true;

	drawBoard(spaces);

	while(running) {
		playerMove(spaces, player);
		drawBoard(spaces);
		if(checkWinner(spaces, player, computer)) {
			running = false;
			break;
		} else if(checkTie(spaces)) {
			running = false;
			break;
		}

		computerMove(spaces, computer);
		drawBoard(spaces);
		if(checkWinner(spaces, player, computer)) {
			running = false;
			break;
		}
	}
	std::cout << "Thanks for playing!\n";

	return 0;
}
