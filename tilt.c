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
  		if (i != next) {
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

int rotate_board_90(int l, int **board) {
	if (l < 2||l > 255) return -1;
	
	int s = l-1;
	int o, f; //for loops
	int e, b;
	int temp;
	//process each level of the square.
	for(f = 0; f < l/2; f++) { 
		for(o = f; o < s-f; o++) { 
			b = f;
			e = s-f; 
			//w -> t
			temp = board[b][b+o];
			//s -> w
			board[b][b+o] = board[b+o][e];
			//e -> w
			board[b+o][e] = board[e][e-o];
			//n -> e
			board[e][e-o] = board[e-o][b];
			//t -> n
			board[e-o][b] = temp;
		}
	}
	return 0;
}

int rotate_board_270(int length, int **board) {
	//temp till a more efficient one is made.
	//after the first one is tested.
	rotate_board_90(length, board);
	rotate_board_90(length, board);	
	rotate_board_90(length, board);
	return 0;
}
