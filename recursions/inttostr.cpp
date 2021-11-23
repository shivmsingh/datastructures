// Q) Convert integer to string.

#include <iostream>
#include <vector>
using namespace std;

vector<string> digits{"zero", "one", "two",   "three", "four",
                      "five", "six", "seven", "eight", "nine"};

void inttostr(int n, vector<string> &out) {
  if (n == 0) return;

  inttostr(n / 10, out);

  out.push_back(digits.at(n % 10));
}

int main() {
  int num;
  vector<string> out;

  cin >> num;

  inttostr(num, out);

  for (auto digits : out) cout << digits << ' ';

  cout << '\n';
}
