// author:Aryanthepain
#include "Main.h"

void init_game(Snake &snake1, Snake &snake2, int &food_x, int &food_y, int max_x, int max_y, WINDOW* win)
{
	// Initialize food position
	food_x=max_x/2;
	food_y=max_y/2;
	
	//initialise snake 1
/*	snake1.body.pb(mp(12,1));
	snake1.body.pb(mp(11,1));
	snake1.body.pb(mp(10,1));
	snake1.body.pb(mp(9,1));
	snake1.body.pb(mp(8,1));
	snake1.body.pb(mp(7,1));
	snake1.body.pb(mp(6,1));
	snake1.body.pb(mp(5,1));
	snake1.body.pb(mp(4,1));
*/	snake1.body.pb(mp(3,1));
	snake1.body.pb(mp(2,1));
	snake1.body.pb(mp(1,1));
	snake1.direction=RIGHT;
	
	//initialise snake 2
	snake2.body.pb(mp(max_x-5,max_y-3));
	snake2.body.pb(mp(max_x-4,max_y-3));
	snake2.body.pb(mp(max_x-3,max_y-3));
	snake2.direction=LEFT;
	
	draw(snake1, snake2, food_x, food_y, win);
}

int main()
{
	// Initialize ncurses
	initscr();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
	curs_set(0);
	timeout(100);

	int start_x, start_y;
	getmaxyx(stdscr, start_y, start_x);
	refresh();
	
	WINDOW* win=newwin(2*start_y/3, 2*start_x/3,1,0);
	box(win,0,0);
	wrefresh(win);

	int max_x, max_y;
	getmaxyx(win, max_y, max_x);

	Snake snake1, snake2;
	int food_x, food_y;
	init_game(snake1, snake2, food_x, food_y, max_x, max_y, win);
	bool food_present=true;

	while (true) {
		handle_input(snake1, snake2);
		
		//remove tail piece
		mvwprintw(win, snake1.body.back().second, snake1.body.back().first, " ");
		mvwprintw(win, snake2.body.back().second, snake2.body.back().first, " ");
		
		//update food and snakes
		food_present=(update_snake(snake1, max_x, max_y, food_x, food_y) && update_snake(snake2, max_x, max_y,food_x, food_y));
		update_food(food_present, snake1, snake2, food_x, food_y, max_x, max_y);
		
		draw(snake1, snake2, food_x, food_y, win);
		wrefresh(win);

		// Check for collisions
		if (check_collision(snake1, snake2)) {
		    break; // End the game if a collision occurs
		}
	}

//quit screen
//different win conditions
	mvwprintw(win, 3, 3, "hello");
	wrefresh(win);
	napms(1000);
	timeout(-1);
	getch();
	// Cleanup
	endwin();
	return 0;
}
