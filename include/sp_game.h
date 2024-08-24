// author:Aryanthepain
#ifndef SP_GAME_H
#define SP_GAME_H
#include <curses.h>
#include <bits/stdc++.h>
#include "snake.h"
#include "sp_game_loop.h"

#define pb push_back
#define mp make_pair
using namespace std;

void sp_game(WINDOW *stdscr, WINDOW *win, int max_x, int max_y);

#endif
