#include<iostream>
#include<bits/stdc++.h>
#include "../../utils/read_in.h"

/*
  Lowercase item types a through z have priorities 1 through 26.
  Uppercase item types A through Z have priorities 27 through 52.
*/
size_t priority(char c) {
    if ('a' <= c && 'z' >= c) {
        return c - 'a' + 1;
    }

    if ('A' <= c && 'Z' >= c) {
        return c - 'A' + 27;
    }

  return 0;
}

auto removeDuplicate(const std::string &line){
  std::string contents;
  std::set<char> exists;

  for(const auto& el : line)
    if(exists.insert(el).second) 
      contents += el;

  return contents;
}

int main(){
  auto lines = readlines("./data/day3.txt");

  // PART 1
  int sum = 0;
  for(auto line : lines){
    size_t line_len = int(line.length() / 2);

    auto rucksack1 = removeDuplicate(line.substr(0, line_len));
    auto rucksack2 = removeDuplicate(line.substr(line_len, 2*line_len));

    for(char c : rucksack1){
      size_t pos = rucksack2.find(c);
      if(pos != std::string::npos){
        sum += priority(c);
        break;
      }
    }
  }

  std::cout << "Part_1: "<< sum << std::endl;

  // PART 2
  sum = 0;
  auto n_lines = lines.size();
  size_t n_groups = int(n_lines/3);

  for(size_t i = 0; i < n_groups; i++){
    auto rucksack1 = removeDuplicate(lines[3*i]);
    auto rucksack2 = removeDuplicate(lines[3*i + 1]);
    auto rucksack3 = removeDuplicate(lines[3*i + 2]);


    for(char c : rucksack1){
      size_t pos1 = rucksack2.find(c);
      size_t pos2 = rucksack3.find(c);

      if(pos1 != std::string::npos && pos2 != std::string::npos){
        sum += priority(c);
        break;
      }
    }
  }

  std::cout << "Part_2: "<< sum << std::endl;

  return 0;
}
