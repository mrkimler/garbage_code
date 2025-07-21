#include <iostream>

void getCard(std::string &numberCard) {
	std::cout << "Write credit card number: ";
	std::cin >> numberCard; 
}

int evenSum(std::string numberCard) {
	int count = 1;
	int numbers[numberCard.length()] = {};
	int size;
	int sum = 0;

	for(int i = 0; i < numberCard.length(); i++) {
		if(numberCard.length() % 2 == 0) {
			numberCard.erase(count, 1);
			count += 1;
		} else if(numberCard.length() % 2 == 1) {
			numberCard.erase(count, 1);
			count += 1;
		}
	}
	count = 0;

	for(int i = 0; i < numberCard.length(); i++) {
		numbers[i] = (int) numberCard.at(numberCard.length() - 1 - i) - 48;
		numbers[i] *= 2;
	}

	size = sizeof(numbers)/sizeof(numbers[0]);

	for(int i = 0; i < size; i++) {
		if(numbers[i] > 9) {
			numbers[i] = numbers[i] % 10;
			numbers[size/2 + count] = 1;
			count += 1;
		}
	}

	for(int i = 0; i < size; i++) {
		sum += numbers[i];
	}

	return sum;
}

int oddSum(std::string numberCard) {
	int count = 0;
	int numbers[numberCard.length()/2] = {};
	int sum = 0;

	for(int i = 0; i < numberCard.length(); i++) {
		if(numberCard.length() % 2 == 0) {
			numberCard.erase(count, 1);
			count += 1;
		} else if(numberCard.length() % 2 == 1) {
			numberCard.erase(count, 1);
			count += 1;
		}
	}

	for(int i = 0; i < numberCard.length(); i++) {
		numbers[i] = (int) numberCard.at(numberCard.length() - 1 - i) - 48;
	}

	for(int i = 0; i < sizeof(numbers)/sizeof(numbers[0]); i++) {
		sum += numbers[i];
	}

	return sum;
}

int main() {
	std::string numberCard;

	getCard(numberCard);
	std::cout << numberCard.size() << '\n';

	int even = evenSum(numberCard);
	int odd = oddSum(numberCard);

	if((even + odd) % 10 == 0) {
		std::cout << numberCard << " is valid" << '\n';
	} else {
		std::cout << numberCard << " is not valid" << '\n';
	}

	std::cout << even+odd << '\n';

	return 0;
}
