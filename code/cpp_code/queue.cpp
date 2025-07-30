#include <iostream>
#include <queue>
#include <deque>
#include <list>

int main() {
	std::queue<int, std::list<int>> que; //По умолчанию используется deque, не может работать с vector

	que.emplace(5);
	que.emplace(10);
	que.emplace(15);
	que.emplace(20);

	que.pop();

	std::cout << que.back() << '\n';
	std::cout << que.front() << "\n\n";

	while(!que.empty()) {
		std::cout << "Value: " << que.front() << '\n';
		std::cout << "Size of queue: " << que.size() << '\n';
		
		que.pop();
	}
	std::cout << "Size of queue: " << que.size() << "\n\n";

	std::priority_queue<int, std::vector<int>> pque; //Не может использоваться с list

	pque.push(25);
	pque.push(15);
	pque.push(34);
	pque.push(1);

	while(!pque.empty()) {	
		std::cout << "Value: " << pque.top() << '\n';
		std::cout << "Size of queue: " << pque.size() << '\n';
		
		pque.pop();
	}
	std::cout << "Size of queue: " << que.size() << "\n\n";

	return 0;
}
