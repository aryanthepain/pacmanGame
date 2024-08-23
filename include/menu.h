// author:Aryanthepain
#ifndef MENU_H
#define MENU_H
#include <curses.h>
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;

enum MODE{single, multi};

MODE display_menu(WINDOW * menu);

#endif

