#include <iostream>

template <typename T>
class List {
public:
	List();
	~List();

	void push_back(T data); //Вставить в конец списка
	void push_front(T data); //Вставить в начала списка
	void insert(T data, int index); //Вставить элемент по индексу
	void pop_front(); //Удалить первый элемент
	void pop_back(); //Удалить последний элемент
	void removeAt(int index); //Удалить элемент по индексу
	void clear(); //Удалить все элементы списка

	int getSize() {
		return _size;
	}

	T & operator[](const int index);

private:
	template <typename>
	class Node { //Узел, элемент односвязного списка
	public:
		Node *_pNext; //указатель на след. элемент
		T _data; //данные элемента

		Node(T data = T(), Node *pNext = nullptr) {
			_data = data;
			_pNext = pNext;
		}
	};

	int _size;
	Node<T> *_head;
};

template <typename T>
List<T>::List() {
	_size = 0;
	_head = nullptr;
}

template <typename T>
List<T>::~List() {
	clear();
}

template <typename T>
void List<T>::push_back(T data) {
	if(_head == nullptr) {
		_head = new Node<T>(data);
	} else {
		Node<T> *current = _head; //передача указателя

		while(current->_pNext != nullptr) {
			current = current->_pNext; //перебор всех элементов пока не nullptr
		}

		current->_pNext = new Node<T>(data); //создание нового указателя
	}

	_size++;
}

template <typename T>
T & List<T>::operator[](const int index) {
	/*
	Мой вариант написания функции:	
	if(index < _size) { //проверка на выход из списка
		Node<T> *current = _head; //передача указателя
		for(int i = 0; i < index; i++) { //перебор до индекса
			current = current->_pNext;
		}

		return current->_data; //возвращаем данные из элемента по индексу
	}

	throw std::runtime_error("Index out of range.");
	*/

	int counter = 0;
	Node<T> *current = _head;

	while(current != nullptr) {
		if(counter == index) {
			return current->_data;
		}
		current = current->_pNext;

		counter++;
	}

	throw std::runtime_error("Index out of range.");
}

template <typename T>
void List<T>::pop_front() {
	Node<T> *temp = _head;

	_head = _head->_pNext;

	delete temp;
	_size--;
}

template <typename T>
void List<T>::clear() {
	while(_size) {
		pop_front();
	}
}

template <typename T>
void List<T>::push_front(T data) {
	_head/*<-Здесь создаётся новый _head, который привязывается к старому _head*/ = new Node<T>(data, _head/*<-- ЭТО СТАРЫЙ УКАЗАТЕЛЬ _head*/);

	_size++;
}

template <typename T>
void List<T>::insert(T data, int index) {
	if(index == 0) {
		push_front(data);
	} else if(index == _size) {
		push_back(data);
	} else if(index > _size) {
		throw std::runtime_error("Index out of range.");
	} else {
		Node<T> *previous = _head;

		for(int i = 0; i < index - 1; i++) {
			previous = previous->_pNext;
		}

		previous->_pNext = new Node<T>(data, previous->_pNext);

		//Node<T> *newNode = new Node<T>(data, previous->_pNext); //Создаём новый элемент с указателем на следующий элемент
		//previous->_pNext = newNode; //Меняем указатель предшествующего элемента _pNext на созданный элемент

		_size++;
	}
}

template <typename T>
void List<T>::removeAt(int index) {
	if(index == 0) {
		pop_front();
	} else {
		Node<T> *previous = _head;

		for(int i = 0; i < index - 1; i++) {
			previous = previous->_pNext;
		}

		Node<T> *toDelete = previous->_pNext; //создаём буфер для удаления
		previous->_pNext = toDelete->_pNext; //передаём в _pNext указатель элемента, который идёт за удаляемым

		delete toDelete;
		_size--;
	}
}

template <typename T>
void List<T>::pop_back() {
	removeAt(_size-1);
}

template <typename T>
inline void print(List<T> &lst) {
	for(int i = 0; i < lst.getSize(); i++) {
		std::cout << "Element" << i << ": " << lst[i] << '\n';
	}
	std::cout << '\n';
}

int main() {
	List<int> lst;
	lst.push_back(10);
	lst.push_back(15);
	lst.push_back(20);
	lst.pop_front();

	std::cout << lst.getSize() << '\n';

	print(lst);

	lst.clear();
	lst.push_back(5);
	lst.push_front(25);
	lst.push_front(30);
	lst.push_front(35);
	lst.insert(40, 2);
	lst.removeAt(2);
	lst.pop_back();

	print(lst);

	return 0;
}
