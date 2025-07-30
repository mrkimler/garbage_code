#include <thread>
#include <iostream>
#include <chrono>

class MyClass {
public:
    void sum(int a, int b) {
        std::this_thread::sleep_for(std::chrono::microseconds(1000000));
        std::cout << "sumC STARTED\n";

        std::this_thread::sleep_for(std::chrono::microseconds(2000000));
        std::cout << "a+b = " << a + b << '\n';

        std::this_thread::sleep_for(std::chrono::microseconds(1000000));
        std::cout << "sumC END\n";
    }

    void multiply(int &a) {
        std::this_thread::sleep_for(std::chrono::microseconds(1000000));
        std::cout << "multiplyC STARTED\n";

        std::this_thread::sleep_for(std::chrono::microseconds(2000000));
        a *= 2;

        std::this_thread::sleep_for(std::chrono::microseconds(1000000));
        std::cout << "Thread ID: " << std::this_thread::get_id() << "\nmultiplyC END\n";
    }

    int sumR(int a, int b) {
        std::this_thread::sleep_for(std::chrono::microseconds(1000000));
        std::cout << "sumRC STARTED\n";

        std::this_thread::sleep_for(std::chrono::microseconds(2000000));

        std::this_thread::sleep_for(std::chrono::microseconds(1000000));
        std::cout << "sumRC END\n";

        return a+b;
    }
};

void sum(int a, int b) {
    std::this_thread::sleep_for(std::chrono::microseconds(1000000));
    std::cout << "sum STARTED\n";

    std::this_thread::sleep_for(std::chrono::microseconds(2000000));
    std::cout << "a+b = " << a + b << '\n';

    std::this_thread::sleep_for(std::chrono::microseconds(1000000));
    std::cout << "sum END\n";
}

void multiply(int &a) {
    std::this_thread::sleep_for(std::chrono::microseconds(1000000));
    std::cout << "multiply STARTED\n";

    std::this_thread::sleep_for(std::chrono::microseconds(2000000));
    a *= 2;

    std::this_thread::sleep_for(std::chrono::microseconds(1000000));
    std::cout << "Thread ID: " << std::this_thread::get_id() << "\nmultiply END\n";
}

int sumR(int a, int b) {
    std::this_thread::sleep_for(std::chrono::microseconds(1000000));
    std::cout << "sumR STARTED\n";

    std::this_thread::sleep_for(std::chrono::microseconds(2000000));

    std::this_thread::sleep_for(std::chrono::microseconds(1000000));
    std::cout << "sumR END\n";

    return a+b;
}

int main() {
    MyClass th;

    int q = 5;
    int result;
    int resultC;

    std::thread thSum(sum, 2, 3); //После указания функции, через запятую можно указать параметры функции
    std::thread thMultiply(multiply, std::ref(q)); //Создаёт класс, который позволяет нам работать с потоком с передачей параметра по ссылке
    std::thread thSumR([&result]() { result = sumR(2, 3); }); //С помощью лямбда выражения можно возвращать return из функции в потоке
    std::thread thSumRC([&resultC, &th]() { resultC = th.sumR(6, 3); });
    std::thread thSumC(&MyClass::sum, &th, 2, 3);

    for(int8_t i = 0; i < 10; ++i) {
        std::cout << "Thread ID: " << std::this_thread::get_id() << "\tmain\t" << i << '\n';
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    thSum.join();
    thMultiply.join();
    thSumR.join();
    thSumRC.join();
    thSumC.join();

    std::cout << "Result:" << q << '\n';
    std::cout << "Sum result: " << result << '\n';
    std::cout << "Sum class result: " << resultC << '\n';
    return 0;
}
