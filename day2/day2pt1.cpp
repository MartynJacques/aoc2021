#include <iostream>
#include <fstream>
#include <string>

struct Position {
  int depth = 0;
  int distance = 0;
};

int main() {
  Position position;

  std::ifstream input_stream("input");
  std::string line;
  while(std::getline(input_stream, line)) {
    if (auto pos = line.find_first_of(' '); pos != std::string::npos) {
      int number = std::stoi(line.substr(pos + 1));
      if (line.starts_with("forward")) {
        position.distance += number;
      } else if (line.starts_with("down")) {
        position.depth += number;
      } else if (line.starts_with("up")) {
        position.depth -= number;
      }
    }
  }

  int result = position.depth * position.distance;
  std::cout << result << std::endl;

}
