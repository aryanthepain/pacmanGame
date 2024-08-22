// author:Aryanthepain
#include <curses.h>
#include <bits/stdc++.h>
// #include <ctime>
// using namespace std;

struct Snake
{
	std::vector<std::pair<int, int>> body;
	int direction;
};

void init_game(Snake &snake1, Snake &snake2, int &food_x, int &food_y, int max_x, int max_y)
{
	// Initialize snakes and food position
}

void update_snake(Snake &snake, int max_x, int max_y)
{
	// Update snake position based on direction
}

bool check_collision(const Snake &snake1, const Snake &snake2, int food_x, int food_y)
{
	// Check for collisions
	return false;
}

int main()
{
	// Initialize ncurses
	initscr();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
	curs_set(0);
	//timeout(100);

	int start_x, start_y;
	getmaxyx(stdscr, start_y, start_x);
	refresh();
	
	WINDOW* win=newwin(2*start_y/3, 2*start_x/3,0,0);
	box(win,0,0);
	wrefresh(win);

	int max_x, max_y;

	Snake snake1, snake2;
	int food_x, food_y;
	init_game(snake1, snake2, food_x, food_y, max_x, max_y);

	while (true)
	{
		// Handle input
		// Update game state
		// Draw everything
		// Check for game over
		break;
	}
	getch();
	// Cleanup
	endwin();
	return 0;
}
