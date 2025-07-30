#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>

std::mutex mtx;
std::mutex mtxD1;
std::mutex mtxD2;

void print(char ch) {
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));

    {
        std::lock_guard<std::mutex> guard(mtx); //Сам выполнит lock и unlock

        std::cout << "LOCK_GUARD\n";
        for(int i = 0; i < 5; ++i) {
            for(int j = 0; j < 10; ++j) {
                std::cout << ch;
                std::this_thread::sleep_for(std::chrono::milliseconds(20));
        }
            std::cout << '\n';
        }
        std::cout << '\n';
    } //Ограничение зоны видимости lock guard

    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
}

void print1() {
    std::lock_guard<std::mutex> guard(mtx);
    mtxD1.lock(); //Если поменять местами, то произойдёт следующее
    //Тут мы сразу захватываем mtxD2, там мы захватываем mtxD2
    std::this_thread::sleep_for(std::chrono::milliseconds(1)); //Без задержки может проканать, но рано или поздно баг возникнет

    //Тут mtxD2, но он уже захвачен в print2. А там будет mtxD1, но он уже захвачен
    //тут. В результате в это вот буфере происходит DeadLock и вся программа виснет
    mtxD2.lock();

    //Так что обязатально надо соблюдать последовательность локов мьютексов.
    std::cout << "DEADLOCK\n";
    for(int i = 0; i < 5; ++i) {
        for(int j = 0; j < 10; ++j) {
            std::cout << '&';
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
        std::cout << '\n';
    }
    std::cout << '\n';

    mtxD2.unlock();
    mtxD1.unlock();
}

void print2() {
    std::lock_guard<std::mutex> guard(mtx);
    mtxD1.lock();
    std::this_thread::sleep_for(std::chrono::milliseconds(1));

    mtxD2.lock();

    std::cout << "DEADLOCK\n";
    for(int i = 0; i < 5; ++i) {
        for(int j = 0; j < 10; ++j) {
            std::cout << '#';
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
        std::cout << '\n';
    }
    std::cout << '\n';

    mtxD2.unlock();
    mtxD1.unlock();
}

void printU(char ch) {
    std::unique_lock<std::mutex> unique(mtx, std::defer_lock); //Он может принимать различные методы в отличии от lock_guard

    std::this_thread::sleep_for(std::chrono::milliseconds(2000));

    unique.lock();
    std::cout << "UNIQUE_LOCK\n";
    for(int i = 0; i < 5; ++i) {
        for(int j = 0; j < 10; ++j) {
            std::cout << ch;
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
        std::cout << '\n';
    }
    std::cout << '\n';
    unique.unlock();

    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
}

int main() {
    std::thread th1(print, '*');
    std::thread th2(print, '@');

    std::thread thD1(print1);
    std::thread thD2(print2);

    std::thread thU1(printU, '^');
    std::thread thU2(printU, '"');

    th1.join();
    th2.join();
    thD1.join();
    thD2.join();
    thU1.join();
    thU2.join();
    return 0;
}
