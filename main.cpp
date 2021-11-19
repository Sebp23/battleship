#include "logic.h"
#include <cstdlib>
#include <iostream>

int main() {
    bool **b = create_board(3, 3);
    place_ships(b, 3, 3, 3);
        
    ResponseType test = guess(b, 3, 3, 1, 1);
    std::cout << ResponseOut(test) << std::endl;
    ResponseType test2 = guess(b, 3, 3, 2, 2);
    std::cout << ResponseOut(test2) << std::endl;

    destroy_board(b, 3);
}