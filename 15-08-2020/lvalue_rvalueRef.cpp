/******************************************************************************

*******************************************************************************/

#include <iostream>

using namespace std;

int multiplyByTwo(int& num) { 
	std::cout << "multiplyByTwo: lvalue reference." << std::endl; 
	return num * 2; 
}

int multiplyByTwo(int&& num) {
	std::cout << "multiplyByTwo: rvalue reference." << std::endl;
	return num * 2;
}

int main()
{
    cout<<"lvalue reference rvalue reference\n";
    
    int num = 4;	//x islvalue
    int& lvref = num; //lvalue reference
    lvref = lvref + 1;
	std::cout << lvref << std::endl;
	
	int num2 = 10;
	//lvref = &num2;  //If we try to assigne new value to a lvalue reference, it will fail.
	
	int&& rvref = 21;   //rvalue reference because 21 is a rvalue.
	std::cout << rvref << std::endl;
    rvref = 31;			//we can re assign a new value to rvalue reference.
	std::cout << rvref << std::endl;
    
    int mulNum1 = multiplyByTwo(num);
    // int mulNum2 = multiplyByTwo(5); //Compile error
    //one way to make this work is, make argument of multiplyByTwo() as const int& 
    //And other way is rvalue reference.
    
    // Let's overload this function.
    int mulNum2 = multiplyByTwo(5);
    
    return 0;
}
