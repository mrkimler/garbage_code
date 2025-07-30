#include <iostream>
#include <forward_list>

int main() {
	std::forward_list<int> flst; //Односвязный список

	flst.push_front(5); //У forward list нет методов push_back и pop_back
	flst.push_front(10);
	flst.push_front(15);

	std::forward_list<int>::iterator it = flst.begin(); //Есть метод before_begin дающий указатель перед первым элементом, нужно для работы итератора с первым элементом списка (хотя есть pop и push front)

	it++;
	//it-- не перегружен у итератора односвязного списка

	std::cout << *it << "\n\n";
	
	flst.insert_after(it, 20); //Вставить ПОСЛЕ указанного итератора
	
	for(int el : flst) {
		std::cout << el << '\n';
	}

	flst.erase_after(it); //Стереть ПОСЛЕ указанного итератора

	for(int el : flst) {
		std::cout << el << '\n';
	}

	return 0;
}
