#include <iostream>

enum Day {
	monday = 0,
	tuesday = 1,
	wednesday = 2,
	thursday = 3,
	friday = 4,
	saturday = 5,
	sunday = 6
};

int main() {
	//enums = a user-defined data type that consists
	//of paired named-integer constants.
	//GREAT if you have a set of potentional options

	Day today = monday;

	switch(today) {
		case monday: std::cout << "It is monday!\n";
			break;
		case tuesday: std::cout << "It is tuesday!\n";
			break;
		case wednesday: std::cout << "It is wednesday!\n";
			break;
		case thursday: std::cout << "It is thursday!\n";
			break;
		case friday: std::cout << "It is friday!\n";
			break;
		case saturday: std::cout << "It is saturday!\n";
			break;
		case sunday: std::cout << "It is sunday!\n";
			break;
	}

	return 0;
}
