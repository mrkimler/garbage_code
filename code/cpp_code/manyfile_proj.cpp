#include <iostream>
#include "for_compilation/sum.hpp"
#include "for_compilation/myclass.hpp"
#include "for_compilation/Foo.hpp"

int main() {
    int result = sum(2, 3);
    std::string str= "Aboba";

    std::cout << "Sum: " << result << '\n';

    myNameSpace::MyClass myc;

    myc.printMessage("Hello, World!");

    Foo();

    return 0;
}
