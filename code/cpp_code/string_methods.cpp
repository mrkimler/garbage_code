#include <iostream>

int main() {
	std::string name;

	std::cout << "Enter your name: ";
	std::getline(std::cin, name);

	if(name.length() > 12){
		std::cout << "Your name can't be over 12 characters\n";
	} else if(name.empty()) {
		std::cout << "Your name is empty\n";
	} else {
		std::cout << "Welcome " << name << '\n';
	}

	name.clear();
	
	if(name.empty()) {
		std::cout << name << "Empty\n";
	}
	
	name.append("This is append!");
	
	std::cout << name << '\n';
	std::cout << name.length() << '\n';

	for(int i = 0; i <= name.length() - 1; i++) {
		std::cout << name.at(i);
	}

	name.insert(6, " (INSert) ");
	name.erase(11, 3);

	std::cout << '\n' << name << '\n';
	std::cout << name.find(' ') << '\n';

	return 0;
}
