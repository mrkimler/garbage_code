#include <iostream>
#include <map>

int main() {
	//Pair
	std::pair<int, std::string> p(1, "Phone"); //Пара - связывает два элемента между собой

	std::cout << p.first << '\n';
	std::cout << p.second << '\n';

	//Map
	std::map<int , std::string> myMap; //Является бинарным деревом с доступом к элементу по ключу

	myMap.emplace(2, "Monitor"); //В других контейнерах этот метод тоже есть. Через запятую можно указывать пару. Создаёт объект во время выполнения
	myMap.insert(std::make_pair(0, "Phone")); //Вставить пару
	myMap.insert(std::pair<int, std::string>(1, "Notebook")); //Вставить пару
	myMap.emplace(22, "Keyboard");
	myMap[2] = "Display"; //Если ключа нет - он добавится.

	std::map<int, std::string>::iterator it = myMap.find(22);

	std::cout << it->second << '\n';

	//Элементы в мап можно получить через []
	std::cout << myMap[2] << '\n';
	std::cout << '\n';

	//Multimap
	std::multimap<int, std::string> mm = { //не перегружен []
		{0, "CPU"},
		{0, "Aboba"},
		{1, "GPU"},
		{2, "Motherboard"},
		{3, "Fan"}
	};

	for(std::multimap<int, std::string>::const_iterator it = mm.cbegin(); it != mm.cend(); ++it) {
		std::cout << it->second << '\n';
	}

	return 0;
}
