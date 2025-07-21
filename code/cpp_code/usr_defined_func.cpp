#include <iostream>

void happyBirthday(std::string name, int age) {
	for(int i = 0; i <= 3; i++) {
		std::cout << "Happy " << age << " Birthday to you, " << name << "!\n";
	}
}

double square(double length) {
	return length * length;
}

double cube(double length) {
	return length * length * length;
}

std::string concatStrings(std::string string1, std::string string2) {
	return string1 + " " + string2;
}

int main() {
	//function = a block of reusable code

	std::string name = "Kimler";
	std::string firstName = "Kimler";
	std::string lastName = "Tutov";
	std::string fullName = concatStrings(firstName, lastName);

	int age = 21;

	double length = 5.0;
	double area = square(length);
	double volume = cube(length);

	happyBirthday(name, age);

	//return = return a value back to the spot
	//where you called the encompassing (охватывающую) 
	//function

	std::cout << "Area: " << area << "cm^2\n";
	std::cout << "Volume: " << volume << "cm^3\n";
	std::cout << "Fullname: " << fullName << '\n';

	return 0;
}
