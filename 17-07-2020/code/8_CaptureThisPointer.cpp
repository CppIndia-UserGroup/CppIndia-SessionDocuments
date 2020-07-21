/*
 *  Presented by Shilpa Dodeja for CppIndia - User Group(18-07-2020)
 *  Use case - Capturing 'this' pointer
 *  Link - https://godbolt.org/z/4vzP15
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class A
{
    public :
    void print()
    {
        auto lambda = [this] {
            cout << "value of member variable is " << m_member << endl; 
        };
        lambda();
    }


    private :
    int m_member = 5;
};

int main() {
    auto lambda = [](){ cout << " hello lambdas!!"; };
    lambda();
}