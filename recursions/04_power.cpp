// Q) Calculate power.

#include <iostream>
using namespace std;

int calculatePower(int n, int k) {
  if (k == 0) return 1;
  if (k == 1) return n;
  return n * calculatePower(n, k - 1);
}

int main() {
  int n;
  cin >> n;

  int k;
  cin >> k;

  cout << calculatePower(n, k) << "\n";
}
