#include <iostream>

int main() {
	//fill() = Fills a range of elements with a specific value
	//fill(begin, end, value)

	const int size = 100;
	int pizza_count = 0;
	int hamburger_count = 0;
	int hotdog_count = 0;

	std::string foods[size];

	for(std::string food : foods) {
		std::cout << food << " ";
	}
	std::cout << "\n\n";

	for(int i = 0; i < size; i++) {
		foods[i] = "pizza";
	}

	for(std::string food : foods) {
		std::cout << food << " ";
	}
	std::cout << "\n\n";

	fill(foods, foods + size/3, "pizza");
	fill(foods + size/3, foods + size/3*2, "hamburger");
	fill(foods + size/3*2, foods + size, "hotdog");

	for(std::string food : foods) {
		std::cout << food << " ";
	}

	for(int i = 0; i < size; i++){
		if(foods[i] == "pizza") {
			pizza_count += 1;
		} else if(foods[i] == "hamburger") {
			hamburger_count += 1;
		} else if(foods[i] == "hotdog") {
			hotdog_count += 1;
		}
		//std::cout << i << '\n' << size << '\n';
	}

	std::cout << "\n\n" << pizza_count << " pizzas\n" << hamburger_count << " hamburgers\n" << hotdog_count << " hotdogs\n";

	std::string foods1[5];

	int size1 = sizeof(foods1)/sizeof(std::string);
	//std::cout << '\n' << size1 << "size\n\n";
	std::string temp;

	for(int i = 0; i < size1; i++) {
		std::cout << "Enter a food you like ot 'q' to quit #" << i << ": ";
		std::getline(std::cin, temp);

		if(temp == "q") {
			break;
		} else {
			foods1[i] = temp;
		}
	}

	std::cout << "You like the following food:\n";

	for(int i = 0; !foods1[i].empty(); i++) {
		std::cout << foods1[i] << '\n';
	}

	return 0;
}
