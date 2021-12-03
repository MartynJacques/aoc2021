#include <iostream>
#include <fstream>
#include <string>

#define NUM_BITS 12

int main() {
  std::ifstream input_stream("input");
  std::string line;
  int arr[NUM_BITS];
  while(std::getline(input_stream, line)) {
    for(int i = 0; i < NUM_BITS; i++) {
      if(line.at(i) == '0') {
        arr[i] -= 1;
      } else {
        arr[i] += 1;
      }
    }
  }

  for(int i = 0; i < NUM_BITS; i++) {
    if(arr[i] > 0) {
      arr[i] = 1;
    } else {
      arr[i] = 0;
    }
    std::cout << arr[i];
  }
  std::cout << std::endl;
}
