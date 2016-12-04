#include <iostream>
#include <climits>
using namespace std;

void Merge(int a[], int p, int q, int r) {
  int n1 = q - p + 1;
  int n2 = r - q;
  int* left = new int[n1 + 1];
  int* right = new int[n2 + 1];
  for (int i = 0; i < n1; i++) {
    left[i] = a[i + p];
  }
  for (int i = 0; i < n2; i++) {
    right[i] = a[i + q + 1];
  }
  left[n1] = INT_MAX;
  right[n2] = INT_MAX;
  for (int k = p, i = 0, j = 0; k <= r; k++) {
    if (left[i] <= right[j]) {
      a[k] = left[i];
      i++;
    } else {
      a[k] = right[j];
      j++;
    }
  }
  delete[] left;
  delete[] right;
}

void MergeSort(int a[], int p, int r) {
  if (p < r) {
    int q = (r + p) / 2;
    MergeSort(a, p, q);
    MergeSort(a, q + 1, r);
    Merge(a, p, q, r);
  }
}

template <class T>
int Length (T &a) {
  return sizeof(a) / sizeof(a[0]);
}

void Print(int a[], int n) {
  for (int i = 0; i < n; i++) {
    cout << a[i] << endl;
  }
}

int main(int argc, char const *argv[])
{
  int a[] = {1, 3, 6, 7, 2, 9, 10};
  int n = Length(a);
  MergeSort(a, 0, n - 1);
  Print(a, n);
  return 0;
}