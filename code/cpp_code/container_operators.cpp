#include <iostream>
#include <array>



int main() {
	std::array<int, 5> arr = {5, 10, 15, 20, 25};
	std::array<int, 5> arr2 = {5, 10, 15, 20, 25};

	bool result = (arr == arr2); //Если контейнеры имеют полностью одинаковые элементы - true
	bool result2 = (arr > arr2); //Первый элемент который будет различаться с другим списком пройдёт сравнение

	std::cout << result << '\n';
	std::cout << result2 << '\n';

	return 0;
}
