#include "../../utils/read_in.h"
#include <iostream>

int main(int argc, char *argv[]) {
  auto lines = readlines("./data/day4.txt");
  int count1 = 0;
  int count2 = 0;

  for (auto line : lines) {
    auto range1 = line.substr(0, line.find(','));
    auto range2 = line.substr(line.find(',') + 1, line.size());

    int r1_beg = stoi(range1.substr(0, range1.find('-')));
    int r1_end = stoi(range1.substr(range1.find('-') + 1, range1.size()));
    int r2_beg = stoi(range2.substr(0, range2.find('-')));
    int r2_end = stoi(range2.substr(range2.find('-') + 1, range2.size()));

    // PART 1
    if ((r1_beg >= r2_beg && r1_end <= r2_end) ||
        (r2_beg >= r1_beg && r2_end <= r1_end))
      count1++;

    // PART 2
    if (r2_beg <= r1_end && r1_beg <= r2_end)
      count2++;
  }

  std::cout << "Part_1: "<< count1 << std::endl;
  std::cout << "Part_2: "<< count2 << std::endl;

  return 0;
}
