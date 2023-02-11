#include<iostream>
#include<vector>
#include<algorithm>
#include "../../utils/read_in.h"

int main (int argc, char *argv[]) {
  std::vector<int> calories = {0};
  std::vector<std::string> lines = readlines("./data/day1.txt");

  // Part 1
  int elf_cal = 0;
  for(auto line : lines){
    if(line == ""){
      calories.emplace_back(elf_cal);
      elf_cal = 0;
      continue;
    }

    elf_cal += stoi(line);
  }

  int max_calories = *max_element(calories.begin(), calories.end());
  std::cout << "Part_1: " << max_calories << std::endl;

  // Part 2
  sort(calories.begin(), calories.end());

  int size = calories.size();
  int top3 = calories[size-1] + calories[size-2] + calories[size-3];

  std::cout << "Part_2: " << top3 << std::endl;
  
  return 0;
}
