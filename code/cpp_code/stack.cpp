#include <iostream>
#include <stack>
#include <deque>
#include <list>

int main() {
	std::stack<int, std::list<int>> st; //По умолчанию использует deque. Можно явно указать, какой контейнер использовать вторым параметром

	st.push(5);
	st.push(10);
	st.push(15);
	st.emplace(20);

	st.pop();

	std::cout << st.size() << "\n\n";

	while(!st.empty()) {
		std::cout << st.top() << '\n'; //Посмотреть элемент
		st.pop();
	}

	return 0;
}
