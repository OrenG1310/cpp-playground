#include <iostream>
#include <vector>
#include <string>

#include "funcs.hpp"


int main() {
  
  std::vector < std::vector < char > > grid = {
    {'_', '_', '_'},
    {'_', '_', '_'},
    {'_', '_', '_'}
  };

  bool winner = false;
  int turn = 1;
  int player;
  int position[2];
  char sign;

  greet();

  while (true) {
    
    player = (turn % 2);
    sign = get_sign(player);

    print_grid(grid);

    std::cout << "\nTurn " << turn << ": " << sign << " playing.\n";
    std::cout << "Where do you want to place your " << sign << "? ";
    while (true) {
      position[0] = get_pos_coord();
      position[1] = get_pos_coord();
      if (is_valid_input(grid, position)) {
        grid[position[0]][position[1]] = sign;
        break;
      }
    }
    
    winner = check_winner(grid);
    
    if (winner || turn == 9) {
      break;
    }

    turn++;
  }

  print_grid(grid);
  declare_game_ending(winner, sign);

  return 0;
}