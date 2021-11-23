// Q) Perform binary search.

#include <iostream>
using namespace std;

int binarySearch(int* arr, int si, int ei, int key) {
  if (si > ei) return -1;

  int mid = (si + ei) >> 1;

  if (arr[mid] == key)
    return mid;
  else if (arr[mid] > key) {
    return binarySearch(arr, si, mid - 1, key);
  } else {
    return binarySearch(arr, mid + 1, ei, key);
  }
}

int main() {
  int arr[100];
  int n;
  cin >> n;
  int key;
  cin >> key;

  for (int i = 0; i < n; i++) cin >> arr[i];

  cout << binarySearch(arr, 0, n - 1, key) << "\n";
}
