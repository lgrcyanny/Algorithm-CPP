#include <iostream>
#include <climits>
using namespace std;
const int END = INT_MIN;

/**
 * Dynamic programming
 * @param  a The array
 * @param  n Array length
 * @return   the length of LIS(Longest Increase Subsequence)
 */
int LIS(int a[], int n) {
  int* lis = new int[n];
  for (int i = 0; i < n; i++) {
    lis[i] = 1;
    for (int j = 0; j < i; j++) {
      if (a[i] > a[j]) {
        lis[i] = lis[j] + 1;
      }
    }
  }
  int res = lis[0];
  for (int i = 0; i < n; i++) {
    if (lis[i] > res) {
      res = lis[i];
    }
  }
  delete lis;
  return res;
}

int main(int argc, char const *argv[]) {
  int a[] = {-5, -4, -3, -2, -1, -5, 6, -7};
  int n = 8;
  cout << LIS(a, n) << endl;
  return 0;
}