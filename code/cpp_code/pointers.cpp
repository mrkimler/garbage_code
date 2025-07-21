#include <iostream>

int main() {
	//pointers = variable that stores a memory address of another variable
	//sometimes it's easier to work with an address

	//& adress-of operator
	//* dereference operator

	std::string name = "Kimler";
	int age = 21;
	std::string freePizzas[5] = {"pizza1", "pizza2", "pizza3", "pizza4", "pizza5"};

	std::string *pName = &name;
	int *pAge = &age;
	std::string *pFreePizzas = freePizzas;

	std::cout << pName << '\n';
	std::cout << *pName << '\n';
	std::cout << *pAge << '\n';
	std::cout << freePizzas << '\n';
	std::cout << pFreePizzas << '\n';
	std::cout << *pFreePizzas << '\n';

	//Null value = a special value that means something has no value.
	//When a pointer is holding a null value, that pointer is not
	//pointing at anything (null pointer)

	//nullptr = keyword represents a null pointer literal

	//nullptrs are helpful when determining if an address
	//was successfully assigned to a pointer

	int *pointer = nullptr;
	int x = 123;

	pointer = &x;

	if(pointer == nullptr){
		std::cout << "address was not assigned!\n";
	} else {
		std::cout << "address was assigned!\n";
	}

	return 0;
}
