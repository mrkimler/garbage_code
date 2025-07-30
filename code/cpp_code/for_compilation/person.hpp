#include <iostream>
#include <vector>

class Person {
public:
    Person(std::string name, double score);
    bool operator() (const Person &other);
    double getScore() const;
    std::string getName() const;
private:
    std::string _name;
    double _score;
};

std::vector<Person> getPeople();
