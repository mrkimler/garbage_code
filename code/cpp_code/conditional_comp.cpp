#include <iostream>
#define DEBUG 5 //Определяем

int main() {
#ifndef DEBUG //Если есть то запускаем, иначе пропускаем
    std::cout << "DEBUG not define!\n";
#else
    std::cout << "Start of loop\n";
#endif //Конец выражения

    for(int i = 0; i < 4; ++i) {
        std::cout << i << '\n';
    }

#ifdef DEBUG
    std::cout << "End of loop\n";
#endif

#if DEBUG > 3
    std::cout << "Bigger than 3!";
#elif DEBUG < 3 //Иначе если
    std::cout << "Lesser than 3!";
#endif
    return 0;
}
