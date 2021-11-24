#include <iostream>
using namespace std;

int ladderProblem(int n) {
  if (n == 0) return 1;
  if (n < 0) return 0;

  int op1 = ladderProblem(n - 1);
  int op2 = ladderProblem(n - 2);
  int op3 = ladderProblem(n - 3);

  return op1 + op2 + op3;
}

int main() {
  int n{};
  cin >> n;

  cout << ladderProblem(n) << '\n';
}
