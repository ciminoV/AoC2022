#include <iostream>
#include <map>
#include "../../utils/read_in.h"

// A file has a path and a size
struct file {
  int size;
  std::string path;
};

void updateDir(std::string &curr_dir, const std::string &line) {
  auto cmd = line.substr(2, line.find(" ") + 1);

  // change dir
  if (cmd == "cd") {
    auto temp_dir = line.substr(line.rfind(" ") + 1);

    if (temp_dir == "..") {                  // go up one dir
      curr_dir.erase(curr_dir.length() - 1); // delete last /
      curr_dir.erase(curr_dir.rfind("/"),
                     curr_dir.length()); // delete lowest dir
      curr_dir += "/";                   // add /
    } else
      curr_dir += temp_dir + "/";
  }
}

file getFile(std::string &curr_dir, const std::string &line) {
  file output;

  output.path = curr_dir + line.substr(line.find(" ") + 1);

  try {
    output.size = std::stoi(line.substr(0, line.find(" ")));
  } catch (std::invalid_argument const &ex) { // if it's the word 'dir'
    output.size = -1;
  }

  return output;
}

int exploreTree(std::multimap<std::string, file> dirs, std::string path) {
  int dir_size = 0;

  // find all the subdirectories and their size
  auto range = dirs.equal_range(path);
  for (auto i = range.first; i != range.second; ++i) {
    if (i->second.size < 0) // nested dir
      dir_size += exploreTree(dirs, i->second.path + "/") + 1;

    dir_size += i->second.size;
  }

  return dir_size;
}

int main(int argc, char *argv[]) {
  auto lines = readlines("./data/day7.txt");
  size_t sum_dir = 0;

  std::multimap<std::string, file> dirs;
  std::string curr_dir = "/";

  for (auto line : lines) {
    if (line[line.length() - 1] == '/')
      continue; // ignore first command

    // it's a command
    if (line[0] == '$')
      updateDir(curr_dir, line);
    // it's the output of previous command
    else
      dirs.insert({curr_dir, getFile(curr_dir, line)});
  }

  // PART 1
  for (auto it = dirs.begin(); it != dirs.end(); it++) {
    auto size = it->second.size;
    if (size < 0) { // its a dir
      size = exploreTree(dirs, it->second.path + "/");

      if (size < 100000)
        sum_dir += size;

      (it->second.size) = size; // update actual dir size
    }
  }

  std::cout << "Part_1: " << sum_dir << std::endl;

  // PART 2
  /*
  check only elements which values+"/" are equals to keys and get the one
  with min size above 30000000 - unused_space
  */
  int unused_space = 70000000;
  for (auto dir: dirs) {
    if(dir.first != "/")
      break;
    
     unused_space -= dir.second.size;
  }

  std::cout << "Part_2: "<< unused_space << std::endl;
  return 0;
}
