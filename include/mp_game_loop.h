// author:Aryanthepain
#ifndef MP_GAME_LOOP_H
#define MP_GAME_LOOP_H
#include <curses.h>
#include <bits/stdc++.h>
#include "snake.h"

#define pb push_back
#define mp make_pair
using namespace std;

void handle_input(Snake &snake1, Snake &snake2);
bool update_snake(Snake &snake, int max_x, int max_y, int food_x, int food_y);
void update_food(bool &food_present, Snake &snake1, Snake &snake2, int &food_x, int &food_y, int max_x, int max_y);
int check_collision(const Snake &snake1, const Snake &snake2);
void draw(Snake &snake1, Snake &snake2, int &food_x, int &food_y, WINDOW *win);
void init_game(Snake &snake1, Snake &snake2, int &food_x, int &food_y, int max_x, int max_y, WINDOW *win);
void draw_score(WINDOW *stdscr, int a, int b, int max_y);

#endif
