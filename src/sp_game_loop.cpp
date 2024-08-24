#include "sp_game_loop.h"

void sp_draw(Snake &snake1, int &food_x, int &food_y, WINDOW *win)
{
    // draw food
    mvwprintw(win, food_y, food_x, "A");

    // draw snake1
    for (size_t i = 0; i < snake1.body.size(); i++)
    {
        mvwprintw(win, snake1.body[i].second, snake1.body[i].first, "O");
    }
}

void sp_handle_input(Snake &snake1)
{
    int ch = getch();
    switch (ch)
    {
    case 'w':
        if (snake1.direction == DOWN)
            break;
        snake1.direction = UP;
        break;
    case 's':
        if (snake1.direction == UP)
            break;
        snake1.direction = DOWN;
        break;
    case 'a':
        if (snake1.direction == RIGHT)
            break;
        snake1.direction = LEFT;
        break;
    case 'd':
        if (snake1.direction == LEFT)
            break;
        snake1.direction = RIGHT;
        break;
    }
}

bool sp_update_snake(Snake &snake, int max_x, int max_y, int food_x, int food_y)
{
    int new_x = snake.body[0].first;
    int new_y = snake.body[0].second;

    switch (snake.direction)
    {
    case UP:
        new_y--;
        break;
    case DOWN:
        new_y++;
        break;
    case LEFT:
        new_x--;
        break;
    case RIGHT:
        new_x++;
        break;
    }

    // Handle boundary conditions (walls wrapping)
    if (new_x < 1)
        new_x = max_x - 2;
    if (new_x >= max_x - 1)
        new_x = 1;
    if (new_y < 1)
        new_y = max_y - 2;
    if (new_y >= max_y - 1)
        new_y = 1;

    snake.body.insert(snake.body.begin(), mp(new_x, new_y));
    if (new_x != food_x || new_y != food_y)
    {
        // if it does not eat the food
        snake.body.pop_back();
        return true; // food is still present
    }
	
	snake.score++;
    return false; // no food
}

bool sp_food_still_present(const Snake &snake1, int food_x, int food_y)
{
    // Check if food collides with snake1
    for (size_t i = 0; i < snake1.body.size(); i++)
    {
        if (food_x == snake1.body[i].first && food_y == snake1.body[i].second)
            return false;
    }

    return true;
}

void sp_update_food(bool &food_present, Snake &snake1, int &food_x, int &food_y, int max_x, int max_y)
{
    if (food_present)
        return;

    while (!food_present)
    {
        food_x = rand() % (max_x - 2) + 1;
        food_y = rand() % (max_y - 2) + 1;
        food_present = true;

        // food spawns on a snake
        food_present = sp_food_still_present(snake1, food_x, food_y);
    }

    return;
}

bool sp_check_collision(const Snake &snake1)
{
    // Check if snake1 collides with itself
    for (size_t i = 1; i < snake1.body.size(); i++)
    {
        if (snake1.body[0] == snake1.body[i])
            return true;
    }

    return false;
}

void sp_init_game(Snake &snake1, int &food_x, int &food_y, int max_x, int max_y, WINDOW *win)
{
	// Initialize food position
	food_x = max_x / 2;
	food_y = max_y / 2;

	// initialise snake 1
	// debug code
	/*	snake1.body.pb(mp(12,1));
		snake1.body.pb(mp(11,1));
		snake1.body.pb(mp(10,1));
		snake1.body.pb(mp(9,1));
		snake1.body.pb(mp(8,1));
		snake1.body.pb(mp(7,1));
		snake1.body.pb(mp(6,1));
		snake1.body.pb(mp(5,1));
		snake1.body.pb(mp(4,1));
	*/
	snake1.body.pb(mp(3, 1));
	snake1.body.pb(mp(2, 1));
	snake1.body.pb(mp(1, 1));
	snake1.direction = RIGHT;
	snake1.score = 0;

	sp_draw(snake1, food_x, food_y, win);
}

void sp_draw_score(WINDOW *stdscr, int a, int high, int max_y){
	mvwprintw(stdscr, max_y+2, 8, "             ");
	mvwprintw(stdscr, max_y+2, 12, "%d", a*10);
	mvwprintw(stdscr, max_y+4, 12, "             ");
	mvwprintw(stdscr, max_y+4, 12, "%d", high*10);
	refresh();
}
