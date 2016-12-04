#include <iostream>
#include <ctime>
using namespace std;

int CountOne(int n) {
  int num = 0;
  while (n > 0) {
    num += n % 10 == 1 ? 1 : 0;
    n /= 10;
  }
  return num;
}

int Calculate(int m) {
  int ret = 0;
  for (int i = 1; i <= m; i++) {
    ret += CountOne(i);
  }
  return ret;
}

int main(int argc, char const *argv[]) {
  clock_t start, end;
  int a = 1000000000;
  start = clock();
  cout << Calculate(a) << endl;
  end = clock();
  cout << "running time " << (end - start) << endl;
  return 0;
}
