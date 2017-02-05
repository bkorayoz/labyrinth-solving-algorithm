#ifndef HEDIR_H
#define HEDIR_H
#define SIZE 11
#define START_X 3
#define START_Y 0
#define END_X 7
#define END_Y 9
#define RIGHT 0
#define LEFT 1
#define UP 2
#define DOWN 3

#include <iostream>
#include <string>
#include <stack>
#include <time.h>
#include <stdlib.h>

using namespace std;

struct node {

	int xPosition;
	int yPosition;
	bool isdecision;
};
enum  STATUS {DECISION, DEAD, ONEWAY};
bool finish = false;
stack<node> s;

bool solved = false;
int currentX = START_X;
int currentY = START_Y;
char map[10][11] = { "##########",
					 "#        #",
					 "#  # ### #",
					 "  #    # #",
					 "#### ## ##",
					 "# #      #",
					 "#   # ####",
					 "# #    #  ",
					 "#    #   #",
					 "##########" };

void print();
int direction(int x, int y);
bool ispossible(int x, int y, int direction);
bool movement(int x, int y);
bool goback(void);
void clean(void);
STATUS situation(int x, int y);
#endif HEDIR_H
