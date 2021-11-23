// Q) Perform linear search.

#include <iostream>
using namespace std;

int linearSearch(int *arr, int index, int n, int key) {
  if (n == 0) return -1;

  if (arr[index] == key) return index;

  return linearSearch(arr, index + 1, n - 1, key);
}

int main() {
  int n, key;
  int index = 0;
  int arr[100];

  cin >> n;

  for (int i = 0; i < n; i++) cin >> arr[i];
  cin >> key;
  cout << linearSearch(arr, 0, n, key) << '\n';
}
