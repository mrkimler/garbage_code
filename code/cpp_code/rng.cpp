#include <iostream>
#include <ctime>

int main() {
	//pseudo-random = NOT truly random (but clode)

	srand(time(NULL));
	
	int num = (rand() % 6) + 1;

	std::cout << num << '\n';

	return 0;
}
