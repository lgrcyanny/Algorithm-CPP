#include <algorithm>
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    void sort(
            const std::string& input_file_name,
            const std::string& output_file_name) {
        std::vector<int> arr;
        int number = 0;
        std::clock_t start;
        double duration;
        start = std::clock();
        std::ifstream fin(input_file_name);
        while(fin >> number) {
            arr.push_back(number);
        }
        duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
        std::cout << "file read:" << duration << std::endl;

        start = std::clock();
        qsort(&arr, 0, arr.size() - 1);
        duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
        std::cout << "qsort :" << duration << std::endl;

        start = std::clock();
        std::ofstream fout(output_file_name);
        for (int i = 0; i < arr.size(); ++i) {
            fout << arr[i] << std::endl;
        }
        duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
        std::cout << "qsort :" << duration << std::endl;
    }

private:
    void qsort(std::vector<int>* arr, int p, int r) {
        if (p >= r) {
            return;
        }
        int q = partition(arr, p, r);
        qsort(arr, p, q - 1);
        qsort(arr, q + 1, r);
    }

    int partition(std::vector<int>* arr, int p, int r) {
        int i = p;
        int j = i - 1;
        for (; i < r; ++i) {
            if (arr->at(i) < arr->at(r)) {
                ++j;
                std::swap(arr->at(i) , arr->at(j));
            }
        }
        ++j;
        std::swap(arr->at(j) , arr->at(r));
        return j;
    }
};

int main(int argc, char const *argv[]) {
    Solution s;
    s.sort("numbers_input.txt", "quick_sort_output.txt");
}
