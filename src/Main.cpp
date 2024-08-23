// author:Aryanthepain
#include <curses.h>
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;

enum Direction{UP, DOWN, LEFT, RIGHT};

struct Snake
{
	vector<pair<int, int>> body;
	Direction direction;
};


void draw(Snake &snake1, Snake &snake2, int &food_x, int &food_y, WINDOW* win){
	//draw food
	mvwprintw(win, food_y, food_x,"A");
	
	//draw snake1
	for(size_t i=0;i<snake1.body.size();i++){
		mvwprintw(win, snake1.body[i].second, snake1.body[i].first, "#");
	}
	
	//draw snake 2
	for(size_t i=0;i<snake2.body.size();i++){
		mvwprintw(win, snake2.body[i].second, snake2.body[i].first, "H");
	}
}

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


bool update_snake(Snake &snake, int max_x, int max_y, int food_x, int food_y) {
    int new_x = snake.body[0].first;
    int new_y = snake.body[0].second;
    
    switch (snake.direction) {
        case UP: new_y--; break;
        case DOWN: new_y++; break;
        case LEFT: new_x--; break;
        case RIGHT: new_x++; break;
    }
	
	// Handle boundary conditions (walls wrapping)
    if (new_x < 1) new_x = max_x - 2;
    if (new_x >= max_x - 1) new_x = 1;
    if (new_y < 1) new_y = max_y - 2;
    if (new_y >= max_y - 1) new_y = 1;
	
    snake.body.insert(snake.body.begin(), mp(new_x, new_y));
    if (new_x!=food_x || new_y!=food_y){
	    snake.body.pop_back();
	    return true;//food is still present
	}
	
	return false;//no food
}


bool check_collision(const Snake &snake1, const Snake &snake2) {
    //check if both snakes collide with each other
    if(snake1.body[0]==snake2.body[0]) return true;
    
    // Check if snake1 collides with itself
    for (size_t i = 1; i < snake1.body.size(); i++) {
        if (snake1.body[0] == snake1.body[i]) return true;
        if(snake2.body[0]==snake1.body[i]) return true;
    }
    // Check if snake2 collides with itself
    for (size_t i = 1; i < snake2.body.size(); i++) {
        if (snake2.body[0] == snake2.body[i]) return true;
        if(snake1.body[0]==snake2.body[i]) return true;
    }
    // Add additional collision checks as needed
    return false;
}

bool food_still_present(const Snake &snake1, const Snake &snake2, int food_x, int food_y) {
    // Check if food collides with snake1
    for (size_t i = 0; i < snake1.body.size(); i++) {
        if (food_x == snake1.body[i].first && food_y == snake1.body[i].second) return false;
    }
    // Check if food collides with snake2
    for (size_t i = 0; i < snake2.body.size(); i++) {
        if (food_x == snake2.body[i].first && food_y == snake2.body[i].second) return false;
    }
    // Add additional collision checks as needed
    return true;
}


void handle_input(Snake &snake1, Snake &snake2) {
    int ch = getch();
    switch (ch) {
        case 'w': if(snake1.direction==DOWN) break; snake1.direction = UP; break;
        case 's': if(snake1.direction==UP) break; snake1.direction = DOWN; break;
        case 'a': if(snake1.direction==RIGHT) break; snake1.direction = LEFT; break;
        case 'd': if(snake1.direction==LEFT) break; snake1.direction = RIGHT; break;
        case KEY_UP: if(snake2.direction==DOWN) break; snake2.direction = UP; break;
        case KEY_DOWN: if(snake2.direction==UP) break; snake2.direction = DOWN; break;
        case KEY_LEFT: if(snake2.direction==RIGHT) break; snake2.direction = LEFT; break;
        case KEY_RIGHT: if(snake2.direction==LEFT) break; snake2.direction = RIGHT; break;
    }
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
		
		food_present=(update_snake(snake1, max_x, max_y, food_x, food_y) && update_snake(snake2, max_x, max_y,food_x, food_y));
		
		while(!food_present){
			food_x=rand()%(max_x-2)+1;
			food_y=rand()%(max_y-2)+1;
			food_present=true;
			
			//food spawns on a snake
			food_present=food_still_present(snake1, snake2, food_x, food_y);
		}

		draw(snake1, snake2, food_x, food_y, win);
		wrefresh(win);

		// Check for collisions
		if (check_collision(snake1, snake2)) {
		    break; // End the game if a collision occurs
		}
	}

//quit screen
//different win conditions

	getch();
	// Cleanup
	endwin();
	return 0;
}
