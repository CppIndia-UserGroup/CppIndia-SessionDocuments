/*
 * Presented by Shilpa Dodeja for CppIndia - User Group(18-07-2020)
 * Use case - Mutliple Captures
 * Link - https://godbolt.org/z/sbPdW1
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> v{1, 2, 3, 4, 5, 6};
  int sum = 0; int y = 2;
  for_each(v.begin(), v.end(), [&sum, y] (int x) { sum += x; });
  cout << "sum is " << sum << endl;
}