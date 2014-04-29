#include <iostream>
using namespace std;

int CountBinaryOne(unsigned short int x) {
  int a[] = {128, 64, 32, 16, 8, 4, 2, 1};
  int n = 8;
  int count = 0;
  for (int i = 0; i < n; i++) {
    if (x >= a[i]) {
      count++;
      x = x - a[i];
    }
  }
  return count;
}

int main(int argc, char const *argv[]) {
  unsigned short int x = 0;
  cout << "Please input a number 0~255";
  do {
    cin >> x;
    cout << "Count is " << CountBinaryOne(x) << endl;
  } while (x >= 0 && x <= 255);

  return 0;
}