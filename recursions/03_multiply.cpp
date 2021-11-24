// Q) Perform multiplication of two numbers without the '*' operator.

#include <iostream>
using namespace std;

int multiplynums(int num1, int num2) {
  if (num1 == 0 || num2 == 0) return 0;
  if (num2 == 1) return num1;

  return num1 + multiplynums(num1, num2 - 1);
}

int main() {
  int num1, num2;
  cin >> num1 >> num2;

  cout << multiplynums(num1, num2) << "\n";
}
