#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include "../person.hpp"

int main() {
    std::vector<Person> people = getPeople();

    std::vector<int> vec = {6, 4, 4, 12, 1, 2, 7};

    std::vector<int>::iterator it = std::find(vec.begin(), vec.end(), 4); //Поиск элемента в коллекции
    std::vector<int>::iterator itIf = std::find_if(vec.begin(), vec.end(), [](int a) { //В последнем поле принимает предикат
        return a % 2 == 0;
    });
    std::vector<int>::iterator itIfNot = std::find_if_not(vec.begin(), vec.end(), [](int a) { //Меняет результат на противоположный (вместо 1 - 0 и наоборот)
        return a % 2 == 0;
    });
    std::vector<Person>::iterator itP = std::find_if(people.begin(), people.end(), [](const Person &p) {
        return p.getName() == "Masha";
    }); //Обычному файнд не удастся использовать с классами, если оператор сравнения не перегружен.

    std::map<std::string, std::vector<int>::iterator> itMap = {
        {"Find: ", it},
        {"Find if: ", itIf},
        {"Find if not: ", itIfNot},
    };

    for(std::pair<std::string, std::vector<int>::iterator> el : itMap) {
        if(el.second != vec.end()) {
            std::cout << el.first << *el.second << '\n';
        }
    }

    if(itP != people.end()) {
        std::cout << itP->getName() << '\n';
    }
    std::cout << '\n';

    std::vector<Person> result;
    std::vector<Person> resultIf;

    std::copy(people.begin(), people.end(), std::back_inserter(result)); //Копирует из одной коллекции элементы в другую

    std::copy_if(people.begin(), people.end(), std::back_inserter(resultIf), [](const Person &p) {
        //return p.getName() == "Andrey";
        return p.getScore() > 50;
    });
    std::sort(resultIf.begin(), resultIf.end(), [](const Person &p1, const Person &p2) {
       return p1.getScore() > p2.getScore();
    });

    for(const Person &el : result) {
        std::cout << "Name:\t" << el.getName() << "\tScore:\t" << el.getScore() << '\n';
    }
    std::cout << '\n';

    for(const Person &el : resultIf) {
        std::cout << "Name:\t" << el.getName() << "\tScore:\t" << el.getScore() << '\n';
    }

    return 0;
}
