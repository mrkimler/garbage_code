#include "person.hpp"

Person::Person(std::string name, double score) {
    _name = name;
    _score = score;
}

bool Person::operator() (const Person &other) { //Перегруженные () - функтуатор
    return other._score > 50.0;
}

double Person::getScore() const {
    return _score;
}

std::string Person::getName() const {
    return _name;
}

std::vector<Person> getPeople() {
        return {
            Person("Vasya", 90),
            Person("Petya", 15),
            Person("Masha", 89),
            Person("Dasha", 100),
            Person("Katya", 98),
            Person("Andrey", 90),
            Person("Sergey", 25),
            Person("Ivan", 75),
            Person("Stas", 45),
            Person("Andrey", 37)
        };
};
