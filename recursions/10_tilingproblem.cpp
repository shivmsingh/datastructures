#include <iostream>
using namespace std;

int tilingproblem(int n) {
  if (n == 4) return 2;

  if (n < 3) return 1;

  int op1 = tilingproblem(n - 1);
  int op2 = tilingproblem(n - 4);

  return op1 + op2;
}

int main() {
  int n;
  cin >> n;
  cout << tilingproblem(n) << '\n';
}
