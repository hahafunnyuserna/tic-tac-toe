#ifndef HEADER_HPP
#define HEADER_HPP

#include <iostream>
#include <stdio.h>
using namespace std;

void createBoard(char board[3][3]);
bool checkWins(char board[3][3], char player);
void gameLoop(char board[3][3], char player, int turns);
void tilItStops(string input);

#endif