#include <iostream>

void Foo1() {
    std::cout << "Foo1()\n";
}

void Foo2(int a) {
    std::cout << "Foo2() " << a << '\n';
}

int Foo3(int a) {
    return a*2;
}

std::string dataFromDB() {
    return "Data from DB";
}

std::string dataFromWebServer() {
    return "Data from WebServer";
}

std::string dataFromAstral() {
    return "Data from astral";
}

void showInfo(std::string(*data) ()) {
    std::cout << data() << '\n';
}

int main() {
    void(*fPointer) (); //Указатель на функцию. Может принять только функции указанного типа с указанными типами переменыых
    fPointer = Foo1;

    void(*fPointer1) (int);
    fPointer1 = Foo2;

    int(*fPointer2) (int);
    fPointer2 = Foo3;

    std::cout << fPointer2(10) << '\n';
    fPointer1(5);
    fPointer();

    showInfo(dataFromWebServer);
    showInfo(dataFromAstral);
}
