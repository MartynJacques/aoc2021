#include <fstream>
#include <iostream>

int main() {
  std::ifstream infile("input");
  int prevNum = -1;
  int currNum;
  int numIncreases = 0;
  while(infile >> currNum) {
    if(prevNum != -1) {
      if(currNum > prevNum) {
        numIncreases++;
      }
    }
    prevNum = currNum;
  }
  std::cout << numIncreases << std::endl;
}


