// author: Aryanthepain
#include "menu.h"

void handle_input(WINDOW *menu, MODE &mode, bool &confirm)
{
	int ch = wgetch(menu);

	switch (ch)
	{
	case KEY_UP:
		mode = single;
		break;
	case KEY_DOWN:
		mode = multi;
		break;
	case 'e':
		confirm = true;
		break;
	default:
		break;
	}
}

void print_mode(WINDOW *menu, MODE mode)
{
	mvwprintw(menu, 6, 0, " ");
	mvwprintw(menu, 7, 0, " ");

	if (mode == single)
	{
		mvwprintw(menu, 6, 0, ">");
	}
	else
	{
		mvwprintw(menu, 7, 0, ">");
	}
	wrefresh(menu);
}

void tutorial(WINDOW *menu, MODE mode)
{
	wclear(menu);

	if (mode == single)
	{
		mvwprintw(menu, 0, 0, "WASD to move");
		mvwprintw(menu, 1, 0, "eat 'A' to increase score");
		mvwprintw(menu, 2, 0, "Do NOT eat yourself");
	}
	else
	{
		mvwprintw(menu, 0, 0, "eat 'A' to increase score");
		mvwprintw(menu, 1, 0, "Do NOT eat yourself");
		mvwprintw(menu, 2, 0, "Do NOT eat other player");
		mvwprintw(menu, 3, 0, "Eliminate other player to win");

		mvwprintw(menu, 5, 0, "Player 1 (O)");
		mvwprintw(menu, 6, 0, "WASD to move");

		mvwprintw(menu, 8, 0, "Player 2 (H)");
		mvwprintw(menu, 9, 0, "arrow keys to move");
	}

	wrefresh(menu);
}

MODE display_menu(WINDOW *menu)
{
	MODE mode = single;

	mvwprintw(menu, 0, 0, "SNAKES GAME BY ARYAN GUPTA");
	mvwprintw(menu, 2, 0, "Make terminal full screen for best experience");
	mvwprintw(menu, 4, 0, "Select game mode:('e' to confirm)");
	mvwprintw(menu, 6, 2, "Single Player");
	mvwprintw(menu, 7, 2, "Two Player");

	wrefresh(menu);

	bool confirm = false;
	while (!confirm)
	{
		print_mode(menu, mode);

		handle_input(menu, mode, confirm);
	}

	wclear(menu);
	wrefresh(menu);

	tutorial(menu, mode);

	napms(1000);
	mvwprintw(menu, 12, 0, "Press any key to continue");
	wrefresh(menu);

	getch();
	werase(menu);
	wrefresh(menu);
	delwin(menu);

	return mode;
}
