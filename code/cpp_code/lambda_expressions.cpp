#include <iostream>
#include <functional>

void Foo(int a) {
    if(a > 10 && a < 40) {
        std::cout << "FOO " << a << '\n';
    }
}

void Bar(int a) {
    if(a % 2 == 0) {
        std::cout << "BAR " << a << '\n';
    }
}

void Baz(int a) {
    if(a*2 > 100) {
        std::cout << "BAZ " << a << '\n';
    }
}

int sum(int a, int b) {
    return a + b;
}

void doWork(std::vector<int> &vec, std::vector<std::function<void (int)>> algVec) {
    for(int el : vec) {
        for(std::function<void (int)> &fel : algVec) {
            fel(el);
        }
        std::cout << '\n';
    }
}

void doWorkAn(std::vector<int> &vec, std::function<void (int)> func) {
    for(int el : vec) {
        func(el);
    }
}

int main() {
    //std::function
    std::vector<int> vec = {1, 51, 4, 10, 98, 8, 12, 22, 29, 49};
    std::vector<std::function<void (int)>> algVec = {Bar, Baz, Foo, Bar};

    std::function<int(int, int)> s; //void() - сигнатура функции с которой может работать function
    s = sum;

    std::cout << s(5, 5) << "\n\n";

    //Lambda expressions
    std::function<void (int)> f;

    f = [](int a) {
        std:: cout << "Ananonym functions called with parameter: " << a << '\n';
    }; //Анонимная функция. () - параметры, {} - тело. У этой фунции нет имени. Мы можем передать эту
    //функцию параметром в другую функцию. [] - для объявления переменных, которые вне функции.
    //Тип данных возвращаемый функцией определяется с помощью return.

    algVec.emplace_back(f);
    doWork(vec, algVec);

    doWorkAn(vec, [](int a) {
        if(a % 2 == 0) {
            std::cout << "LAMBDA " << a << '\n';
        }
    });

    int p = 0;
    std::function<void ()> lambda = [&p]() {
        p = 5;
    };

    lambda();

    return 0;
}
