/*
 *  Presented by Shilpa Dodeja for CppIndia - User Group(18-07-2020)
 *  Use case - No Captures and Lambda variable
 *  Link - https://godbolt.org/z/xcdK7o
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    auto lambda = [](){ cout << " hello lambdas!!"; };
    lambda();
}