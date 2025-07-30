#include <iostream>
#include <algorithm>
#include <vector>
#include "for_compilation/person.hpp"

int main() {
    std::vector<Person> people = getPeople();
	std::vector<int> vec = {9, 4, 94, 6, 1, 3, 7};
	std::sort(vec.begin(), vec.end(), [](int a, int b) { //Бинарный предикат
	    return a > b;
	}); //Сортирует коллекцию. Последним параметром принимает
	//бинарный предикат, для сравнения между собой значений, для сортировки.

	for(int el : vec) {
	    std::cout << el << '\n';
	}
	std::cout << '\n';

	const int size = 7;
	int arr[size] = {9, 4, 94, 6, 1, 3, 7};

	std::sort(arr, arr + size);

	for(int el : arr) {
	    std::cout << el << '\n';
	}

	std::sort(people.begin(), people.end(), [](const Person &p1, const Person &p2) {
	    return p1.getName() < p2.getName();
	});

	for(Person el : people) {
	    std::cout << "Name:\t" << el.getName() << "\tScore:\t" << el.getScore() << '\n';
	}

	return 0;
}
