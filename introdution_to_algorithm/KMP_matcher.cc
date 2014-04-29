#include <iostream>
#include <cstring>
using namespace std;

class KMPMatcher {
public:
  char* source;
  int n;
  KMPMatcher(char t[]);

  void Match(char pattern[]);
public:
  int* ComputePrefixFunction(char pattern[], int m);
};

KMPMatcher::KMPMatcher(char t[]) {
  source = t;
  n = strlen(source);
}


int* KMPMatcher::ComputePrefixFunction(char pattern[], int m) {
  int* pi = new int[m];
  pi[0] = 0;
  int k = 0;
  for (int q = 1; q < m; q++) {
    while (k > 0 && pattern[k] != pattern[q]) {
      k = pi[k];
    }
    if (pattern[k] == pattern[q]) {
      k = k + 1;
    }
    pi[q] = k;
  }

  return pi;
}

void KMPMatcher::Match(char pattern[]) {
  int m = strlen(pattern);
  int* pi = ComputePrefixFunction(pattern, m);
  int q = 0;
  for (int i = 0; i < n; i++) {
    while (q > 0 && pattern[q] != source[i]) {
      q = pi[q];
    }
    if (pattern[q] == source[i]) {
      q = q + 1;
    }
    if (q == m) {
      cout << "The index is " << (i - m + 1) << endl;
      q = pi[q - 1];
    }
  }
}

int main(int argc, char const *argv[]) {
  char source[] = "cababababcavabababvvababababcaab";
  char pattern[] = "ababababca";
  KMPMatcher* kmp_matcher = new KMPMatcher(source);
  kmp_matcher->Match(pattern);
  return 0;
}