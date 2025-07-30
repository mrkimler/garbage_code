#include <iostream>
#include <thread> //Работа с потоками
#include <chrono> //Работа с временем
//#include <fstream>

void doWork() {
    for(size_t i = 0; i < 10; ++i) {
        std::cout << "ID of thread: " << std::this_thread::get_id() << "\tdoWork " << i << '\n';
        /*
        std::ifstream fin;
        fin.open("spam", std::ifstream::app);
        if(!fin.is_open()) {
            std::cout << "Failed to open\n";
        } else {
            while(!fin.eof()) {
                std::string str = "";
                getline(fin, str);
                std::cout << str;
            }
        }
        */
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}

int main() {
    std::cout << "START MAIN" << '\n';

    std::thread th(doWork);
    std::thread th2(doWork);
    //th.detach(); //Прервать поток по завершению основного потока

    for(size_t i = 0; i < 10; i++) {
        std::cout << "ID of thread: " << std::this_thread::get_id() << "\tmain " << i << '\n'; //Узнать какой сейчас поток
        std::this_thread::sleep_for(std::chrono::milliseconds(500)); //Остановить поток на опр. кол-во времени в мс
    }

    th.join(); //Прерывает другие потоки вклинивая себя. Если два таких потока, они будут работать вместе.
    th2.join();

    std::cout << "END MAIN" << '\n';
    return 0; //Завершение основного потока быстрее т.к. каждый элемент перебирается со скоростью 0.5с, а не 1с.
}
