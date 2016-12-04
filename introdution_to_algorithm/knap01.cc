#include <iostream>
using namespace std;
const int TOTAL_WEIGHT = 50;
const int TOTAL_WEITH_ARR = 51; // The total wieght for the array
/**
 * c[i][w]表示前i件物品放入容量为w的背包的最大价值
 * c[i][w] = max{c[i - 1][w - weight(i)] + value[i], c[i - 1][w]}
 */
class Knap
{
private:
  int n;
  int* value;
  int* weight;
  typedef int A[TOTAL_WEITH_ARR];
  A* c;
public:
  Knap(int an, int* av, int* aw):n(an), value(av), weight(aw) {
    c = new int[n + 1][TOTAL_WEITH_ARR];
    memset(c, 0, (n + 1) * (TOTAL_WEITH_ARR) * sizeof(int));
  }
  ~Knap() {
    delete []c;
    c = NULL;
  }
  int Calculate();
};

int Knap::Calculate() {
  for (int i = 1; i <= n; i++) {
      for (int w = 1; w <= TOTAL_WEIGHT; w++) {
        if (w < weight[i - 1]) {
          c[i][w] = c[i - 1][w];
        } else { // Since c[n + 1][total_weight + 1], so value should be value[i - 1], weight should be weight[i - 1]
          if (c[i - 1][w - weight[i - 1]] + value[i - 1] > c[i - 1][w]) {
            c[i][w] = c[i - 1][w - weight[i - 1]] + value[i - 1];
          } else {
            c[i][w] = c[i - 1][w];
          }
        }
      }
    }
  return c[n][TOTAL_WEIGHT];
}

int main(int argc, char const *argv[])
{
  int n = 3;
  int total_weight = 50;
  int weight[] = {10, 20, 30};
  int value[] = {60, 100, 120};
  Knap knap(n, value, weight);
  cout << knap.Calculate() << endl;

  return 0;
}