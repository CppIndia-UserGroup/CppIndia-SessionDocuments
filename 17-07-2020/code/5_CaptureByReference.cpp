/*
 * Presented by Shilpa Dodeja for CppIndia - User Group(18-07-2020)
 * Use case - Capture By Reference
 * Link - https://godbolt.org/z/cG5rPP
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> v{1, 2, 3, 4, 5, 6};
  int sum = 0;
  for_each(v.begin(), v.end(), [&sum] (int x) { sum += x; });
  cout << "sum is " << sum << endl;
}