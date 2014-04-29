#include <iostream>
using namespace std;

void Swap(int &x, int &y) {
  int t = x;
  x = y;
  y = t;
}

void Print(int a[], int n) {
  for (int i = 0; i < n; i++) {
    cout << a[i] << endl;
  }
}

int Split(int a[], int p, int r) {
  int pivot = a[p];
  int j = p;
  int i = p + 1;
  for (; i <= r; i++) {
    if (a[i] > pivot) {
      j++;
      Swap(a[j], a[i]);
    }
  }
  a[p] = a[j];
  a[j] = pivot;
  return j;
}

void FindMaxK(int a[], int p, int r, int k) {
  if (p >= r) {
    return;
  }
  int q = Split(a, p, r);
  int count = q - p + 1;
  if (count == k) {
    return;
  } else if (count > k) {
    FindMaxK(a, p, q - 1, k);
  } else {
    FindMaxK(a, q + 1, r, k - count);
  }
}

template <class T>
int Length(T &x) {
  return sizeof(x) / sizeof(x[0]);
}

int main(int argc, char const *argv[]) {
  int a[] = {1, 6, 7, 8, 0, 2, 1};
  int n = Length(a);
  int k = 3;
  FindMaxK(a, 0, n - 1, k);
  Print(a, k);
  return 0;
}