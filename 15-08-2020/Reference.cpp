#include <iostream>

using namespace std;

int square1(int& num) {	return num * num; }

int square2(const int& num) { return num * num;	}
		
int main()
{
    cout<<"Reference\n";
    int i = 2;
    int& ref1 = i;	// lref is a reference to i.
    
	//If we try to create a reference of a rvalue, It will give an error.
	//int& ref = 5;	//error

	//It is possible to create a const reference to a rvalue.
	const int& ref2 = 5;  

    int sqr1 = square1(i);
    std::cout << sqr1 << std::endl;
    
    //int sqr2 = square1(2);  //Error
    int sqr2 = square2(3);
    std::cout << sqr2 << std::endl;
    
    sqr2 = square2(i);
    std::cout << sqr2 << std::endl;
    
    return 0;
}
