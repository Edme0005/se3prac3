#include <stdio.h>
#include "2048.h"

int test_tilt(int (*func)(int,int *)) {
	int shortLine[1] = {1};
	int longLine[255];
	int i;
	for (i = 0; i < 255; i++)
		longLine[i] = 0;

	int e = 1;
	e &= func(0, shortLine);
	e &= !func(1, shortLine);
	e &= !func(255, longLine);
	e &= func(256, longLine);

	return e;
}

int test_tilt_left() {
	return test_tilt(tilt_line_left);
}

int test_tilt_right() {
	return test_tilt(tilt_line_right);
}

