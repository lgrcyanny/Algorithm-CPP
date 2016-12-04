#include <iostream>
using namespace std;

double Factorial(int n) {
  double res = 1;
  while (n > 0) {
    res = res * n;
    n--;
  }
  return res;
}

int FactorialCountZero(int n) {
  int res = 0;
  while (n > 0) {
    res = res + n / 5;
    n = n / 5;
  }
  return res;
}

int FactorialCountOne(int n) {
  int res = 0;
  while (n > 0) {
    res++;
    n = n >> 1;
  }
  return res;
}


int main(int argc, char const *argv[]) {
  int x = 25;

  cout << FactorialCountZero(x) << endl;
  return 0;
}