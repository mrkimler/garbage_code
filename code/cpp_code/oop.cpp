#include <iostream>

class Human {
public:
	std::string name;
	std::string occupation;
	int age;

	void eat() {
		std::cout << "This person is eating\n";
	}

	void drink() {
		std::cout << "This person is drinkig\n";
	}

	void sleep() {
		std::cout << "This person is sleeping\n";
	}
};

class Car {
public:
	std::string _make;
	std::string _model;
	int _year;
	std::string _color;

	Car(std::string make, std::string model, int year, std::string color) {
		_make = make;
		_model = model;
		_year = year;
		_color = color;
	}

	void accelerate() {
		std::cout << "You step on the gas\n";
	}

	void brake() {
		std::cout << "You step on the brake\n";
	}
};

class Student {
public:
	std::string _name;
	int _age;
	double _gpa;

	Student(std::string name, int age, double gpa) {
		_name = name;
		_age = age;
		_gpa = gpa;
	}
};

class Pizza {
public:
	std::string _topping1;
	std::string _topping2;

	Pizza() {
	}

	Pizza(std::string topping1) {
		_topping1 = topping1;
	}

	Pizza(std::string topping1, std::string topping2) {
		_topping1 = topping1;
		_topping2 = topping2;
	}
};

class Stove {
public:
	Stove(int temperature) {
		setTemperature(temperature);
	}

	int getTemperature() {
		return _temperature;
	}

	void setTemperature(int temperature) {
		if(temperature < 0) {
			_temperature = 0;
		} else if (temperature >= 10) {
			_temperature = 10;
		} else {
			_temperature = temperature;
		}
	}

private:
	int _temperature = 0;
};

class Animal {
public:
	bool getAlive() {
		return _alive;
	}
	void setAlive(bool alive) {
		_alive = alive;
	}

	void eat() {
		std::cout << "This animal is eating\n";
	}

private:
	bool _alive = 1;
};

class Dog : public Animal {
public:
	void bark() {
		std::cout << "The dog goes woof!\n";
	}
};

class Cat : public Animal {
public:
	void meow() {
		std::cout << "The cat goes meow!\n";
	}
};

int main() {
	/*
	object = A collection of attributes and methods
	
	They can have characteristics and could perform actions
	Can be used to mimic real world items (ex. Phone, Book, Statue, etc)
	Created from a class which acts as a "blue-print"
	*/

	Human human1;
	Human human2;

	Car car1("АвтоВАЗ", "Жигуль", 1998, "тёмно-синий");

	human1.name = "Rick";
	human1.occupation = "scientist";
	human1.age = 70;

	human2.name = "Morty";
	human2.occupation = "schoolkid";
	human2.age = 15;

	std::cout << human2.name << '\n';
	std::cout << human2.occupation << '\n';
	std::cout << human2.age << '\n';

	human2.eat();
	human2.drink();
	human2.sleep();

	std::cout << car1._make << '\n';
	std::cout << car1._model << '\n';
	std::cout << car1._year << '\n';
	std::cout << car1._color << '\n';

	car1.accelerate();
	car1.brake();

	//constroctor = special method that is automatically called when an object is instantiated
	//useful for assigning values to attributes as arguments

	Student student1("Spongebob", 25, 3.2);
	Student student2("Patrick", 40, 1.5);
	Student student3("Sandy", 21, 4.0);

	std::cout << student1._name << '\n';
	std::cout << student1._age << '\n';
	std::cout << student1._gpa << '\n';

	//overloaded constructors = multiple constructors w/ same name but different parameters
	//allows for varying arguments when instantiating an object

	Pizza pizza1("pepperoni");
	Pizza pizza2("pepperoni", "mushrooms");
	Pizza pizza3;

	std::cout << pizza1._topping1 << '\n';
	std::cout << pizza2._topping2 << '\n';

	//Abstraction = hiding unnecessary data from outside a class
	//getter = function that makes a private attribute READABLE
	//setter = function that makes a private attribute WRITEABLE

	Stove stove(0);

	stove.setTemperature(15);

	std::cout << "The temperature setting is: " << stove.getTemperature() << '\n';

	//inheritance = A class can recieve attributes and methods from another class
	//Children classes inherit from a Parent class
	//Helps to reuse similiar code found within multiple classes

	Dog dog;
	Animal animal;
	Cat cat;

	std::cout << dog.getAlive() << '\n';
	dog.eat();
	dog.bark();
	cat.meow();

	return 0;
}
