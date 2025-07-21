#include <iostream>
#include <fstream>
#include <climits>

class Point {
public:
	Point() {
		_x = _y = _z = 0;
	}

	Point(int x, int y, int z) {
		_x = x;
		_y = y;
		_z = z;
	}

	void print() {
		std::cout << "X: " << _x << "\nY: " << _y << "\nZ: " << _z << '\n';
	}

private:
	int _x;
	int _y;
	int _z;

	friend std::ostream & operator << (std::ostream &os, const Point &point);
	friend std::istream & operator >> (std::istream &is, Point &point);
};

std::ostream & operator << (std::ostream &os, const Point &point) {
	os << point._x << " " << point._y << " " << point._z;

	return os;
}

std::istream & operator >> (std::istream &is, Point &point) {
	is >> point._x >> point._y >> point._z;

	return is;
}

int main() {
	int a;
	int write_or_read = 0;
	const std::string path = "generated_files/";
	const std::string my_file = path + "my_file";
	const std::string obj_file = path + "obj_file";
	const std::string fs_file = path + "fs_file";
	const std::string fs_obj_file = path + "fs_obj_file";
	const std::string no_file = path + "no_file";
	std::string str;
	std::string msg;
	char ch;
	char choose;
	std::ofstream fout;
	std::ifstream fin;
	std::fstream fs;
	const Point point(5, 10, 15);

	std::cout << "Do you want to enter the number? (Y/n): ";
	std::cin >> choose;
	choose = std::toupper(choose);

	fout.open(my_file, std::ofstream::app);
	if(choose == 'Y') {
		if(!fout.is_open()) {
			std::cout << "Error of opening file.\n";
		} else {
			std::cout << "Enter the number: ";
			std::cin >> a;

			fout << "\nThe number of choosen by user: " << a;
		}
	}
	fout.close();
	fout.clear();

	fin.open(my_file);

	if(!fin.is_open()) {
		std::cout << "Error of opening file.\n";
	} else {
		std::cout << "File is open!\n";

		while(!fin.eof()) {
			str = "";
			std::getline(fin, str);
			std::cout << str << '\n';
		}
		std::cout << '\n';
	}

	fin.close();
	fin.clear();

	std::cout << "File is closed!\n";

	fout.open(obj_file, std::ofstream::app);
	if(!fout.is_open()) {
		std::cout << "Error of opening file.\n";
	} else {
		std::cout << "Obj file is open!\n";

		fout.write((char*) &point, sizeof(Point));
	}
	fout.close();
	fout.clear();

	std::cout << "Obj file is closed!\n";

	fin.open(obj_file);

	if(!fin.is_open()) {
		std::cout << "Error of opening file.\n";
	} else {
		std::cout << "Obj file is open!\n";
		Point temp;

		while(fin.read((char*) &temp, sizeof(Point))) {
			temp.print();
		}
	}
	fin.close();
	fin.clear();

	std::cout << "Obj file is closed!\n";

	fs.open(fs_file, std::fstream::in | std::fstream::out | std::fstream::app);

	if(!fs.is_open()) {
		std::cout << "Error of opening file.\n";
	} else {
		std::cout << "Fs file is open!\n";

		while(write_or_read < 1 || write_or_read > 2) {
			std::cout << "1 for read.\n";
			std::cout << "2 for write.\n";
			std::cout << ": ";
			std::cin >> write_or_read;

			if(std::cin.fail()) {
				std::cin.clear();
				fflush(stdin);
				std::cin.ignore(INT_MAX, '\n');
			}
		}

		if(write_or_read == 1) {
			while(!fs.eof()) {
				str = "";
				std::getline(fs, str);
				std::cout << str << '\n';
			}
		} else {
			std::cout << "Write message!\n" << ": ";
			std::getline(std::cin >> std::ws, msg);
			fs << msg << '\n';
		}
	}
	fs.close();
	fs.clear();

	std::cout << "Fs file is closed!\n";

	fs.open(fs_obj_file, std::fstream::out | std::fstream::app);
	if(!fs.is_open()) {
		std::cout << "Error of opening file.\n";
	} else {
		std::cout << "Fs obj file is open!\n";

		fs << point << '\n';
		fs.close();

		fs.open(fs_obj_file, std::fstream::in);
		while(true) {
			Point temp;

			fs >> temp;
			if(fs.eof()) {
				break;
			}

			std::cout << temp << '\n';
		}
	}
	fs.close();
	fs.clear();

	std::cout << "Fs obj file is closed!\n";

	fin.exceptions(std::ifstream::badbit | std::ifstream::failbit);
	try {
		std::cout << "Try to open file.\n";

		fin.open(no_file);

		std::cout << "File is open successfull!\n";

		fin.close();
		fin.clear();
	} catch(const std::ifstream::failure &ex) {
		std::cout << "Error:\n";
		std::cout << ex.what() << '\n';
		std::cout << ex.code() << '\n';
		std::cout << "Если что это так задумано.\n";
	}

	return 0;
}
