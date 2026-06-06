#include <iostream>
#include <vector>
//#define TEST

std::vector<int> primal_numbers(int number, std::vector<int> vec) {
    int array[number-3];
    int counter = 0;

    for(int i = 2; i < number-1; i++) {
        array[i-2] = i;
    }

    for(int i = 0, m = 2; m * m <= number; i++, m++) {
        if(array[i] > 0) {
            #ifdef TEST
            std::cout << "true\n";
            #endif

            for(int j = m * m; j <= number; j += m) {
                #ifdef TEST
                std::cout << j << '\t';
                std::cout << array[j-2] << " eliminated\n";
                #endif

                array[j-2] = 0;
            }
        }
    }

    for(int i = 0; i < number-2; i++) {
        if(array[i] != 0) {
            vec.push_back(array[i]);
        }
    }

    #ifdef TEST
    for(int number : vec) {
        counter++;

        if(counter % 10 == 0) {
            std::cout << '\n';
        }
        std::cout << number << '\t';
    }
    #endif

    return vec;
}

int main() {
    int odd = 0;

    do {
        std::cout << "Enter odd number bigger than 5: ";
        std::cin >> odd;
    } while(odd < 7 || odd % 2 == 0);

    int count_schecks = 0;

    std::vector<int> primals_vector;
    primals_vector = primal_numbers(odd, primals_vector);

    int hundreads = 0;
    int tens = 0;
    int units = 0;

    while(true) {
        #ifdef TEST
        std::cout << "TEST\n";
        std::cout << primals_vector[units] << '\n';
        std::cout << primals_vector[tens] << '\n';
        std::cout << primals_vector[hundreads] << "\n\n";
        #endif

        if(primals_vector[hundreads] + primals_vector[tens] + primals_vector[units] == odd) {
            count_schecks++;
        }

        if(primals_vector[units] != primals_vector[primals_vector.size()-1]) {
            units++;
            continue;
        } else if(primals_vector[tens] != primals_vector[primals_vector.size()-1]) {
            tens++;
            continue;
        } else if(primals_vector[hundreads] != primals_vector[primals_vector.size()-1]) {
            hundreads++;
            units = hundreads;
            tens = hundreads;
            continue;
        } else {
            hundreads = odd;
            tens = odd;
            units = odd;
        }

        if(hundreads && tens && units >= odd) {
            std::cout << "Possible ways to get " << odd << " with primal numbers: " << count_schecks << '\n';
            break;
        }
    }
}
