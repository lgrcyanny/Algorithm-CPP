#include <ctime>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class BitVector {
public:
    BitVector(int size) {
        int n = (1 + (size / BITS_PER_WORD));
        buffer = new int[n];
        for (int i = 0; i < n; ++i) {
            buffer[i] = 0;
        }
    }
    ~BitVector() {
        delete[] buffer;
    }
    void set(int i) {
        buffer[(i >> SHIFT)] |= 1 << (i & MASK);
    }
    void clr(int i) {
        buffer[(i >> SHIFT)] &= ~(1 << (i & MASK));
    }
    int test(int i) {
        return buffer[(i >> SHIFT)] & (1 << (i & MASK));
    }

private:
    int* buffer;
    static const int BITS_PER_WORD = 32;
    static const int MASK = 0x1f;
    static const int SHIFT = 5;
};

const int BitVector::BITS_PER_WORD;
const int BitVector::MASK;
const int BitVector::SHIFT;

class Solution {
public:
    void sort(
            int range,
            const std::string& input_file_name,
            const std::string& output_file_name) {
        BitVector bits_vector(range);
        std::ifstream fin(input_file_name);
        int i = 0;

        std::clock_t start;
        double duration;
        start = std::clock();
        while (fin >> i) {
            bits_vector.set(i);
        }
        duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
        std::cout << "sort :" << duration << std::endl;

        start = std::clock();
        std::ofstream fout(output_file_name);
        for (int i = 0; i < range; ++i) {
            if (bits_vector.test(i)) {
                fout << i << std::endl;
            }
        }
        duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
        std::cout << "file write :" << duration << std::endl;
    }
};

int main(int argc, char const *argv[]) {
    Solution s;
    int range = 10000000;
    s.sort(range, "numbers_input.txt", "numbers_output.txt");
}