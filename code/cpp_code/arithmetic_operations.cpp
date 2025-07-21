#include <iostream>

int main() {
	//arithmetic operations - return the result of a specidic
	//arithmetic operations (+ - * /)

	int students = 20;
	int remainder = students % 3;
	int cakes = 6-5+4*3/2;

	double x = (int) 3.14;

	char y = 100;

	students = students + 1;
	students += 1;
	students++;

	students = students - 1;
	students -= 1;
	students--;

	students = students * 2;
	students *= 2;

	students = students / 2;
	students /= 2;

	std::cout << students << '\n';
	std::cout << remainder << '\n';

	//parenthesis
	//multiplication & division
	//addition & subtraction

	std::cout << cakes << '\n';

	/*
	type conversion - conversion a value of one data type to another
	Implicit = automatic
	Explicit = Precade value with new data type (int)
	*/

	std::cout << x << '\n';
	std::cout << y << '\n';
	std::cout << (char) 100 << '\n';

	int questions = 20;
	int correct = 10;
	double percentage = correct*100/questions;

	std::cout << percentage << "%" << '\n';

	return 0;
}
