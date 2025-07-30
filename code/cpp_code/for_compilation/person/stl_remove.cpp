#include <iostream>
#include <algorithm>
#include <vector>
#include "../person.hpp"

int main() {
    std::vector<Person> people = getPeople();

    std::vector<int> vec = {5, 9, 1, 46, 4, 9, 4};

    std::vector<int>::iterator it = std::remove(vec.begin(), vec.end(), 9); //Передаёт в итератор все элементы удовлетворяющие условию
    vec.erase(it, vec.end()); //Удаляем эти элементы

    for(int el : vec) {
        std::cout << el << '\n';
    }

    std::vector<Person>::iterator itP = std::remove_if(people.begin(), people.end(), [](const Person &p) {
        return p.getScore() < 50;
    }); //С условием
    people.erase(itP, people.end());

    for(Person el : people) {
        std::cout << "Name:\t" << el.getName() << "\tScore:\t" << el.getScore() << '\n';
    }

    return 0;
}
