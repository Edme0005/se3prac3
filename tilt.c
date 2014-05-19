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

  // slide tiles to the left
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
