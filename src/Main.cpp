// author: Aryanthepain
#include "Main.h"

int main()
{
	// Initialize ncurses
	initscr();
	if (stdscr == nullptr)
	{
		cerr << "Error initializing ncurses." << endl;
		return 1;
	}
	cbreak();			  // makes ncurses work for a single character
	noecho();			  // inout does not display on terminal
	keypad(stdscr, TRUE); // special keys are able to be input
	curs_set(0);		  // removes cursor
	//	timeout(100); //waits for getch() for 100ms, otherwise outputs ERR

	int start_x, start_y;
	getmaxyx(stdscr, start_y, start_x);

	// menu screen
	WINDOW *menu = newwin(start_y, start_x, 0, 0);
	if (menu == nullptr)
	{
		endwin();
		cerr << "Error creating menu window." << endl;
		return 1;
	}
	refresh();
	MODE mode;
	mode = display_menu(menu);
	/*	//debug code
	if(mode==single){
			mvwprintw(stdscr, 0,0, "single");
		}
		refresh();
		getch();
	*/
	WINDOW *win = newwin(min(30, 2 * start_y / 3), min(100, 2 * start_x / 3), 1, 0);
	int max_x, max_y;
	getmaxyx(win, max_y, max_x);

	mvwprintw(stdscr, 0, (max_x - 26) / 2, "SNAKES GAME BY ARYAN GUPTA");
	refresh();
	box(win, 0, 0);
	wrefresh(win);
	
	if(mode==single) sp_game(stdscr, win, max_x, max_y);
	else mp_game(stdscr, win, max_x, max_y);

	// quit screen
	// different win conditions
	mvwprintw(win, max_y / 2, max_x / 3, "GAME OVER!");
	wrefresh(win);

	// delay after game ends to prevent accidental clicks
	napms(2000);
	mvwprintw(win, max_y / 2 + 2, max_x / 3-5, "Press any key to continue");
	wrefresh(win);
	timeout(-1);
	getch();

	// Cleanup
	endwin();
	return 0;
}
