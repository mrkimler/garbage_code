#include <iostream>
#include <vector>

int main() {
	//Вектор создаёт массив с неопр. кол-вом значений в нём. 
	//Эффективен при добавлении элементов в конце массива.

	std::vector<int> someArray;

	for(int i = 0; i < 10; i++) {
		someArray.push_back(i);
	}

	for(int value : someArray) {
		std::cout << value << '\n';
	}

	return 0;
}
