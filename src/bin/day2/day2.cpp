#include<iostream>
#include<vector>
#include<string.h>
#include "../../utils/read_in.h"

int main (int argc, char *argv[]) {
  int score = 0;
  std::vector<std::string> lines = readlines("./data/day2.txt");

  /*
    First column opponent play:
    A - Rock              B - Paper              C - Scissor

    Second column my play:
    Rock - 1 point        Paper - 2 points      Scissor - 3 points    
  
    Outcome of the round:
    Win - 6 points        Draw - 3 points       Lose - 0 point
  */

  /* Part 1
    X - Rock              Y - Paper              Z - Scissor
  */
  for(auto line : lines){
    std::string opponent_play = line.substr(0,1);
    std::string my_play = line.substr(2,1);

    if(my_play == "X"){ // I play Rock
      score += 1;

      if(opponent_play == "A") // Draw
        score += 3;
      else if(opponent_play == "C") // Win
        score += 6;

      continue;
    }

    if(my_play == "Y"){ // I play Paper
      score += 2;

      if(opponent_play == "A") // Win
        score += 6;
      else if(opponent_play == "B") // Draw
        score += 3;

      continue;
    }

    if(my_play == "Z"){ // I play Scissor
      score += 3;

      if(opponent_play == "B") // Win
        score += 6;
      else if(opponent_play == "C") // Draw
        score += 3;

      continue;
    }
  }

  std::cout << "Part_1: " << score << std::endl;
  score = 0;

  /* Part 2
     X - Lose              Y - Draw               Z - Win
  */
  for (auto line : lines) {
   std::string opponent_play = line.substr(0,1);
   std::string my_play = line.substr(2,1);

   if(my_play == "X"){ // Lose
     // 0 points

     if(opponent_play == "A") // I play Scissor
       score += 3;
     else if(opponent_play == "B") // I play Rock
       score += 1;
     else if(opponent_play == "C") // I play Paper
       score += 2;

     continue;
   }

   if(my_play == "Y"){ // Draw
     score += 3;

     if(opponent_play == "A") // I play Rock
       score += 1;
     else if(opponent_play == "B") // I play Paper
       score += 2;
     else if(opponent_play == "C") // I play Scissor
       score += 3;

     continue;
   }

   if(my_play == "Z"){ // Win
     score += 6;

     if(opponent_play == "A") // I play Paper
       score += 2;
     else if(opponent_play == "B") // I play Scissor
       score += 3;
     else if(opponent_play == "C") // I play Rock
       score += 1;

     continue;
   }
 }

  std::cout << "Part_2: "<< score << std::endl;
  
  return 0;
}
