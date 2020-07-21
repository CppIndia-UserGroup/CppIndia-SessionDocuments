/*
 * Presented by Shilpa Dodeja for CppIndia - User Group(18-07-2020)
 * Use Case - Understanding function object
 * Link - https://godbolt.org/z/vvG1jq
 */


#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void print(int x) { 
    cout << " using normal function: " << x + 1 << endl;
}

struct A
{
    void print(int x) { cout << " using print member function: " << x + 1 << endl;}
    void operator() (int x) { cout << " using operator() function: " << x + 1 << endl;} 
};

int main()
{
    // calling a normal function
    print(1);

    // Declare the object
    A a;
    a.print(2);
    a.operator()(3);

    // Use it as a function
    a(4);
}

