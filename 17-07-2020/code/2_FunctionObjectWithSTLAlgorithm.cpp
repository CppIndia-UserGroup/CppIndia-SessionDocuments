/*
 * Presented by Shilpa Dodeja for CppIndia - User Group(18-07-2020)
 * Use case - Using the Function Objects with STL algorithm(Pre-Lambda) 
 * Link - https://godbolt.org/z/b1afGn
 */


#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct AddAndPrint {
  AddAndPrint(int increment) : m_increment(increment) {}

  void operator()(const int& x) { cout << x + m_increment << endl; }

  int m_increment;
};

int main() {
  vector<int> v{1, 2, 3, 4, 5, 6};
  int increment;
  cin >> increment;
  AddAndPrint print(increment);
  for_each(v.begin(), v.end(), print);
  // for_each(v.begin(), v.end(), AddAndPrint(increment));
}



