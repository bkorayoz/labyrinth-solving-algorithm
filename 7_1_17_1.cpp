/*	
	B.Koray OZ ~ Labyrinth ~ 7.1.2017
 */

#include "hedir.h"

int main(void) {
	system("COLOR 0A");
	system("PAUSE");
	map[START_X][START_Y] = 'o';
	srand(time(NULL));
	movement(START_X, START_Y);
	print();
	clean();
	system("PAUSE");
	return EXIT_SUCCESS;
};

void print() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {	
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	_sleep(300);
	if(!finish) system("CLS");
};

bool ispossible(int x, int y, int direction) {

	switch (direction) {
		
	case RIGHT:
		y++;
		break;
	case LEFT:
		y--;
		break;
	case UP:
		x--;
		break;
	case DOWN:
		x++;
		break;
	default:
		cout << "boka sardi" << endl;
		return false;
	}
	
	return (map[x][y] == ' ');
};

int direction(int x, int y) {
	int yon;
	while (true) {
		yon = rand() % 4;
		if ((currentY == START_Y) && yon == LEFT) continue; // ilk adim.
		else if (situation(currentX, currentY) == DEAD) {
			//map[currentX][currentY] = 'X';
			//print();
			//cout << endl;
			if(s.top().isdecision) s.pop();
			goback();
		}
		else if (ispossible(currentX, currentY, yon)) return yon;
	}
};

STATUS situation(int x, int y) {
	int available = 0;
	if (map[x][y + 1] == ' ') available++;
	if (map[x][y - 1] == ' ') available++;
	if (map[x + 1][y] == ' ') available++;
	if (map[x - 1][y] == ' ') available++;
	if ((x == END_X) && y == END_Y) return ONEWAY;
	if (available > 1) return DECISION;
	if (available == 0) return DEAD;
	else return ONEWAY;
};

bool movement(int x, int y) {
	
	if ((x == END_X) && (y == END_Y)) {
		cout << "EXIT FOUND !!!" << endl << endl;
		finish = true;
		return false;
	}
	node temp;
	switch (direction(currentX,currentY)) {

	case RIGHT:	
		currentY++;
		temp.xPosition = currentX;
		temp.yPosition = currentY;
		if (situation(currentX, currentY) == DECISION) {
			temp.isdecision = true;
			s.push(temp);
		}
		else if (situation(currentX, currentY) == ONEWAY) {
			temp.isdecision = false;
			s.push(temp);
		}
		else {
			temp.isdecision = false;
			goback();
		}
		map[currentX][currentY] = 'o';
		print();
		cout << endl;
		break;
	case LEFT:
		--currentY;
		//node temp;
		temp.xPosition = currentX;
		temp.yPosition = currentY;
		if (situation(currentX, currentY) == DECISION) {
			temp.isdecision = true;
			s.push(temp);
		}
		else if (situation(currentX, currentY) == ONEWAY) {
			temp.isdecision = false;
			s.push(temp);
		}
		else {
			temp.isdecision = false;
			goback();
		}
		map[currentX][currentY] = 'o';
		print();
		cout << endl;
		break;
	case UP:
		--currentX;
		//node temp;
		temp.xPosition = currentX;
		temp.yPosition = currentY;
		if (situation(currentX, currentY) == DECISION) {
			temp.isdecision = true;
			s.push(temp);
		}
		else if (situation(currentX, currentY) == ONEWAY) {
			temp.isdecision = false;
			s.push(temp);
		}
		else {
			temp.isdecision = false;
			goback();
		}
		map[currentX][currentY] = 'o';
		print();
		cout << endl;
		break;
	case DOWN:
		++currentX;
		//node temp;
		temp.xPosition = currentX;
		temp.yPosition = currentY;
		if (situation(currentX, currentY) == DECISION) { 
			temp.isdecision = true; 
			s.push(temp);
		}
		else if (situation(currentX, currentY) == ONEWAY) {
			temp.isdecision = false;
			s.push(temp);
		}
		else {
			temp.isdecision = false;
			goback();
		}
		map[currentX][currentY] = 'o';
		print();
		cout << endl;
		break;
	default:
		
		return false;
	}
	
	movement(currentX, currentY);
};

bool goback(void) {
	
	node temp;
	temp = s.top();
	if (temp.isdecision) {
		map[currentX][currentY] = 'X';
		print();
		cout << endl;
		currentX = temp.xPosition;
		currentY = temp.yPosition;
		return false;
	}
	else {
		map[temp.xPosition][temp.yPosition] = ' ';
		print();
		cout << endl;
		currentX = temp.xPosition;
		currentY = temp.yPosition;
		s.pop();
		if (!goback()) return true;
	}
};

void clean(void) {
	
	while (!(s.empty())) {
		s.pop();
	}
};