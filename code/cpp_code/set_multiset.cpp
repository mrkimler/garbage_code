#include <iostream>
#include <set>

int main() {
	//Set
	std::set<int> st = {90, 50, 23, 45, 12, 72}; //Представляет собой бинарное дерево. Не может добавлять одинаковые элемнты

	st.insert(25); //Не имеет методов push_back и push_front. Нет перегрузки []. Нет метода at.
	st.insert(75); //Если смог добавить элемент то 1, иначе 0.
	st.insert(38);
	st.insert(13);

	std::set<int>::iterator it = st.find(45); //Возвращает итератор на найденный элемент, иначе на end.

	int val;
	std::cout << "Enter the value to find the element: ";
	std::cin >> val;

	st.erase(90); //Удаляет конкретный элемент возвращая 1, иначе возвращает 0

	if(st.find(val) != st.end()) {
		std::cout << "Value found!\n";
	} else {
		std::cout << "Value not found!\n";
	}

	for(int el : st) {
		std::cout << el << '\n';
	}
	std::cout << '\n';

	//Multiset
	std::multiset<int> mst = {2, 4, 92, 48, 19, 74, 32}; //Модифицированные бинарное дерево, в который можно жобавлять одинаковые элементы

	mst.insert(2);
	mst.insert(2);
	mst.insert(2);

	std::multiset<int>::iterator it1 = mst.lower_bound(2); //Вернёт первый из повторяющихся элементов
	std::multiset<int>::iterator it2 = mst.upper_bound(2); //Вернёт следующий отсортированный элемент после найденного
	std::pair<std::multiset<int>::iterator, std::multiset<int>::iterator> it3 = mst.equal_range(2); //Вернёт диапазон значений от lower до upper bound

	std::cout << *it3.first << '\n';
	std::cout << *it3.second << '\n';

	std::cout << '\n';

	for(int el : mst) {
		std::cout << el << '\n';
	}

	return 0;
}
