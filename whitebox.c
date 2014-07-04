#include <stdio.h>
#include "2048.h"

int test_tilt(int (*func)(int,int *)) {
	int shortLine[1] = {1};
	int longLine[255];
	int i;
	for (i = 0; i < 255; i++)
		longLine[i] = 0;

  	printf("Tilt line, line size 0: [%s]\n", (func(0, shortLine) ? "Pass" : "Fail"));
  	printf("Tilt line, line size 1: [%s]\n", (!func(1, shortLine) ? "Pass" : "Fail"));
  	printf("Tilt line, line size 255: [%s]\n", (!func(255, longLine) ? "Pass" : "Fail"));
  	printf("Tilt line, line size 256: [%s]\n", (func(256, longLine) ? "Pass" : "Fail"));

	return 1;
}

int test_tilt_left() {
	printf("Testing tilt left\n");
	return test_tilt(tilt_line_left);
}

int test_tilt_right() {
	printf("Testing tilt right\n");
	return test_tilt(tilt_line_right);
}

int test_board_rotate() {
  	int **twoBoard=alloca(2*sizeof(int*));
  	twoBoard[0]=alloca(2*sizeof(int*));
  	twoBoard[1]=alloca(2*sizeof(int*));
  	twoBoard[0][0] = 0; twoBoard[1][0] = 0;
  	twoBoard[0][1] = 0; twoBoard[1][1] = 0;

  	int **largeBoard=alloca(255*sizeof(int*));
  	int i;
  	for (i=0;i<255;i++) {
  		largeBoard[i]=alloca(255*sizeof(int**));
  		int j;
  		for (j=0;j<255;j++) {
  			largeBoard[i][j] = 0;
  		}
  	}

  	printf("Testing rotate_board_90\n");
  	printf("Rotate board 90, board size 1: [%s]\n", (rotate_board_90(1, twoBoard) ? "Pass" : "Fail"));
  	printf("Rotate board 90, board size 2: [%s]\n", (!rotate_board_90(2, twoBoard) ? "Pass" : "Fail"));
  	printf("Rotate board 90, board size 255: [%s]\n", (!rotate_board_90(255, largeBoard) ? "Pass" : "Fail"));
  	printf("Rotate board 90, board size 256: [%s]\n", (rotate_board_90(256, largeBoard) ? "Pass" : "Fail"));
  	return 1;
}

int main() {
	test_tilt_left();
	test_tilt_right();
	test_board_rotate();

	return 1;
}