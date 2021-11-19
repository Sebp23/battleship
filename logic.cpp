#include "logic.h"
#include <cstdlib>
#include <iostream>


bool **create_board(const int height, const int width) {
  bool **board = (bool **)malloc(sizeof(bool) * height);

  for (int i = 0; i < height; i++) {
    board[i] = (bool *)malloc(sizeof(bool) * width);
  }

  return board;
}

void destroy_board(bool **board, const int height) {
  for (int i = 0; i < height; i++) {
    bool *arry = board[i];
    free(arry);
  }
  free(board);
}

void place_ships(bool **board, const int shipcount, const int width, const int height)
{
  for (int i = 0; i < shipcount; i++)
  {
    int xCoord = rand() % width;
    int yCoord = rand() % height;

    if (board[xCoord][yCoord] == 1)
    {
      i--;
      break;
    }
    else
    {
      board[xCoord][yCoord] = 1;
    }
  }
}
  
Coordinates *find_ships(bool **board, const int width, const int height, const int ship_count)
{
  Coordinates *ret;
  
  ResponseType lastGuess;
  Coordinates *nearMissCoords;
  int xGuess;
  int yGuess;

  while (lastGuess == MISS){
    xGuess = rand() % width;
    yGuess = rand() % height;
    
    ResponseType currGuess = guess(board, height, width, xGuess, yGuess);
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
        if (guess(board, height, width, nearMissCoords->x+i, nearMissCoords->y+j) == HIT){
          ret->x = nearMissCoords->x+i;
          ret->y = nearMissCoords->y+j;
          return ret;
        }
      }
    }
  }

  return ret;
}

ResponseType guess(bool **board, const int height, const int width, const int x, const int y) {
  if(board[x][y] == 1)
  {
    return HIT;
  }
  else
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

std::string ResponseOut(ResponseType r){
  if (r == HIT){
        return "HIT";
  }
  else if (r == NEAR_MISS){
      return "NEAR_MISS";
  }
  else{
      return "MISS";
  }
}