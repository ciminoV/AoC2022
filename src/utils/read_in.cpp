#include "read_in.h"

std::vector<std::string> readlines(const std::string& fname) {
  std::vector<std::string> lines;
  // Open file
  std::string filename = fname;
  std::ifstream fin(filename.c_str());

  if(!fin) {
    std::cout << "Error: open file for input failed" << std::endl;
    exit(127);
  }

  // Read file
  std::string line;
  while(std::getline(fin,line)){
   lines.emplace_back(line);
  }

  // Close file
  fin.close();

  return lines;
}

