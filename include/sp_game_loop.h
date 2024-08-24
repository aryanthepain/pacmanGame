// author: Aryanthepain
#ifndef MP_GAME_LOOP_H
#define MP_GAME_LOOP_H
#include <curses.h>
#include <bits/stdc++.h>
#include "snake.h"

#define pb push_back
#define mp make_pair
using namespace std;

void sp_handle_input(Snake &snake1);
bool sp_update_snake(Snake &snake, int max_x, int max_y, int food_x, int food_y);
void sp_update_food(bool &food_present, Snake &snake1, int &food_x, int &food_y, int max_x, int max_y);
bool sp_check_collision(const Snake &snake1);
void sp_draw(Snake &snake1, int &food_x, int &food_y, WINDOW *win);
void sp_init_game(Snake &snake1, int &food_x, int &food_y, int max_x, int max_y, WINDOW *win);
void sp_draw_score(WINDOW *stdscr, int a, int high, int max_y);

#endif
