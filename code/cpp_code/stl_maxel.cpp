#include <iostream>
#include <algorithm>
#include <list>
#include <vector>

int main() {
    std::vector<int> vec = {10, 1, -55, 11, 13, 58};
    std::list<int> lst = {4, 7, 77, -3, 44, 74};
    const int size = 6;

    int arr[size] = {10, 1, -55, 13, 58};

    std::vector<int>::iterator itV = std::max_element(vec.begin(), vec.end()); //Возврващет самый большой по значению элемент
    std::vector<int>::iterator itVmi = std::min_element(vec.begin(), vec.end()); //Возвращает самый маленький по значению элемент
    std::list<int>::iterator itL = std::max_element(lst.begin(), lst.end());
    std::pair<std::list<int>::iterator, std::list<int>::iterator> itLmm = std::minmax_element(lst.begin(), lst.end()); //Возвращает два элемента соответственно
    int *max = std::max_element(arr, arr + size);

    std::cout << *itV << '\n';
    std::cout << *itVmi << '\n';
    std::cout << *itL << '\n';
    std::cout << *max << '\n';
    std::cout << "Min list: " << *itLmm.first << "\tMax List: " << *itLmm.second << '\n';

    return 0;
}
