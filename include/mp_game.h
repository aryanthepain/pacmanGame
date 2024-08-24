// author:Aryanthepain
#ifndef MP_GAME_H
#define MP_GAME_H
#include <curses.h>
#include <bits/stdc++.h>
#include "snake.h"
#include "mp_game_loop.h"

#define pb push_back
#define mp make_pair
using namespace std;

void mp_game(WINDOW *stdscr, WINDOW *win, int max_x, int max_y);

#endif
