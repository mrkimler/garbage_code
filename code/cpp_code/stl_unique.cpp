#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    int arr[] = {1, 2, 2, 2, 5, 4, 4};
    int arr2[4];

    std::vector<int> arrV1 = {1, 2, 2, 2, 5, 4, 4};
    std::vector<int> arrV2;

    int* result = std::unique(arr, std::end(arr)); //Оставляет в последовательностях одинаковых значений одно значение.
    //Кол-во элементов не меняет, а лишь заменяет ненужные элементы на нужные. Ненужную часть можно убрать в дальнейшем.
    std::copy(arr, result, arr2);

    std::unique_copy(arrV1.begin(), arrV1.end(), back_inserter(arrV2));

    for(; result != std::end(arr); result++) {
        std::cout << *result << '\n';
    }
    std::cout << '\n';

    for(int el : arr2) {
        std::cout << el << '\n';
    }
    std::cout << '\n';

    for(int el : arrV2) {
        std::cout << el << '\n';
    }

    return 0;
}
