#include "logic.h"
#include <cstdlib>
#include <iostream>

bool **create_board(const int height, const int width) {
  bool **board;
  *board = (bool *)malloc(sizeof(bool) * height);

  for (int i = 0; i < height; i++) {
    *board[i] = (bool *)malloc(sizeof(bool) * width);
  }

  return board;
}

void destroy_board(bool **board, const int height) {
  for (int i = 0; i < height; i++) {
    bool *arry = board[i];
    free(arry);
  }
  free(*board);
}

void place_ships(bool **board, const int shipcount, const int width, const int height)
{
  for (int i = 0; i < shipcount; i++)
  {
    int xCoord = rand() % width;
    int yCoord = rand() % height;
    board[xCoord][yCoord] = 1;
  }
}

Coordinates *find_ships(bool **board, const int width, const int height)
{
  Coordinates *ret;

  ResponseType lastGuess;
  Coordinates *nearMissCoords;
  int xGuess;
  int yGuess;

  while (lastGuess == MISS){
    xGuess = rand() % width;
    yGuess = rand() % height;
    
    currGuess = guess(board, xGuess, yGuess);
    lastGuess = currGuess;
    
    if (currGuess == HIT) {
      ret->x = xGuess;
      ret->y = yGuess;
      return ret;
    }
    if (currGuess == NEAR_MISS){
      nearMissCoords->x = xGuess;
      nearMissCoords->y = yGuess;
    }
  }
  
  while (lastGuess != HIT){
    for(int i = -1; i <= 1; i++)
    {
      for(int j = -1; j <= 1; j++)
      {
        if (guess(board, nearMissCoords->x+i, nearMissCoords->y+j) == HIT){
          ret->x = nearMissCoords->x+i;
          ret->y = nearMissCoords->y+j;
          return ret;
        }
      }
    }
  }

  return ret;
}

ResponseType guess(bool **board, const int x, const int y) {
  if(board[x][y] == 1)
  {
    return HIT;
  }
  
  else if
  {
    for(int i = -1; i <= 1; i++)
    {
      for(int j = -1; j <= 1; j++)
      {
        if (board[x+i][y+j] == 1)
        {
          return NEAR_MISS;
        }
      }
    }
  }
  
  return MISS;
}

// int main(){
//   bool **board = create_board(6,6);
//   //place_ships(board, 3, 10, 10);
//   destroy_board(board, 6);
  
//   // for(int y = 0; y < 10; y++)
//   // {
//   //   for(int x = 0; x < 10; x++)
//   //   {
//   //     std::cout << board[y][x] <<std::endl;
//   //   }
//   // }
// }