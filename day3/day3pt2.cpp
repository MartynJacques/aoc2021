#include <array>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#define NUM_BITS 12

std::array<char, NUM_BITS> getMostCommonBitInPositions(
    std::vector<std::string> &vec) {
    std::array<int, NUM_BITS> arr = {};
    for (int j = 0; j < vec.size(); j++) {
        for (int i = 0; i < NUM_BITS; i++) {
            if (vec.at(j).at(i) - '0' == 0) {
                arr[i] -= 1;
            } else {
                arr[i] += 1;
            }
        }
    }

    std::array<char, NUM_BITS> charArr = {};
    for (int i = 0; i < NUM_BITS; i++) {
        if (arr[i] > 0 || arr[i] == 0) {
            charArr[i] = '1';
        } else {
            charArr[i] = '0';
        }
    }

    return charArr;
}

std::array<char, NUM_BITS> flipBits(std::array<char, NUM_BITS> arr) {
    std::array<char, NUM_BITS> flippedArr = {};
    for (int i = 0; i < NUM_BITS; i++) {
        if (arr[i] == '0') {
            flippedArr[i] = '1';
        } else {
            flippedArr[i] = '0';
        }
    }
    return flippedArr;
}

void printBits(std::array<char, NUM_BITS> arr) {
    for (auto a : arr) {
        std::cout << a;
    }
    std::cout << std::endl;
}

int main() {
    std::ifstream input_stream("input");
    std::string line;
    std::vector<std::string> vec;
    while (std::getline(input_stream, line)) {
        vec.push_back(line);
    }
    std::vector<std::string> otherVec = vec;

    int bitNum = 0;
    while (vec.size() != 1) {
        auto mostCommonBits = getMostCommonBitInPositions(vec);

        for (auto it = vec.begin(); it != vec.end();) {
            if (mostCommonBits[bitNum] != it->at(bitNum)) {
                it = vec.erase(it);
            } else {
                ++it;
            }
        }
        bitNum++;
    }

    std::cout << vec.at(0) << std::endl;

    bitNum = 0;
    while (otherVec.size() != 1) {
        auto leastCommonBits = flipBits(getMostCommonBitInPositions(otherVec));

        for (auto it = otherVec.begin(); it != otherVec.end();) {
            if (leastCommonBits[bitNum] != it->at(bitNum)) {
                it = otherVec.erase(it);
            } else {
                ++it;
            }
        }
        bitNum++;
    }

    std::cout << otherVec.at(0) << std::endl;
}
