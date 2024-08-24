// author: Aryanthepain
#ifndef SNAKE_H
#define SNAKE_H

#include <bits/stdc++.h>
using namespace std;

enum Direction
{
    UP,
    DOWN,
    LEFT,
    RIGHT
};

struct Snake
{
    vector<pair<int, int>> body;
    Direction direction;
    int score;
};

#endif