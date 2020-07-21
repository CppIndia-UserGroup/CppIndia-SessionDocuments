/*
 * Presented by Shilpa Dodeja for CppIndia - User Group(18-07-2020)
 * Use case - Default captures
 * Link - https://godbolt.org/z/zh3jse
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> v{1, 2, 3, 4, 5, 6};
  int sum = 0; int y = 2;
  for_each(v.begin(), v.end(), [&] (int x) { sum += x; cout << " y is " << y << endl; });
  for_each(v.begin(), v.end(), [=] (int x) mutable { sum += x; });
  cout << "sum is " << sum << endl;
}