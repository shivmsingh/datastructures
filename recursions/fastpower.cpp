// Q) Calculate power of a number in O(logN) time.

#include <iostream>
using namespace std;

int fastpower(int base, int power) {
  if (power == 0) return 1;
  if (power == 1) return base;

  int num = fastpower(base, power / 2);
  num *= num;

  if (power % 2 == 0)
    return num;
  else
    return num * base;
}

int main() {
  int base, power;
  cin >> base >> power;

  cout << fastpower(base, power) << "\n";
}
