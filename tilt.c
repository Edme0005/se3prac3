#include <stdio.h>
#include "2048.h"

int tilt_line_left(int length,int *line)
{
  // make sure vector length is sensible
  if (length<1||length>255) return -1;

  // slide tiles to the left
  

  // combine tiles as required
  for (int i = 0; i < length; i++) {
  	if (lane[i] == lane[i+1]) {
  		
  		//slide values down
  		for (int j = i+1; j < length | lane[j+1] != 0; j++) {
  			lane[j] = lane[j+1]
  		}
  	}
  }
  return 0;
}
