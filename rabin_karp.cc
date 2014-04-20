#include <iostream>
#include <cmath>
using namespace std;


template <class T>
inline int length(T& a) {
  return  sizeof(a) / sizeof(a[0]);
}

/**
 * [RabinKarpMatcher]
 * @param source  [The source string]
 * @param n       [The length of source string]
 * @param pattern [The pattern for matcher]
 * @param m       [The length of pattern]
 * @param d       [The base of string]
 * @param q       [The prime number]
 */
void RabinKarpMatcher(int source[], int n,  int pattern[], int m, int d, int q) {
  int h = (int)pow(d, m - 1) % q;
  int p = 0;
  int* t = new int[n - m + 1];
  t[0] = 0;
  for (int i = 0; i < m; i++) {
    p = (d * p + pattern[i]) % q;
    t[0] = (d * t[0] + source[i]) % q;
  }

  for (int i = 0; i <= (n - m); i++) {
    if (t[i] == p) {
      int j = 0;
      while (j < m) {
        if (source[j + i] != pattern[j]) {
          break;
        }
        j++;
      }
      if (j == m) {
        cout << "The index is " << i << endl;
      }
    }
    t[i + 1] = ((t[i] - h * source[i]) * d + source[i + m]) % q;
    if (t[i + 1] < 0) {
      t[i + 1] = t[i + 1] + q;
    }
  }
}

int main(int argc, char const *argv[]) {
  int source[] = {2, 3, 5, 9, 0, 2, 3, 1, 4, 1, 5, 2, 6, 7, 3, 9, 9, 2, 1};
  int pattern[] = {3, 1, 4, 1, 5};
  int n = length(source);
  int m = length(pattern);
  int d = 10;
  int q = 13;
  RabinKarpMatcher(source, n, pattern, m, d, q);
  return 0;
}