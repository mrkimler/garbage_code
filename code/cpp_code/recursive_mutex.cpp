#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

std::recursive_mutex rmtx; //Позволяет много раз залочить один и тот же поток. Но потом столько же раз надо разлочить.

void Foo(int a) {
    rmtx.lock();
    std::cout << a << ' ' << std::flush;

    std::this_thread::sleep_for(std::chrono::milliseconds(300));

    if(a <= 1) {
        std::cout << '\n';

        rmtx.unlock();
        return;
    }

    Foo(--a);
    rmtx.unlock();
}

int main() {
    std::thread th(Foo, 5);
    std::thread th2(Foo, 7);

    th.join();
    th2.join();
    return 0;
}
