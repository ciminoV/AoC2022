#include <iostream>
#include <sstream>
#include <stack>
#include <array>
#include<string>
#include "../../utils/read_in.h"

// Get the number of crates, initial column and final column
std::array<size_t, 3> getNumbersFromString(const std::string &str) {
  std::array<size_t, 3> moves;

  std::stringstream str_strm;
  str_strm << str;

  std::string temp_str;
  int temp_int;
  int i = 0;

  while (!str_strm.eof()) {
    str_strm >> temp_str;

    if (std::stringstream(temp_str) >> temp_int) {
      moves[i] = (temp_int);
      i++;
    }

    temp_str = "";
  }

  return moves;
}

// Check if is valid crate character, i.e. a capital letter
bool isCrate(char c) {
  if ('A' <= c && 'Z' >= c)
    return true;

  return false;
}

int main(int argc, char *argv[]) {
  auto lines = readlines("./data/day5.txt");

  std::vector<std::array<size_t, 3>> moves;
  std::vector<std::stack<char>> crates;

  // INPUT READ
  char split = 0;
  // read from last line to first
  for (auto it = lines.end() - 1; it >= lines.begin(); it--) {

    // Skip empty row and columns row
    if (it->empty()) {
      split = 1;
      it--;

      // create as many stacks as columns
      size_t n_stack = int((*it)[it->length() - 2]) - 48; // avoid ascii decimal value
      for (size_t i = 0; i < n_stack; i++) {
        std::stack<char> new_stack;
        crates.emplace_back(new_stack);
      }

      continue;
    }

    // Store the moves
    if (!split) {
      moves.push_back(getNumbersFromString(*it));

    // Store the crates
    } else {
      for (int i = 1; i < it->size() - 1; i++) {
        char c = (*it)[i];
        if (isCrate(c)) {
          size_t el = int(i / 4);

          crates[el].push(c);
        }
      }
    }
  }

  // PART 2
  // Move the crates
  for (auto it = moves.end() - 1; it >= moves.begin(); it--) {
    size_t n_crates = (*it)[0];
    size_t from_col = (*it)[1] - 1; // input moves are 1-indexed
    size_t to_col = (*it)[2] - 1;

    /* move n_crates from col x to col y
      string with n_crates character popped from chosen stack
    */
    std::string move_els = "";
    std::stack<char> temp_stack = crates[from_col];
    for (size_t i = 0; i < n_crates; i++){
      move_els += temp_stack.top();
      temp_stack.pop();
    }

    for(size_t i = 0; i < move_els.length();  i++){
      crates[from_col].pop();
      crates[to_col].push(move_els[move_els.length()-i-1]);
    }
  }

  // Get top crates
  std::string top_crates = "";
  for (auto crate : crates)
    top_crates += crate.top();

  std::cout << "Part_2: "<< top_crates << std::endl;

  return 0;
}
