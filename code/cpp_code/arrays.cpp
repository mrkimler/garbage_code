#include <iostream>

double getTotal(double prices[], int size) {
	double total = 0;

	for(int i = 0; i < size; i++) {
		total += prices [i];
	}

	return total;
}

int searchArray(int array[], int size, int element) {
	for(int i = 0; i < size; i++) {
		if(array[i] == element) {
			return i;
		}
	}

	return -1;
}

int main() {
	//array = a data structure that can hold multiple values
	//values accessed by an index number 
	//"kind of like variable that holds multiple values"

	std::string car[] = {"Mazda", "Mercedes", "Nissan"};

	car[0] = "Lexus";
	
	for(int i = 0; i < 3; i++) {
		std::cout << car[i] << '\n';
	}

	//sizeof() = determines the size in bytes of a:
	//variable, data type, class, objects, etc.

	double gpa = 2.5;
	std::string name = "Kimler";
	char grade = 'F';
	bool student = 1;
	char grades[] = {'A', 'B', 'C', 'D', 'F'};
	std::string students[] = {"Spongebob", "Patrick", "Squidward"};

	std::cout << sizeof(gpa) << " bytes\n";
	std::cout << sizeof(name) << " bytes\n";
	std::cout << sizeof(grade) << " bytes\n";
	std::cout << sizeof(student) << " bytes\n";
	std::cout << sizeof(grades) << " bytes\n";
	std::cout << sizeof(students) << " bytes\n";

	for(int i = 0; i < sizeof(students)/sizeof(std::string); i++) {
		std::cout << students[i] << '\n';
	}

	//foreach loop = loop that eases the traversal over an
	//iterable data set

	for(std::string student : students) {
		std::cout << student << '\n';
	}

	double prices[] = {49.99, 15.05, 75, 9.99};
	double total;
	int size = sizeof(prices)/sizeof(double);

	total = getTotal(prices, size);

	std::cout << "Р" << total << '\n';

	int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int size1 = sizeof(numbers)/sizeof(int);
	int index;
	int myNum;
	
	std::cout << "Enter the number to search for: ";
	std::cin >> myNum;

	index = searchArray(numbers, size1, myNum);

	if(index != -1) {
		std::cout << myNum << " is at index " << index << '\n';
	} else {
		std::cout << myNum << " is not in the array" << '\n';
	}

	return 0;
}
