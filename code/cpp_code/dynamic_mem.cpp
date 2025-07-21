#include <iostream>

void walk(int steps) {
	for(int i = 0; i < steps; i++) {
		std::cout << "You take a step!\n";
	}
}

void walkR(int steps) {
	if(steps > 0) {
		std::cout << "You take a step!\n";
		walk(steps - 1);
	}
}

int factorial(int number) {
	if(number > 1) {
		return number * factorial(number - 1);
	} else {
		return number;
	}
}

int factorialI(int number) {
	int count = number;

	for(int i = 1; i < count; i++) {
		number *= count - i;
	}

	return number;
}

int main() {
	/*
	dynamic memory = Memory that is allocated after the programm
	is already compiled & running. Use the 'new' operator to alocate
	memory in the heap rather than the stack.

	Useful when we don't know how much memory we fill need. Makes
	our programs more flexible, especially when accepting user input.
	*/

	int *pNum = NULL;
	char *pGrades = NULL;
	int size;

	pNum = new int;

	std::cout << "How many grades to enter in?: ";
	std::cin >> size;

	pGrades = new char[size];

	for(int i = 0; i < size; i++) {
		std::cout << "Enter grade #" << i + 1 << ": ";
		std::cin >> pGrades[i];
	}

	for(int i = 0; i < size; i++) {
		std::cout << pGrades[i] << " ";
	}
	std::cout << '\n';

	delete[] pGrades;

	*pNum = 21;

	std::cout << "address: " << pNum << '\n';
	std::cout << "value: " << *pNum << '\n';

	delete pNum;

	/*
	recursion = a programming technique where a function
	invokes itself from within break a complex concept
	into repeatable single step

	(iterative vs recursive)

	advantages = +less code and is cleaner
	             +usefull for sorting and searching 
		     algorithms

	disadvantages = -uses more memory
			-slower
	*/

	walk(5);
	walkR(5);

	int number;

	std::cout << "Factorial of number?: ";
	std::cin >> number;

	std::cout << factorialI(number) << '\n';
	std::cout << factorial(number) << '\n';

	return 0;
}
