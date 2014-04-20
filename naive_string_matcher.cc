#include <iostream>
#include <cstring>
using namespace std;

void NaiveStringMatcher(char str[], char p[]) {
  int n = strlen(str);
  int m = strlen(p);
  for (int i = 0; i <= (n - m); ) {
    int j =0;
    while (j < m && p[j] == str[j + i]) {
      j++;
    }
    if (j == m) {
      cout << i << endl;
      i = i + m;
    } else {
      i++;
    }
  }
}

/**
 * The pattern can have "*", like "ab*b*c", "*" match any letter
 * @param str  The source string, can't have *
 * @param p   The pattern
 */
void REStringMatcher(char str[], char p[]) {
  int n = strlen(str);
  int m = strlen(p);
  for (int i = 0; i < n; i++) {
    int k = i;
    int j = 0;
    while (j < m) {
      if (p[j] != '*' && (k + j) < n && p[j] == str[k + j]) {
        j++;
      } else if ((k + j) < n && p[j] == '*') {
        // Process matches for "*"
        while (str[k + j] != p[j + 1]) {
          k++;
        }
        j++;
        k--;
      } else {
        //printf("not match i = %d, j = %d, k = %d \n", i, j, k);
        break;
      }
    }
    if (j == m) {
      cout << i << endl;
    }
  }
}

int main(int argc, char const *argv[])
{
  char str[] = "cabccbacbacab";
  char p[] = "b*ac";
  REStringMatcher(str, p);
  return 0;
}