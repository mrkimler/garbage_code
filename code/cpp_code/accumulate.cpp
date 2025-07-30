#include <iostream>
#include <numeric>
#include <vector>

int main() {
    std::vector<int> vec = {2, 3, 4, 5, 7, 10};

    int sum = std::accumulate(vec.begin(), vec.end(), 1); //Третий параметр это значение с которым оно работает(точка отсчёта). Изначально работает в режиме сложения.
    int multiply = std::accumulate(std::begin(vec), std::end(vec), 1, [](int a, int b) { //Аналог .begin() только для всего в том числе и для статических массивов
        return a * b;
    });
    int evenSum = std::accumulate(vec.begin(), vec.end(), 0, [](int a, int b) {
        if(!(b % 2)) {
            return a + b;
        }

        return a;
    });
    std::string split_string = std::accumulate(vec.begin() + 1, vec.end(), std::to_string(vec[0]), [](std::string a, int b) { //accumulate сам определяет возвращаемое значение от того, что указано в точке отсчёта (3 параметр)
        return a + "-" + std::to_string(b);
    });

    std::cout << "SUM " << sum << '\n';
    std::cout << "MULTIPLY " << multiply << '\n';
    std::cout << "EVEN_SUM " << evenSum << '\n';
    std::cout << "SPLIT_STRING " << split_string << '\n';

    return 0;
}
