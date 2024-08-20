// author:Aryanthepain
#include <ncurses/curses.h>
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
	// timeout(100);

	int max_x, max_y;
	getmaxyx(stdscr, max_y, max_x);

	Snake snake1, snake2;
	int food_x, food_y;
	init_game(snake1, snake2, food_x, food_y, max_x, max_y);

	while (true)
	{
		// Handle input
		// Update game state
		// Draw everything
		// Check for game over
	}
	getch();
	// Cleanup
	endwin();
	return 0;
}
