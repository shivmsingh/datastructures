#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int getSubstring(string& str, char* out) {
  if (str.size() == 0) {
    out[0] = ' ';
    return 1;
  }

  string subs = str.substr(1);

  int x = getSubstring(subs, out);

  for (int i = 0; i < x; i++) {
    out[i + x] = out[i];
  }

  for (int i = 0; i < x; i++) {
    out[x + i] += str[0];
  }

  return 2 * x;
}

int main() {
  string s = "abc";
  char out[100] = " ";
  int x = getSubstring(s, out);

  for (int i = 0; i < x; i++) cout << out[i] << ' ';
}
