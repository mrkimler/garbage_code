#include <iostream>

template <typename T, typename U>

auto max(T x, U y) {
	return (x > y) ? x : y;
}

struct student {
	std::string name;
	double gpa;
	bool enrolled = 1;
};

struct Car {
	std::string model;
	int year;
	std::string color;
};

void printCar(Car &car) {
	std::cout << &car << '\n';
	std::cout << car.model << '\n';
	std::cout << car.year << '\n';
	std::cout << car.color << '\n';
}

void paintCar(Car &car, std::string color) {
	car.color = color;
}

int main() {
	//function template = describes what a function looks like.
	//Can be used to generate as many overloaded functions
	//as needed, each using different data types

	std::cout << max(1, 2.1) << '\n';

	/*
	struct = A structure that group related variables under one name
	structs can contain many different data types (string, int, char, etc)
	variables in a struct are known as "members"
	members can be access with . "Class Member Access Operator"
	*/

	student student1;
	student1.name = "Spongebob";
	student1.gpa = 3.2;

	student student2;
	student2.name = "Patrick";
	student2.gpa = 2.1;

	student student3;
	student3.name = "Squidward";
	student3.gpa = 1.5;

	Car car1;
	Car car2;

	car1.model = "Nissan";
	car1.year = 2021;
	car1.color = "black";

	car2.model = "Lada";
	car2.year = 1998;
	car2.color = "cyan";

	paintCar(car1, "red");
	paintCar(car2, "green");

	std::cout << &car1 << '\n';
	printCar(car1);
	std::cout << &car2 << '\n';
	printCar(car2);

	std::cout << student1.name << '\n';
	std::cout << student1.gpa << '\n';
	std::cout << student1.enrolled << '\n';

	std::cout << student2.name << '\n';
	std::cout << student2.gpa << '\n';
	std::cout << student2.enrolled << '\n';

	std::cout << student3.name << '\n';
	std::cout << student3.gpa << '\n';
	std::cout << student3.enrolled << '\n';

	return 0;
}
