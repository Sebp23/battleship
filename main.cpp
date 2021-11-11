#include "logic.h"
#include <cstdlib>
#include <iostream>

int main() {
    bool **board = create_board(6,6);
    //place_ships(board, 3, 10, 10);
    destroy_board(board, 6);
}
