#include <iostream>
#include <vector>
#include <string>

void greet() {
  std::cout << "Welcome to Tic Tac Toe!\n";
  std::cout << "Get 3 X or 3 Y in a row (horizontal, vertical or diagonal) in order to win the game.\n";
  std::cout << "Enter 2 digits representing the position on the grid that you would like to place your X or O in (e.g.: 1 1).\n";
  std::cout << "Let's begin!\n";
}

void print_grid(std::vector < std::vector < char > > grid) {
  std::cout << "\n";
  for (int i = 0; i < grid.size(); i++) {
    for (int j = 0; j < grid[i].size(); j++){
      std::cout << grid[i][j] << " ";
    }
    std::cout << "\n";
  }
}

char get_sign(int player) {
  if (player == 1) {
      return 'X';
    }
    return 'O';
}

int get_pos_coord(){
  int coord;
  std::cin >> coord;
  return (coord - 1);
}

bool in_range(int position[2]) {
  return (position[0] >= 0 and position[0] <= 2) and (position[1] >= 0 and position[1] <= 2);
}

bool check_winner(std::vector < std::vector < char > > grid) {
  // horizontal check
  for (int i = 0; i < grid.size(); i++) {
    if (grid [i][0] != '_' && grid[i][0] == grid[i][1] && grid[i][0] == grid[i][2]) {
      return true;
    }
  }
  // vertical check
  for (int j = 0; j < grid.size(); j++) {
    if (grid [0][j] != '_' && grid[0][j] == grid[1][j] && grid[0][j] == grid[2][j]) {
      return true;
    }
  }
  // diagonal check
  if (grid [0][0] != '_' && grid[0][0] == grid[1][1] && grid[0][0] == grid[2][2]) {
    return true;
  }
  return false;
}

bool is_valid_input(std::vector < std::vector < char > > grid, int position[2]) {
  if (!in_range(position)) {
    std::cout << "Your choice is out of range! Try again: ";
    return false;
  } else if (grid[position[0]][position[1]] != '_') {
    std::cout << "You chose a non-empty slot! Try again: ";
    return false;
  }
  return true;
}

void declare_game_ending(bool winner, char sign) {
  if (winner) {
    std::cout << "\n*** " << sign << " WINS! ***\n";
  } else {
    std::cout << "\n***Game ended in a draw! ***\n";
  }
}