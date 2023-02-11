#include <iostream>
#include <set>
#include "../../utils/read_in.h"

size_t findMarker(const std::string& str, int l){
  int pos = 0;

  for (int i = l-1; i < str.length(); i++) {
    std::set<char> start_marker;

    for(int j = i; j >= i-(l-1); j--)
      start_marker.insert(str[j]);

    if(start_marker.size() == l){
      pos = i+1;
      return pos;
    }
  }

  return -1;
}

int main(int argc, char *argv[]) {
  auto line = readlines("./data/day6.txt")[0]; // one line file

  // PART 1
  std::cout << "Part_1: "<< findMarker(line,4) << std::endl;
  // PART 2
  std::cout << "Part_2: "<< findMarker(line,14) << std::endl;

  return 0;
}
