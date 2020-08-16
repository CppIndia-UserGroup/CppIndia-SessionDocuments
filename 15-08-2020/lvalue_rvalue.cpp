#include <iostream>
using namespace std;

int add(int a, int b) { return a + b; }

int main()
{
    std::cout << "Modern C++ !\n"; 

	//lvalue - rvalue

	int i;	// i is a lvalue.
	int* p = &i;

	i = 2;
	std::cout << i << std::endl;


	int x = 2;	//2 is rvalue.
	x = i + 2;	//(i + 2) is a rvalue. we can't get the address of (i+2).

	// i + 2 = 40;	

	int sum = add(2, 3);	//add(2, 3) will return a rvalue.

	//Uncomment below 2 lines. after creating a class
	//temp obj1;
	//obj1 = temp(10);	//obj1 is lvalue and temp() is rvalue.


	// string s{};
	// s + s = s;
    return 1;
}
