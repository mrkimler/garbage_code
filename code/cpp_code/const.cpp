#include <iostream>
#include <vector>

//typedef std::vector<std::pair<std::string, int>> pairlist_t;
//typedef std::string text_t;
//typedef int number_t;

namespace first{
	int x = 1;
}
namespace second{
	int x = 2;
}

int main() {
	using namespace first;	
	//using namespace std;
	using std::cout;
	using std::endl;
	using std::string;
	using pairlist_t = std::vector<std::pair<std::string, int>>;
	using text_t = std::string;
	using number_t = int;	

	// The const keyword specidies that a variable's value is constant
	// tells the computer to prevent anything from mofigying it
	// (read-only)

	const double  pi = 3.14159;
	const int light_speed = 299792458;
	const int width = 1920;
	const int height = 1080;
	
	double radius = 10;
	double circumference = 2 * pi * radius;

	string bro = "Bro";

	text_t firstName = "Igor";

	number_t age = 43;

	cout << circumference << "cm" << endl;

	/*
	Namespace = provides a solution for preventing name conflicts
	in large projects. Each entity needs a unique name. A name
	space allows for identically named entities as long as the
	namespaces are different.
	*/

	cout << x << endl;
	cout << bro << endl;

	/*
	typedef - reserved keyword used to create additional name
	(alias) for another data type. Now indetifier for an existng.
	Helps with readabillity and reduces typos. Use there is a
	clear benefit. Replaced with "using" (work better w/ templates)
	*/
	
	pairlist_t pairlist;
	cout << firstName << endl;
	cout << age << endl;

	return 0;
}
