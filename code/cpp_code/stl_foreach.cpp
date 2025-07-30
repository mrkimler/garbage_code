#include <iostream>
#include <algorithm>

int main() {
    int arr[] = {1, 2, 10, 55};

    std::for_each(arr, std::end(arr), [](int a) {
        std::cout << a << '\n';
    });

    return 0;
}
