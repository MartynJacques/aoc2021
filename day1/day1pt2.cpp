#include <fstream>
#include <iostream>
#include <vector>

int main() {
  std::ifstream infile("input");
  std::vector<int> nums;
  int currNum;
  while(infile >> currNum) {
    nums.push_back(currNum);
  }

  int numIncreases = 0;
  for(int i = 0; i < nums.size() - 3; i++) {
    int sumA = nums.at(i)  + nums.at(i + 1) + nums.at(i + 2);
    int sumB = nums.at(i + 1)  + nums.at(i + 2) + nums.at(i + 3);
      
    if(sumB > sumA) {
      numIncreases++;
    }
  }

  std::cout << numIncreases;
}


