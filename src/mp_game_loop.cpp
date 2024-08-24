// author: Aryanthepain
#include "mp_game_loop.h"

void draw(Snake &snake1, Snake &snake2, int &food_x, int &food_y, WINDOW *win)
{
    // draw food
    mvwprintw(win, food_y, food_x, "A");

    // draw snake1
    for (size_t i = 0; i < snake1.body.size(); i++)
    {
        mvwprintw(win, snake1.body[i].second, snake1.body[i].first, "O");
    }

    // draw snake 2
    for (size_t i = 0; i < snake2.body.size(); i++)
    {
        mvwprintw(win, snake2.body[i].second, snake2.body[i].first, "H");
    }
}

void handle_input(Snake &snake1, Snake &snake2)
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
    case KEY_UP:
        if (snake2.direction == DOWN)
            break;
        snake2.direction = UP;
        break;
    case KEY_DOWN:
        if (snake2.direction == UP)
            break;
        snake2.direction = DOWN;
        break;
    case KEY_LEFT:
        if (snake2.direction == RIGHT)
            break;
        snake2.direction = LEFT;
        break;
    case KEY_RIGHT:
        if (snake2.direction == LEFT)
            break;
        snake2.direction = RIGHT;
        break;
    }
}

bool update_snake(Snake &snake, int max_x, int max_y, int food_x, int food_y)
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

bool food_still_present(const Snake &snake1, const Snake &snake2, int food_x, int food_y)
{
    // Check if food collides with snake1
    for (size_t i = 0; i < snake1.body.size(); i++)
    {
        if (food_x == snake1.body[i].first && food_y == snake1.body[i].second)
            return false;
    }

    // Check if food collides with snake2
    for (size_t i = 0; i < snake2.body.size(); i++)
    {
        if (food_x == snake2.body[i].first && food_y == snake2.body[i].second)
            return false;
    }

    return true;
}

void update_food(bool &food_present, Snake &snake1, Snake &snake2, int &food_x, int &food_y, int max_x, int max_y)
{
    if (food_present)
        return;

    while (!food_present)
    {
        food_x = rand() % (max_x - 2) + 1;
        food_y = rand() % (max_y - 2) + 1;
        food_present = true;

        // food spawns on a snake
        food_present = food_still_present(snake1, snake2, food_x, food_y);
    }

    return;
}

int check_collision(const Snake &snake1, const Snake &snake2)
{
    // check if both snakes collide with each other
    if (snake1.body[0] == snake2.body[0])
    {
        if (snake1.score == snake2.score)
            return 3; // draw conditions
        else if (snake1.score > snake2.score)
            return 1;
        else
            return 2;
    }

    // Check if snake1 collides with itself
    for (size_t i = 1; i < snake1.body.size(); i++)
    {
        if (snake1.body[0] == snake1.body[i])
            return 2;
        if (snake2.body[0] == snake1.body[i])
            return 1;
    }
    // Check if snake2 collides with itself
    for (size_t i = 1; i < snake2.body.size(); i++)
    {
        if (snake2.body[0] == snake2.body[i])
            return 1;
        if (snake1.body[0] == snake2.body[i])
            return 2;
    }

    return false;
}

void init_game(Snake &snake1, Snake &snake2, int &food_x, int &food_y, int max_x, int max_y, WINDOW *win)
{
    // Initialize food position
    food_x = max_x / 2;
    food_y = max_y / 2;

    // initialise snake 1
    snake1.body.pb(mp(3, 1));
    snake1.body.pb(mp(2, 1));
    snake1.body.pb(mp(1, 1));
    snake1.direction = RIGHT;
    snake1.score = 0;

    // initialise snake 2
    snake2.body.pb(mp(max_x - 5, max_y - 3));
    snake2.body.pb(mp(max_x - 4, max_y - 3));
    snake2.body.pb(mp(max_x - 3, max_y - 3));
    snake2.direction = LEFT;
    snake2.score = 0;

    draw(snake1, snake2, food_x, food_y, win);
}

void draw_score(WINDOW *stdscr, int a, int b, int max_y)
{
    mvwprintw(stdscr, max_y + 4, 12, "      ");
    mvwprintw(stdscr, max_y + 5, 12, "      ");
    mvwprintw(stdscr, max_y + 4, 13, "%d", a * 10);
    mvwprintw(stdscr, max_y + 5, 13, "%d", b * 10);
    refresh();
}
