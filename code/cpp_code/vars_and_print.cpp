#include <iostream>

int main() {

	//This is a comment
	/*
		This
		is
		a
		multi-line
		comment
	*/

	std::cout << "I like spaghetti" << '\n';
	std::cout << "It's really good!" << '\n';
	
	int x; //declaretion
	x = 5; //assigment

	//integer (whole number)	
	int y = 6;
	int sum = y+x;
	int age = 21;
	int year = 2023;
	int days = 7;

	//double (number including decimals)
	double price = 10.99;
	double gpa = 2.5;
	double temperature = 25.1;

	//single character
	char grade = 'A';
	char initial = 'B';
	char currency = '$';

	//boolean (true or false)
	bool student = 0;
	bool power = 1;
	bool forSale = 1;

	//string (objects that represents a sequence of text)
	std::string name = "Bro";
	std::string day = "Thursday";
	std::string food = "spghetti";
	std::string addr = "123 Fake SL.";

	std::cout << x << std::endl;
	std::cout << y << std::endl;
	std::cout << sum << std::endl;

	std::cout << price << std::endl;	

	std::cout << initial << std::endl;

	std::cout << name << std::endl;
	std::cout << "Hello " << name << ", your " << age << " years old." << std::endl;

	return 0;
}
