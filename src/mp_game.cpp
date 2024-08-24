//author: Aryanthepain
#include "mp_game.h"


void mp_game(WINDOW *stdscr, WINDOW *win, int max_x, int max_y){
	Snake snake1, snake2;
	int food_x, food_y;
	init_game(snake1, snake2, food_x, food_y, max_x, max_y, win);
	bool food_present = true;
	int winner=0;
	
	mvwprintw(stdscr, max_y+2, 1, "Scores:");
	mvwprintw(stdscr, max_y+4, 1, "Snake 1(O):");
	mvwprintw(stdscr, max_y+5, 1, "Snake 2(H):");
		
	timeout(100); // getch set to time out after 100ms
	while (true)
	{
		handle_input(snake1, snake2);

		// remove tail piece
		mvwprintw(win, snake1.body.back().second, snake1.body.back().first, " ");
		mvwprintw(win, snake2.body.back().second, snake2.body.back().first, " ");

		// update food and snakes
		food_present = (update_snake(snake1, max_x, max_y, food_x, food_y) && update_snake(snake2, max_x, max_y, food_x, food_y));
		update_food(food_present, snake1, snake2, food_x, food_y, max_x, max_y);

		draw(snake1, snake2, food_x, food_y, win);
		draw_score(stdscr, snake1.score, snake2.score, max_y);
		wrefresh(win);

		// Check for collisions
		if (winner=check_collision(snake1, snake2))
		{
			if(winner==3)
				mvwprintw(win, max_y/2-2, max_x/3-4, "It is a DRAW!!!");
			else{
				mvwprintw(win, max_y/2-2, max_x/3-4, "Player %d wins!!!", winner);
			}
			break; // End the game if a collision occurs
		}
	}
	
	return;
}
