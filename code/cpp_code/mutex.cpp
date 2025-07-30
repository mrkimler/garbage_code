#include <iostream>
#include <mutex>
#include <thread>

std::mutex mtx; //Не позволяет сразу двум потокам работать с какой-то функцией или обработкой

void print(char ch) {
    std::this_thread::sleep_for(std::chrono::milliseconds(2000)); //Это может взять n потоков

    mtx.lock(); //Место где мы указываем, что больше потоки не принимаем

    for(int i = 0; i < 5; ++i) {
        for(int j = 0; j < 10; ++j) {
            std::cout << ch;
            std::this_thread::sleep_for(std::chrono::milliseconds(20));
        }
        std::cout << '\n';
    }
    std::cout << '\n';

    mtx.unlock(); //Место где мы указываем, что мы снова принимает потоки.

    std::this_thread::sleep_for(std::chrono::milliseconds(2000)); //Это может взять n потоков
}

int main() {
    std::thread th1(print, '*');
    std::thread th2(print, '@');

    th1.join();
    th2.join();
    return 0;
}
