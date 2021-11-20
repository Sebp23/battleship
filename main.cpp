#include "logic.h"
#include <cstdlib>
#include <iostream>

int main() {
    bool **b = create_board(9, 9);
    place_ships(b, 3, 9, 9);
        
    ResponseType test = guess(b, 9, 9, 8, 8);
    std::cout << ResponseOut(test) << std::endl;
    ResponseType test2 = guess(b, 9, 9, 2, 2);
    std::cout << ResponseOut(test2) << std::endl;

    Coordinates *test3 = find_ships(b, 9, 9, 3);
    std::cout << "Found ship at " << test3->x << ", " << test3->y << std::endl;

    destroy_board(b, 9);
}