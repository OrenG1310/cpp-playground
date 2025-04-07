#include <vector>
#include <string>

void greet();
void print_grid(std::vector < std::vector < char > > grid);
char get_sign(int player);
int get_pos_coord();
bool is_valid_input(std::vector < std::vector < char > > grid, int position[2]);
bool check_winner(std::vector < std::vector < char > > grid);
void declare_game_ending(bool winner, char sign);