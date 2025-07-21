#include <iostream>
#include <iomanip>
#include <climits>

void showBalance(double balance) {
	std::cout << "Your balance is: Р"<< std::setprecision(2) << std::fixed << balance << '\n';
}

double deposit() {
	double amount = 0;

	std::cout << "Enter amount to be deposited: ";
	std::cin >> amount;

	if(amount > 0) {
		return amount;
	} else {
		std::cout << "That's not a valid amount.\n";
		return 0;
	}

	return amount;
}

double withdraw(double balance) {
	double amount = 0;

	std::cout << "Enter amount to be withdrawn: ";
	std::cin >> amount;

	if(amount < balance && amount > 0) {
		return amount;
	} else {
		std::cout << "That's not a valid amount.\n";
		return 0;
	}
}

int main() {
	double balance = 123.45;
	int choice = 0;


	do {
		std::cout << "Enter your choice:\n";
		std::cout << "1. Show Balance\n";
		std::cout << "2. Deposit Money\n";
		std::cout << "3. Withdraw Money\n";
		std::cout << "4. Exit\n" << ": ";
		std::cin >> choice;

		std::cin.clear();
		fflush(stdin);
		std::cin.ignore(INT_MAX, '\n');

		switch(choice) {
			case 1: showBalance(balance); 
				break;
			case 2: balance += deposit();
				showBalance(balance);
				break;
			case 3: balance -= withdraw(balance);
				showBalance(balance);
				break;
			case 4: std::cout << "Thanks for visiting!\n";
				break;
			default: std::cout << "Invalid choice\n"; 
		}
	} while(choice != 4);

	return 0;
}
