#include <iostream>
#include <list>

template <typename T>
void printLst(const std::list<T> &lst) {
	for(typename std::list<T>::const_iterator i = lst.cbegin(); i != lst.cend(); ++i) {
		std::cout << *i << '\n';
	}
	std::cout << '\n';
}

int main() {
	std::list<int> lst = {15, 20, 25}; //Двусвязный список, не может работать с []

	lst.push_back(5);
	lst.push_front(10); //Вставить элемент в начале

	std::list<int>::iterator it = lst.begin();

	std::cout << *it << "\n\n";

	lst.sort(); //Отсортировать лист
	
	lst.pop_back(); //Удалить последний элемент
	lst.pop_front(); //Удалить первый элемент

	lst.push_back(30);
	lst.push_back(30);
	lst.push_front(30);

	lst.unique(); //Оставляет в последовательности одинаковых значений одно

	printLst(lst);

	lst.reverse(); //Сортирует исходные элмементы списка {15, 20, 25} от большего к меньшему

	printLst(lst);

	lst.clear();
	lst.push_back(45);
	lst.push_front(40);
	lst.push_back(35);
	lst.insert(it, 50);

	it++; //Итератор двусвязного списка можно сдвигать только по 1
	it++;
	it--;

	std::advance(it, +2);

	lst.insert(it, 55);

	std::advance(it, -2);

	lst.erase(it);
	lst.remove(50); //Удалить конкретный элемент
	lst.push_back(65);
	lst.push_back(70);

	printLst(lst);

	lst.assign(3, 60); //Стереть список и заполнить его опр. значением в опр. кол-ве

	std::list<int> lst2 = {1, 2, 3, 4, 5, 6, 7};

	lst2.assign(lst.begin(), lst.end()); //Копирование списка в другой список

	printLst(lst);
	printLst(lst2);

	return 0;
}
