#include <iostream>

int getDigital(const int number) {
	//std::cout << number / 10 % 10 << '\n';
	return number % 10 + (number / 10 % 10);
}

int sumEven(const std::string codeNumber) {
	int sum = 0;

	for(int i = codeNumber.length() - 1; i >= 0; i -= 2) {
		sum += codeNumber[i] - 48;
	}

	return sum;
}

int sumOdd(std::string codeNumber) {
	int sum = 0;

	for(int i = codeNumber.length() - 2; i >= 0; i -= 2) {
		sum += getDigital((codeNumber[i] - 48) * 2);
	}

	return sum;
}

int main() {
	std::string codeNumber;
	int result = 0;

	std::cout << "Enter credit card cod number: ";
	std::cin >> codeNumber;

	result = sumOdd(codeNumber) + sumEven(codeNumber);

	if(result % 10 == 0) {
		std::cout << codeNumber << " is valid\n";// << result;
	} else {
		std::cout << codeNumber << " is not valid\n";// << result;
	}
}
