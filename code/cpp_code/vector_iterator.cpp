#include <iostream>
#include <iterator>
#include <vector>

int main() {
	//Vector

	std::vector<int> myVector = {40, 45, 50, 55, 60, 65, 70};

	myVector.resize(8); //Изменение размера вектора с заполнением 0 или указанным значением

	std::cout << "Count of elements in vector: " << myVector.size() << '\n';
	std::cout << "Capacity of vector: " << myVector.capacity() << '\n'; //Ёмкость вектора

	myVector.push_back(5); //Добавить элемент в конец
	myVector.push_back(10);
	myVector.push_back(15);

	myVector[0] = 20;
	std::cout << "Count of elements in vector: " << myVector.size() << '\n';
	std::cout << "Capacity of vector: " << myVector.capacity() << '\n';

	std::cout << "Vector is empty? " << myVector.empty() << '\n';

	for(int i = 0; i < myVector.size(); i++) { //Получить размер вектора
		std::cout << myVector.at(i) << '\n'; //at всегда проверяет не вышли ли мы за пределы вектора
	}
	std::cout << '\n';

	myVector.clear(); //Очистить вектор
	std::cout << "Vector is empty? " << myVector.empty() << '\n';

	myVector.push_back(25);
	myVector.push_back(30);
	myVector.push_back(35);
	myVector.pop_back(); //Удалить последний элемент

	for(int i = 0; i < myVector.size(); i++) {
		std::cout << myVector.at(i) << '\n';
	}

	myVector.reserve(100); //Зарезервировать ёмкость вектора вручную

	std::cout << "Capacity of vector: " << myVector.capacity() << '\n';
	std::cout << "Count of elements in vector: " << myVector.size() << '\n';

	myVector.shrink_to_fit(); //Уменьшить ёмкость до кол-ва элементов в векторе

	std::cout << "\nCapacity of vector: " << myVector.capacity() << '\n';
	std::cout << "Count of elements in vector: " << myVector.size() << '\n';

	//Iterators

	int arr[] = {75, 80, 85};

	std::cout << '\n' << arr[1] << '\n';
	std::cout << *(arr + 1) << '\n';

	//std::vector<int>::iterator it;

	//it = myVector.begin(); //Передаём итератору указатель на первый элемент вектора

	//*it = 90;
	//it++; //Сдвиг итератора на один элемент вперёд

	//const_iterator - итератор который нельзя изменить (можно изменять элемент, но само значение элемента
	//поменять нельзя)
	//cbegin и cend - версии begin и end для const_iterator
	for(std::vector<int>::const_iterator i = myVector.cbegin(); i != myVector.cend(); i++) {
		std::cout << *i << '\n';
	}

	//reverse_iterator - перевёрнутый итератор и так-же есть версии begin и end под него
	for(std::vector<int>::reverse_iterator i = myVector.rbegin(); i != myVector.rend(); i++) {
		std::cout << *i << '\n';
	}

	myVector.reserve(8);
	std::vector<int>::iterator it = myVector.begin();

	myVector.push_back(100);

	std::cout << *it << '\n';

	std::advance(it, 1); //Сдвинуть итератор на указанное значение эквивалент i += n

	myVector.insert(it, 95); //Вставить на указанный итератор элемент
	std::cout << *it << '\n';

	myVector.erase(it - 1); //Стереть на указанном итераторе элемент

	std::cout << '\n';
	for(it = myVector.begin(); it != myVector.end(); it++) {
		std::cout << *it << '\n';
	}

	return 0;
}
