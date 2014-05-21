#include <stdio.h>
#include "2048.h"

int tilt_line_left(int length,int *line)
{
  // make sure vector length is sensible
  if (length<1||length>255) return -1;

  // slide tiles to the left
  int next = 0;
  int i;
  for (i = 0; i < length; i++) {
  	if (line[i] != 0) {
  		if ( i != next) {
  			line[next] = line[i];
  			line[i] = 0;
  		}
  		next++;
  	}
  }
  
  // combine tiles as required
  for (i = 0; i < length; i++) {
  	if (line[i] == line[i+1] && line[i] != 0) {
  		line[i] += line[i];
  		//slide values down
  		int j;
  		for (j = i+1; j < length; j++) {
  			line[j] = line[j+1];
  		}
  		line[j] = 0;
  	}
  }
  line[i] = 0;
  
  return 0;
}

int tilt_line_right(int length,int *line) {
	if (length<1||length>255) return -1;

  // slide tiles to the right
  int next = length-1;
  int i;
  for (i = length-1; i >= 0; i--) {
  	if (line[i] != 0) {
  		if ( i != next) {
  			line[next] = line[i];
  			line[i] = 0;
  		}
  		next--;
  	}
  }
  
  // combine tiles as required
  for (i = length-1; i >= 0; i--) {
  	if (line[i] == line[i-1] && line[i] != 0) {
  		line[i] += line[i];
  		//slide values down
  		int j;
  		for (j = i-1; j >= 0; j--) {
  			line[j] = line[j-1];
  		}
  		line[j] = 0;
  	}
  }
  line[i] = 0;
	
	return 0;
}

int rotate_board_90(int length, int **board) {
	if (length < 2) return -1;
	//considering the consistancy in which this method will be called,
	//and that it will in practice only be called on a board of 4x4, or smaller
	//seemed logical to simply hard code the rotations.
	//planning for a board larger would be outside the bounds of the applications needs..
	//but when required would simply only need another else attached to the end.
	if (length == 2) {
		int temp = board[0][0];
		board[0][0] = board[0][1];
		board[0][1] = board[1][1];
		board[1][1] = board[1][0];
		board[1][0] = temp;
	} else if (length == 3) {
		int temp[2];
		temp[0] = board[0][0];
		temp[1] = board[0][1];
		
		board[0][0] = board[0][2];
		board[0][1] = board[1][2];
		board[0][2] = board[2][2];
		board[1][2] = board[2][1];
		board[2][2] = board[2][0];
		board[2][1] = board[1][0];
		board[2][0] = temp[0];
		board[1][0] = temp[1];
	} else if (length == 4) {
		
	}
	return 0;
}
