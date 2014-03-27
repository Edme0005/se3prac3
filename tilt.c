#include <stdio.h>
#include "2048.h"

int tilt_line_left(int length,int *line)
{
  // make sure vector length is sensible
  if (length<1||length>255) return -1;

  // slide tiles to the left
  int next = 0;
  for (int i = 0; i < length; i++) {
  	if (line[i] != 0) {
  		line[next] = line[i];
  		line[i] = 0;
  		next++;
  	}
  }

	/*
  // combine tiles as required
  for (int i = 0; i < length; i++) {
  	if (line[i] == line[i+1]) {
  		
  		//slide values down
  		for (int j = i+1; j < length | line[j+1] != 0; j++) {
  			line[j] = line[j+1]
  		}
  	}
  }
  */
  return 0;
}
