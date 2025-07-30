#include <iostream>
#include <array>

int main() {
	std::array<int, 10> arr = {5, 10, 15, 20, 25, 30, 35, 40, 45, 50}; //Мы не можем добавлять новые элементы и удалять существующие. Т.е. не можем менять его размер никоим образом. К примеру из 10 значений сделать 9/11 мы не можем.
	try {
		std::cout << arr.at(5) << '\n';
		std::cout << arr.size() << '\n';
	} catch(const std::exception &ex) {
		std::cout << ex.what() << '\n';
	}

	for(int el : arr) {
		std::cout << el << '\n';
	}

	arr.fill(0); //Заполнить весь массив опр. значением

	arr[0] = 1;
	arr[9] = 10;

	std::cout << "Front: " << arr.front() << '\n'; //Получить доступ к первому элементу массива
	std::cout << "Back: " << arr.back() << '\n'; //Получить доступ к последнему элементу массива

	for(int el : arr) {
		std::cout << el << '\n';
	}

	return 0;
}
