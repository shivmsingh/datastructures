// Q) Find last occurence of a number.

#include <iostream>
using namespace std;

int lastOccurence(int *arr, int n, int key) {
  if (n < 0) return -1;

  if (arr[n] == key) return n;

  return lastOccurence(arr, n - 1, key);
}

int main() {
  int n, key;
  cin >> n;
  int arr[100];

  for (int i = 0; i < n; i++) cin >> arr[i];

  cin >> key;

  cout << lastOccurence(arr, n, key) << '\n';
}
