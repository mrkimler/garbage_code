#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

class Point {
public:
    Point(int x, int y) {
        _x = x;
        _y = y;
    }

    int getX() const {
        return _x;
    }
    int getY() const {
        return _y;
    }

private:
    int _x;
    int _y;
};

int main() {
    //Equal/Mismatch
    int arr[] = {3, 10, 7, 5, 4};
    std::vector<int> arr2 = {10, 3, 4, 5, 7, 11};

    std::sort(arr, std::end(arr));
    std::sort(arr2.begin(), arr2.end());

    bool result = std::equal(arr, std::end(arr), std::begin(arr2)); //Сравнивает коллекции между собой, если не указывать конец второй коллекции
    //то если первая коллекция меньше второй и все значения равны(до превышения элементов у второй коллекции), то вернётся true
    //несмотря на то, что вторая коллекция больше. Он проверяет индекс к индексу.

    bool result2 = std::equal(arr, std::end(arr), std::begin(arr2), std::end(arr2));
    std::pair<int*, std::vector<int>::iterator> resultMis = std::mismatch(arr, std::end(arr), arr2.begin(), arr2.end()); //Возвращает два элемента, из первой и второй
    //коллекции, которые не соответствуют друг-другу. При равенстве вернёт end()

    std::cout << "ARR\t";
    for(int el : arr) {
        std::cout << el << '\t';
    }
    std::cout << '\n';

    std::cout << "ARR2\t";
    for(int el : arr2) {
        std::cout << el << '\t';
    }
    std::cout << '\n';

    std::cout << result << '\n';
    std::cout << result2 << '\n';
    std::cout << "FIRST " << *resultMis.first << "\tSECOND " << *resultMis.second << "\n\n";

    //Equal predicate

    std::vector<Point> arrP1 {
        Point(1, 6),
        Point(1, 3),
        Point(5, 7),
        Point(4, 5),
        Point(1, 6)
    };

    std::vector<Point> arrP2 {
        Point(1, 6),
        Point(5, 7),
        Point(1, 6),
        Point(1, 3),
        Point(4, 5)
    };

    std::sort(arrP1.begin(), arrP1.end(), [](const Point &p1, const Point &p2) {
        return p1.getX() > p2.getX() || p1.getY() > p2.getY();
    });
    std::sort(arrP2.begin(), arrP2.end(), [](const Point &p1, const Point &p2) {
        return p1.getX() > p2.getX() || p1.getY() > p2.getY();
    });

    bool resultP = std::equal(arrP1.begin(), arrP1.end(), arrP2.begin(), arrP2.end(), [](const Point &p1, const Point &p2) {
        return p1.getX() == p2.getX() && p1.getY() == p2.getY();
    });

    for(int i = 0; i < arrP1.size() && arrP2.size(); ++i) {
        std::cout << "X1: " << arrP1[i].getX() << " | X2: " << arrP2[i].getX();
        std::cout << "     ||\tY1: " << arrP1[i].getY() << " | Y2: " << arrP2[i].getY();
        std::cout << '\n';
    }

    std::cout << resultP << '\n';

    return 0;
}
