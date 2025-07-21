#include <iostream>
#include <memory>

template <typename T>
class SmartPointer {
public:
	SmartPointer(T *ptr) {
		_ptr = ptr;
		std::cout << "Constructor" << '\n';
	}

	~SmartPointer() {
		delete _ptr;
		std::cout << "Destructor" << '\n';
	}

	T & operator*() {
		return *_ptr;
	}

private:
	T *_ptr;
};

/*
smart pointers:
auto_ptr
unique_ptr
shared_ptr
*/

int main() {
	SmartPointer<int> pointer = new int(5);

	*pointer = 10;

	std::cout << *pointer << '\n';

	std::auto_ptr<int> ap1(new int(20));
	std::auto_ptr<int> ap2(ap1);

	int *ptr1 = ap1.get();
	int *ptr2 = ap2.get(); 

	std::cout << ptr1 << '\t' << *ptr2 << '\n';

	std::unique_ptr<int> up1(new int(15));
	std::unique_ptr<int> up2;

	up2 = std::move(up1);

	std::cout << up1.get() << '\t' << *up2.get() << '\n';

	std::unique_ptr<int> up3(new int(30));
	std::unique_ptr<int> up4;

	up4.swap(up3);

	ptr1 = up3.get();
	ptr2 = up4.get();

	std::cout << ptr1 << '\t' << *ptr2 << '\n';

	int *ptr3 = new int(25);

	std::unique_ptr<int> up5(ptr3);
	up5.release();

	std::cout << up5.get() << '\t' << *ptr3 << '\n';

	std::unique_ptr<int> up6(ptr3);
	up6.reset();

	std::cout << up6.get() << '\t' << *ptr3 << '\n';

	std::shared_ptr<int> sp1(new int(35));
	std::shared_ptr<int> sp2(sp1);

	std::cout << *sp1.get() << '\t' << *sp2.get() << '\n';

	int size;
	std::cout << "Enter the size of array: ";
	std::cin >> size;

	std::shared_ptr<int[]> sp3(new int[size] {1, 2, 3, 4, 5});
	std::shared_ptr<int[]> sp4(sp3);

	for(int i = 0; i < size; i++) {
		sp3[i] = rand() % 10;
		std::cout << sp3[i] << '\n';
	}

	return 0;
}
