#include <iostream>
#define DELETED -1
const int m = 11;

int hash1(int k) {
  return k % m;
}

int hash2(int k) {
  return 1 + (k % (m - 1));
}

int hash(int k, int i) {
  return (hash1(k) + hash2(k) * i) % m;
}

void insert(int table[], int k) {
  for (int i = 0; i < m; i++) {
    int index = hash(k, i);
    if (table[index] == DELETED) {
      table[index] = k;
      break;
    }
  }
}

void print(int table[]) {
  std::cout << "The table now is" << std::endl;
  for (int i = 0; i < m; i++) {
    std::cout << table[i] << std::endl;
  }
}

int main(int argc, char const *argv[])
{
  int table[m];
  for (int i = 0; i < m; i++) {
    table[i] = DELETED;
  }
  insert(table, 10);
  insert(table, 22);
  insert(table, 31);
  insert(table, 4);
  insert(table, 15);
  insert(table, 28);
  insert(table, 88);
  insert(table, 17);
  insert(table, 59);
  print(table);
  return 0;
}
