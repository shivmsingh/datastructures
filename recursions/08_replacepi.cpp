// Q) Replace pi with 3.14 .

#include <cstring>
#include <iostream>
using namespace std;

void replacepi(char* s, int i) {
  if (s[i] == '\0') return;

  if (s[i] == 'p' and s[i + 1] == 'i') {
    for (int j = strlen(s) - 1; j >= i - 2; --j) {
      s[j + 2] = s[j];
    }
    s[i] = '3';
    s[i + 1] = '.';
    s[i + 2] = '1';
    s[i + 3] = '4';

    replacepi(s, i + 3);
  }

  replacepi(s, i + 1);
}

int main() {
  char arr[100] = "xpighpilmpipi";

  replacepi(arr, 0);

  for (int i = 0; arr[i] != '\0'; i++) {
    cout << arr[i];
  }
}
