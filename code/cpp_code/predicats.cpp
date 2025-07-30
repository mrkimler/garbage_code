#include <iostream>
#include <algorithm>
#include <vector>
#include "for_compilation/person.hpp"

class MyFunctor {
public:
    int operator() (int a, int b) {
        std::cout << "I am functor! " << count << '\n';
        ++count;

        return a + b;
    }

private:
    int count = 0;

};

class EvenFunctor {
public:
    void operator() (int value) {
        if(value % 2 == 0) {
            _evenSum += value;
            _evenCount++;
        }
    }

   void showEvenSum() {
       std::cout << "Summ of even numbers: " << _evenSum << '\n';
   }

   void showEvenCount() {
       std::cout << "Count of even numbers: " << _evenCount << '\n';
   }
private:
    int _evenSum = 0;
    int _evenCount = 0;
};

bool greaterThanZero(int val) { //Предикатор - возвращает логическое true или false
    return val > 0;
}

bool lessThanZero(int val) {
    return val < 0;
}

int main() {
    //Functor
    MyFunctor f;

    std::cout << f(2, 2) << '\n'; //Функтор это перегрузка оператора ()
    std::cout << f(3, 6) << '\n';
    std::cout << f(1, 0) << '\n';

    int arr[] = {5, 10, 15, 20, 25};
    std::vector<Person> people = getPeople();

    EvenFunctor ef;

    for(int el : arr) {
        ef(el);
    }

    ef.showEvenCount();
    ef.showEvenSum();

    //Predicator
    std::cout << greaterThanZero(1) << '\n';
    std::cout << greaterThanZero(-1) << '\n';

    std::vector<int> vec = {30, 35, -40, -45, 50};

    std::cout << std::count_if(vec.begin(), vec.end(), greaterThanZero) << '\n';
    std::cout << std::count_if(vec.begin(), vec.end(), lessThanZero) << "\n\n"; //Подсчитывает сколько элементов в коллекции соответствует предикатору

    std::cout << std::count_if(people.begin(), people.end(), people.front()); //Реализация предикатора через функтор

	return 0;
}
