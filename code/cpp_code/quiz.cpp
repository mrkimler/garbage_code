#include <iostream>

char userInput() {
	char answer;

	std::cout << "Enter answer: ";
	std::cin >> answer;
	answer = toupper(answer);

	std::cout << '\n';

	return answer;
}

int checkAnswer(char userAnswers[], char correctAnswers[], int sizeCA) {
	int counter = 0;

	for(int i = 0; i < sizeCA; i++) {
		if(userAnswers[i] == correctAnswers[i]) {
			counter += 1;
		}
	}

	return counter;
}

void display(std::string questions[], std::string options[][4], char userAnswers[], int sizeOR, int sizeOC) {
	for(int i = 0; i < sizeOR; i++) {
		std::cout << questions[i] << "\n\n";
		for(int j = 0; j < sizeOC; j++) {
			std::cout << options[i][j] << '\n';
		}
		userAnswers[i] = userInput();
	}
}

int main() {
	std::string questions[] = 
		{"1. What year was C++ created?: ", 
		"2. Who invented C++?: ", 
		"3. What is the predecessor of C++: ", 
		"4. Is the Earth flat?: "};
	std::string options[][4] = {
		{"A. 1969", "B. 1975", "C. 1985", "D. 1989"},
		{"A. Guido van Rossum", "B. Bjarne Stroustrup", "C. John Carmack", "D. Mark Zeuckerburg"},
		{"A. C", "B. C+", "C. C--", "D. B++"},
		{"A. Yes", "B. No", "C. Sometimes", "D. What's Earth?"}
	};
	char correctAnswers[] = {'C', 'B', 'A', 'B'};
	char userAnswers[4];
	int counter;
	int sizeOR;
	int sizeOC;
	int sizeCA;

	sizeOR = sizeof(options)/sizeof(options[0]);
	sizeOC = sizeof(options[0])/sizeof(options[0][0]);
	sizeCA = sizeof(correctAnswers)/sizeof(correctAnswers[0]);

	display(questions, options, userAnswers, sizeOR, sizeOC);

	counter = checkAnswer(userAnswers, correctAnswers, sizeCA);

	std::cout << "Right answers: " << counter << "/4\n";

	return 0;
}
