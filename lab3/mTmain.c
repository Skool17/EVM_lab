#include <stdio.h>
#include "myTerm.h"

int main() {
		
	unsigned int x = 0, y = 0, d;
	
	unsigned int *row = &x, *col = &y;
	
	mt_clrscr();
	d = mt_getscreensize(row, col);
	
	d = mt_gotoXY(*row/2, *col/2);
	d = mt_setfgcolor(red);
	d = mt_setgbcolor(blue);
	write(1, "tet", 3);
	d = mt_setfgcolor(yellow);
	d = mt_setgbcolor(red);
	write(1, "ris\n", 4);
	
	y = mt_setfgcolor(9);
	y = mt_setgbcolor(9);
	return 0;
}
