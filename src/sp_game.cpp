//author: Aryanthepain
#include "sp_game.h"


void sp_game(WINDOW *stdscr, WINDOW *win, int max_x, int max_y){
	Snake snake1;
	int food_x, food_y;
	sp_init_game(snake1, food_x, food_y, max_x, max_y, win);
	bool food_present = true;
	int high_score;
	load_high_score(high_score);
	
	mvwprintw(stdscr, max_y+2, 1, "Your Score:");
	mvwprintw(stdscr, max_y+4, 1, "High Score: ");
		
	timeout(50); // getch set to time out after 100ms
	while (true)
	{
		sp_handle_input(snake1);

		// remove tail piece
		mvwprintw(win, snake1.body.back().second, snake1.body.back().first, " ");

		// update food and snakes
		food_present = sp_update_snake(snake1, max_x, max_y, food_x, food_y);
		sp_update_food(food_present, snake1, food_x, food_y, max_x, max_y);
		
		if(snake1.score>high_score){
			high_score=snake1.score;
			save_high_score(high_score);
		}
		
		sp_draw(snake1, food_x, food_y, win);
		sp_draw_score(stdscr, snake1.score,high_score, max_y);
		wrefresh(win);

		// Check for collisions
		if (sp_check_collision(snake1))
		{
			break; // End the game if a collision occurs
		}
	}
	
	return;
}
