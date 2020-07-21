/*
 * Presented by Shilpa Dodeja for CppIndia - User Group(18-07-2020)
 * Use case - Dangling Reference
 * Link - https://godbolt.org/z/PevEM7
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

auto Lambda()
{
    int x = 0;
    return [&]() { cout << " x is " << x << endl;};
}

int main() 
{
    Lambda()();
}