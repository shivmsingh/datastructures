// Q) Find all occurences of a given number.

#include <iostream>
#include <vector>
using namespace std;

void alloccurences(vector<int> &in, int key, int i, vector<int> &out) {
  if (i == in.size()) return;

  if (in.at(i) == key) out.push_back(i);

  alloccurences(in, key, i + 1, out);
}

int main() {
  int n, key;
  cin >> n;

  vector<int> in;
  vector<int> out;

  for (int i = 0; i < n; i++) {
    int input{};
    cin >> input;
    in.push_back(input);
  }

  cin >> key;

  alloccurences(in, key, 0, out);

  for (auto index : out) cout << index << ' ';

  cout << '\n';
}
