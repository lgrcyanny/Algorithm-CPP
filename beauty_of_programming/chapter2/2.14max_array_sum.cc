#include <iostream>
#include <climits>
using namespace std;

/**
 * Dyanmic programming
 * @param  a [description]
 * @param  n [description]
 * @return   [description]
 */
int MaxSubArraySum(int a[], int n) {
  int* f = new int[n];
  f[0] = a[0];
  for (int i = 1; i < n; i++) {
    f[i] = a[i];
    if (f[i - 1] > 0 && (f[i] + f[i - 1] > f[i])) {
      f[i] = f[i] + f[i - 1];
    }
  }

  int res = f[0];
  for (int i = 1; i < n; i++) {
    if (f[i] > res) {
      res = f[i];
    }
  }

  return res;
}

int inline Max(int x, int y) {
  return x > y ? x : y;
}


/**
 * Dyanmic programming with O(1) space
 * @param  a the array
 * @param  n the number of a
 * @return   the max sum
 */
int AdvancedMaxSum(int a[], int n) {
  int maxsum = INT_MIN;
  int sum= 0;
  for (int i = 0; i < n; i++) {
    sum = sum + a[i];
    maxsum = Max(sum, maxsum);
    if (sum < 0) {
      sum = 0;
    }
  }
  return maxsum;
}


template <class T>
int length(T &a ) {
  return sizeof(a) / sizeof(a[0]);
}

int main(int argc, char const *argv[]) {
  int a[] = {1, -2, 3, 5, -3, 2};
  int b[] = {0, -2, 3, 5, -1, 2};
  int c[] = {-9, -2, -3, -5, -3};

  cout << AdvancedMaxSum(a, length(a)) << endl;
  cout << AdvancedMaxSum(b, length(b)) << endl;
  cout << AdvancedMaxSum(c, length(c)) << endl;

  return 0;
}