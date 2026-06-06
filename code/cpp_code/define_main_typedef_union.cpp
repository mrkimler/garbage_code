#include <iostream>
#define PI 3.14159
#define nl '\n' //Определение замены для компилятора. Т.е. вместо '\n' можно писать nl
#define FOO(x, y) ((x)*(y)) //Определение функции

int main(int argc, char* argv[]) { //argc - кол-во аргументов после вызова исполняемого файла. argv - хранить значения введёные после исполняемого файла
    std::cout << PI << nl;

    std::cout << FOO(2, 3);

    std::cout << '\n';
    for(int i = 0; i < argc; ++i) {
        std::cout << argv[i] << '\t';
    }
    std::cout << '\n';

    std::system("ping 8.8.8.8");
    return 0;
}
