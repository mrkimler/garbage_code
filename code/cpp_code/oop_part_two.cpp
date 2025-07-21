#include <iostream>
#include <ctime>

class Image;

class IBicycle {
public:
	virtual void twistTheWheel() = 0;
	virtual void ride() = 0;
};

class MyClass {
public:
	MyClass(int y, int x, int size, char className);

	MyClass() {
		_data = nullptr;

		setID();

		setY(0);
		setX(0);
		setSize(1);
		setName("none");
		setClassName('z');

		std::cout << "No argument constructor " << this << '\n';
	}

	MyClass(char className):MyClass() {
		setClassName(className);

		_objID = -1;

		std::cout << "Constructor of inheritance " << this << '\n';
	}

	MyClass(const MyClass &other) {
		setSize(other._size);
		setY(other._y);
		setX(other._x);
		setClassName(other._className);
		setName("none");

		other._data != nullptr ? _data = new int[other._size] : _data = nullptr;

		setID();

		if(_data && other._data) {
			for(int i = 0; i < other._size; i++) {
				_data[i] = other._data[i];
			}
		}

		std::cout << "Copy constructor " << this << '\n';
	}

	MyClass & operator = (const MyClass &other) {
		setSize(other._size);
		setY(other._y);
		setX(other._x);

		if(_data != nullptr) {
			delete[] _data;
		}

		_data = new int[other._size];

		if(other._data != nullptr) {
			for(int i = 0; i < other._size; i++) {
				_data[i] = other._data[i];
			}
		} else {
			delete[] _data;
			_data = nullptr;
		}

		std::cout << "Operator = " << this << '\n';
	
		return *this;
	}

	bool operator == (const MyClass &other) {
		std::cout << "Operator == " << this << '\n';
		return _x == other._x && _y == other._y;
	}
	bool operator != (const MyClass &other) {
		std::cout << "Operator != " << this << '\n';
		return !(_x == other._x && _y == other._y);
	}
	bool operator <= (const MyClass &other) {
		std::cout << "Operator <= " << this << '\n';
		return _x <= other._x && _y <= other._y;
	}
	bool operator >= (const MyClass &other) {
		std::cout << "Operator >= " << this << '\n';
		return _x >= other._x && _y >= other._y;
	}
	MyClass operator + (const MyClass &other) {
		std::cout << "Operator + " << this << '\n';
		MyClass temp(other._y, other._x, other._size, other._className);

		temp.setX(other._x + _x);
		temp.setY(other._y + _y);

		return temp;
	}
	int & operator[] (int index) {
		return _arr[index];
	}

	void setY(int y) {
		_y = y;
	}
	int getY() {
		return _y;
	}
	void setX(int x) {
		_x = x;
	}
	int getX() {
		return _x;
	}
	void setSize(int size) {
		_size = size;
	}
	int getSize() {
		return _size;
	}
	void setClassName(char className) {
		_className = className;
	}
	char getClassName() {
		return _className;
	}
	static int getCountMyClass() {
		return _countMyClass;
	}
	static void getIDs() {
		std::cout << "IDs: ";
		for(int i = 0; i < _countMyClass; i++) {
			if(i % 3 == 0) {
				std::cout << "\n\t";
			}
			std::cout << _id[i] << ' ';
		}
		std::cout << "\n";
	}
	void setName(std::string name) {
		_name = name;
	}
	std::string getName() {
		return _name;
	}

	virtual void printMyClass() {
		const char name = getClassName();

		std::cout << "\nX." << name << " value: " << getX() << "\nY." << name << " value: " << getY() << '\n';
		std::cout << "size." << name << " value: " << getSize() << '\n' << "Count of classes MyClass: " << _countMyClass << '\n';
		std::cout << "ID: " << _objID << '\n';
		std::cout << "Name: " << _name << "\n\n";
	}

	static void changeName(MyClass &myclass, std::string name) {
		myclass._name = name;
	}

	friend void Change(MyClass &value, Image &valueI);

	~MyClass();
private:
	int _y;
	int _x;
	int *_data;
	int _size;
	int _arr[5] = {9, 8, 7, 6, 5};
	int _objID;
	static int _countMyClass;
	static int *_id;

	char _className;

	std::string _name;

	friend std::ostream & operator<<(std::ostream &of, const MyClass &other);

	void setID() {
		_countMyClass++;

		if(_countMyClass == 1) {
			srand(time(0));
		}

		bool notEquals = 1;

		if(_id == nullptr) {
			_id = new int[_countMyClass];
		};

		while(notEquals) {
			notEquals = 0;
			_id[_countMyClass - 1] = rand();

			for(int i = 0; i < _countMyClass - 1; i++) {
				if(_id[_countMyClass - 1] == _id[i]) {
					notEquals = 1;
					break;
				}
			}
		}

		_objID = _id[_countMyClass - 1];
	}
};

int MyClass::_countMyClass = 0;
int* MyClass::_id = nullptr;

std::ostream & operator<<(std::ostream &of, const MyClass &other) {
	of << other._x << ' ' << other._y;
	return of;
}

MyClass::MyClass(int y, int x, int size, char className):MyClass() {
	_data = new int[size];

	setID();

	setSize(size);
	setY(y);
	setX(x);
	setClassName(className);

	for(int i = 0; i < size; i++) {
		_data[i] = i;
	}

	std::cout << "Constructor: " << this << '\n';
}

MyClass::~MyClass() {
	std::cout << "Destructor " << this << '\n';

	if(_data != nullptr) {
		delete[] _data;
	}

	if(_countMyClass - 1 == 0) {
		delete[] _id;
		_id = nullptr;
	} else if(_objID != -1) {
		_countMyClass--;

		int temp[_countMyClass];

		for(int i = 0; i < _countMyClass; i++) {
			temp[i] = _id[i];
		}
		delete[] _id;

		_id = new int[_countMyClass];

		for(int i = 0; i < _countMyClass; i++) {
			_id[i] = temp[i];
		}
	}
}

void Foo(MyClass value) {
	std::cout << "Foo\n";
}

MyClass Foo2() {
	std::cout << "Foo2\n";
	MyClass a(1, 2, 3, 'a');

	a.printMyClass();

	return a;
}

class CharacterMyClass : public MyClass {
public:
	CharacterMyClass():MyClass('g') {
		setCharacter("none");
	}
	CharacterMyClass(std::string character):MyClass('f') {
		setCharacter(character);
	}

	void printMyClass() override {	
		const char name = getClassName();

		std::cout << "\nX." << name << " value: " << getX() << "\nY." << name << " value: " << getY() << '\n';
		std::cout << "size." << name << " value: " << getSize() << '\n';
		std::cout << "Count of MyClasses: " << getCountMyClass() << '\n';
		std::cout << "Character: " << getCharacter() << '\n';
		std::cout << "Name: " << getName() << "\n\n";
	}

	std::string getCharacter() {
		return _character;
	}
	void setCharacter(std::string character) {
		_character = character;
	}

	~CharacterMyClass() {
	}
private:
	std::string _character;
};

class GunMyClass : public MyClass {
public:
	GunMyClass():MyClass('g') {
		setGun("none");
	}
	GunMyClass(std::string gun):MyClass('f') {
		setGun(gun);
	}

	void printMyClass() override {	
		const char name = getClassName();

		std::cout << "\nX." << name << " value: " << getX() << "\nY." << name << " value: " << getY() << '\n';
		std::cout << "size." << name << " value: " << getSize() << '\n';
		std::cout << "Count of MyClasses: " << getCountMyClass() << '\n';
		std::cout << "Gun: " << getGun() << '\n';
		std::cout << "Name: " << getName() << "\n\n";
	}

	std::string getGun() {
		return _gun;
	}
	void setGun(std::string gun) {
		_gun = gun;
	}

	~GunMyClass() {
	}
private:
	std::string _gun;
};

class Image{
public:
	void getImageInfo() {
		for(int i = 0; i < _length; i++) {
			std::cout << _pixels[i].getInfo() << '\n';
		}
	}

	friend void Change(MyClass &value, Image &valueI);

private:

	class Pixel{
	public:
		Pixel(int r, int g, int b) {
			_r = r;
			_g = g;
			_b = b;	
		}

		std::string getInfo() {
			return "Pixel: r=" + std::to_string(_r) + " g=" + std::to_string(_g) + " b=" + std::to_string(_b);
		}
	private:
		int _r;
		int _g;
		int _b;
	};

	Pixel _pixels[5] {
		Pixel(0, 4, 64),
		Pixel(4, 14, 10),
		Pixel(11, 4, 24),
		Pixel(244, 244, 14),
		Pixel(111, 179, 64)
	};
	
	int _length = 5;
};

void Change(MyClass &value, Image &valueI) {
	value._x = 1;
	valueI._pixels[0] = Image::Pixel(100, 100, 100);
}

template <typename T1, class T2>
class MyTemplate {
public:
	MyTemplate(T1 v1, const T2 &v2) {
		_v1 = v1;
		_v2 = v2;
	}

	void dataTypeSize() {
		std::cout << "Size of value1: " << sizeof(_v1) << '\n';
		std::cout << "Size of value2: " << sizeof(_v2) << '\n';
	}

	T1 Foo() {
		return _v1;
	}

protected:
	T1 _v1;
	T2 _v2;
};

template <typename T1, class T2>
class TypeInfo : public MyTemplate<T1, T2> {
public:
	TypeInfo(T1 v1, T2 v2):MyTemplate<T1, T2>(v1, v2) {

	}

	void showTypeName() {
		std::cout << "Название типа v1: " << typeid(this->_v1).name() << '\n';
		std::cout << "Название типа v2: " << typeid(this->_v2).name() << '\n';
	}
};

class Cap {
public:
	std::string getColor() {
		return _color;
	}
private:
	std::string _color = "red";
};

class Dummy {
public:
	void inspectDummy() {
		std::cout << "Кепка манекена " << cap.getColor() << " цвета\n";
	}
private:
	Cap cap;
};

class Human {
public:
	Human(std::string name) {
		_name = name;
		_age = 0;
		_weight = 0;
	}

	Human(std::string name, int age):Human(name) {
		_age = age;
	}

	Human(std::string name, int age, int weight):Human(name, age) {
		_weight = weight;
	}

	void rideOn(IBicycle &bicycle) {
		std::cout << "Крутим руль\n";
		bicycle.twistTheWheel();
		std::cout << "Поехали\n";
		bicycle.ride();
	}

	void think() {
		brain.think();
	}

	void inspectCap() {
		std::cout << "Моя кепка " << cap.getColor() << " цвета\n";
	}
private:
	class Brain {
	public:
		void think() {
			std::cout << "Я думаю!\n";
		}
	};

	Brain brain;
	Cap cap;

	std::string _name;
	int _age;
	int _weight;
};

class A {
public:
	A() {
	}

	virtual ~A() = 0;
};

A::~A() {};

class B : public A {
public:
	B() {
		std::cout << "Выделена динамическая память, объект класса B\n";
	}

	~B() override {
		std::cout << "Освобождена динамическая память, объект класса B\n";
	}
};

class SimpleBicycle : public IBicycle {
public:
	void twistTheWheel() override {
		std::cout << "метод twistTheWheel() SimpleBicycle\n";
	}

	void ride() override {
		std::cout << "метод ride() SimpleBicycle\n";
	}
};

class Component {
public:
	Component(std::string companyName) {
		std::cout << "Construcor of Component\n";
		setCompanyName(companyName);
	}

	void setCompanyName(std::string companyName) {
		_companyName = companyName;
	}
private:
	std::string _companyName;
};

class GPU : public Component {
public:
	GPU(std::string companyName):Component(companyName) {
		std::cout << "Constructor of GPU\n";
	}
};

class Memory : public Component {
public:
	Memory(std::string companyName):Component(companyName) {
		std::cout << "Constructor of Memory\n";
	}
};

class GraphicCard : public GPU, public Memory {
public:
	GraphicCard(std::string GPUCompanyName, std::string memoryCompanyName):GPU(GPUCompanyName),Memory(memoryCompanyName) {
		std::cout << "Constructor of GraphicCard\n";
	}
};

class MyException : public std::runtime_error {
public:
	MyException(const char *msg, int dataState):std::runtime_error(msg){
		_dataState = dataState;
	}

	int getDataState() {
		return _dataState;
	}
private:
	int _dataState;
};

void Foo3(int value) {
	if(value < 0) {
		throw std::runtime_error("Check1: number lower than 0!");
	} else if(value == 0) {
		throw "Check2: number equals 0!";
	} else if(value == 1) {
		throw MyException("Check 3: number equals 1!", value);
	} 

	std::cout << "Variable: " << value << '\n';
}

class PC {
public:
	enum PCState {
		OFF,
		ON,
		SLEEP
	};

	int getState() {
		return _state;
	}
	void setState(PCState state) {
		_state = state;
	}
private:
	PCState _state;
};

namespace firstNS {
	void Foo() {
		std::cout << "Foo FirstNS.\n";
	}

	int a;

	class Point {

	};
}

namespace secondNS {
	void Foo() {
		std::cout << "Foo SecondNS.\n";
	}

	int b;

	class Point {

	};
}

namespace thirdNS {
	namespace secondNS {
		void Foo() {
			std::cout << "Foo ThirdNS.\n";
		}
	}
}

namespace fourthNS {
	void Foo4() {
		std::cout << "Foo fourth.\n";
	}
}

using namespace fourthNS;

template <class T1>
class Printer {
public:
	void print(T1 v1) {
		std::cout << v1 << '\n';
	}
};

template <>
class Printer<std::string> {
public:
	void print(std::string v1) {
		std::cout << "___" << v1 << "___\n";
	}
};

struct MyStruct1 {
	MyStruct1() {

	}

	int a = 22;

	void print() {
		std::cout << a << '\n';
	}

	~MyStruct1() {

	}
};

struct MyStruct2 : MyStruct1 {

};

class List {
public:
	List();
	~List();
private:

	template <typename T>
	class Node {
	public:
		Node *_pNext;
		T _data; 

		Node(Node *pNext, T data) {}
	};
};

List::List() {

}

List::~List() {

}

int main() {
	MyClass b(1, 2, 3, 'b');
	b.setY(2);
	b.setX(3);

	MyClass c(1, 2, 3, 'c');
	MyClass d(2, 4, 6, 'd');
	MyClass e;

	c = d;

	bool check = c == d;
	bool check2 = b == d;
	bool checkN = c != d;
	bool checkN2 = b != d;

	const int length = 5;

	MyClass arr[length];
	CharacterMyClass f1("Puge");
	GunMyClass f2("Hook");
	PC pc;
	pc.setState(pc.PCState::ON);
	Printer<std::string> printer;

	Human human("Аристарх", 30, 70);
	Dummy dummy;
	Image image;
	A *bptr = new B;
	SimpleBicycle bicycle1;
	GraphicCard gc("AMD", "Saphire");

	MyStruct2 ms;

	ms.print();

	delete bptr;

	std::string name = "Kimler";

	d = b + c;

	bool checks[] = {check, check2, checkN, checkN2};

	for(int i = 0; i < sizeof(checks)/sizeof(checks[0]); i++) {
		std::cout << "Check" << i + 1 << ": " << checks[i] << '\t';
		std::cout << "Array" << i << ": " << d[i] << '\n';
	}

	Foo(b);
	Foo2();

	b.printMyClass();
	c.printMyClass();
	d.printMyClass();

	Change(d, image);
	image.getImageInfo();
	d.printMyClass();

	MyTemplate<int, MyClass> template1(1, e);
	TypeInfo<int, double> template2(1, 1.1);

	MyClass::changeName(e, name);
	MyClass::getIDs();
	e.printMyClass();
	f1.printMyClass();
	f2.printMyClass();

	template1.dataTypeSize();
	template2.showTypeName();
	template2.dataTypeSize();

	int number = template1.Foo();

	arr[0] = b;
	arr[1] = c;
	arr[2] = d;
	arr[3] = e;

	for(MyClass element : arr) {
		std::cout << element << '\n';
	}

	human.think();
	human.inspectCap();
	dummy.inspectDummy();
	human.rideOn(bicycle1);

	try {
		Foo3(-1);
	} catch(MyException &ex) {
		std::cout << "We catch1: " << ex.what() << '\n';
		std::cout << "Data state is: " << ex.getDataState() << '\n';
	} catch(const char* ex) {
		std::cout << "We catch2: " << ex << '\n';
	} catch(const std::exception &ex) {
		std:: cout << "We catch3: " << ex.what() << '\n';
	} catch(...) {
		std::cout << "Something goes wrong.\n";
	} 

	switch(pc.getState()) {
		case pc.PCState::ON: std::cout << "PC is on!\n";
			break;
		case pc.PCState::OFF: std::cout << "PC is off!\n";
			break;
		case pc.PCState::SLEEP: std::cout << "PC is sleep!\n";
			break;
	}

	firstNS::Foo();
	secondNS::Foo();
	thirdNS::secondNS::Foo();
	Foo4();

	printer.print("Some string!");

	return 0;
}
