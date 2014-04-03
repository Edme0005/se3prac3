#include <stdio.h>
#include "2048.h"

int line_vector_test(int i1,int i2,int i3,int i4,char *msg,
                int o1,int o2,int o3,int o4, int (*func)(int,int *))
{
  int list[4]={i1,i2,i3,i4};
  if (msg) printf("%s - ",msg); 
  else {
    printf("Tilting {%d,%d,%d,%d} left yields {%d,%d,%d,%d} - ",
             i1,i2,i3,i4,o1,o2,o3,o4);
  }
  fflush(stdout);
  func(4,list);
  if ((list[0]!=o1)||(list[1]!=o2)||(list[2]!=o3)||(list[3]!=o4))
    {
      printf("FAILED: {%d,%d,%d,%d} became {%d,%d,%d,%d} instead of"
             " {%d,%d,%d,%d}\n",
             i1,i2,i3,i4,list[0],list[1],list[2],list[3],
             o1,o2,o3,o4);
      return -1;
    } 
  printf("PASSED.\n");
  return 0;
  
}

int ttl_vector(int i1,int i2,int i3,int i4,char *msg,
               int o1,int o2,int o3,int o4)
{
  return line_vector_test(i1,i2,i3,i4,msg,o1,o2,o3,o4,tilt_line_left);
}

int ttr_vector(int i1,int i2,int i3,int i4,char *msg,
               int o1,int o2,int o3,int o4)
{
  return line_vector_test(i1,i2,i3,i4,msg,o1,o2,o3,o4,tilt_line_right);
}


int test_tilt_left()
{
  int e=0;
  e|=ttl_vector(0,0,0,0,"Empty list is empty after shift",0,0,0,0);
  e|=ttl_vector(1,0,0,0,"Value on left stays on left after shift",1,0,0,0);
  e|=ttl_vector(0,0,0,1,"Value on right shifts to left edge after shift",1,0,0,0);
  e|=ttl_vector(0,0,1,0,"Value in middle shifts to left edge after shift",1,0,0,0);
  e|=ttl_vector(1,2,4,8,"Distinct values don't combine",1,2,4,8);
  e|=ttl_vector(8,4,2,1,"Distinct values don't combine",8,4,2,1);
  e|=ttl_vector(1,1,1,1,"Combinations don't cascade",2,2,0,0);
  e|=ttl_vector(1,2,2,1,"Combines some.",1,4,1,0);
  e|=ttl_vector(4,2,2,0,"Checks order of adding",4,4,0,0);
  e|=ttl_vector(2,2,2,0,"Checks order of adding",4,2,0,0);
  e|=ttl_vector(0,0,1,1,"Values are combined on left",2,0,0,0);
  e|=ttl_vector(4,0,1,1,"Values combine with correct values",4,2,0,0);
  e|=ttl_vector(2,0,1,1,"Values don't cascade",2,2,0,0);
  e|=ttl_vector(4,4,0,1,"Combines some, shifts 1",8,1,0,0);
  e|=ttr_vector(0,0,0,0,"Empty list is empty after shift",0,0,0,0);
  e|=ttr_vector(1,0,0,0,"Value on left stays on right after shift",0,0,0,1);
  e|=ttr_vector(0,0,0,1,"Value on right shifts to right edge after shift",0,0,0,1);
  e|=ttr_vector(0,0,1,0,"Value in middle shifts to right edge after shift",0,0,0,1);
  e|=ttr_vector(1,2,4,8,"Distinct values don't combine",1,2,4,8);
  e|=ttr_vector(8,4,2,1,"Distinct values don't combine",8,4,2,1);
  e|=ttr_vector(1,1,1,1,"Combinations don't cascade",0,0,2,2);
  e|=ttr_vector(1,2,2,1,"Combines some.",0,1,4,1);
  e|=ttr_vector(4,2,2,0,"Checks order of adding",0,0,4,4);
  e|=ttr_vector(2,2,2,0,"Checks order of adding",0,0,2,4);
  e|=ttr_vector(0,0,1,1,"Values are combined on right",0,0,0,1);
  e|=ttr_vector(4,0,1,1,"Values combine with correct values",0,0,4,2);
  e|=ttr_vector(2,0,1,1,"Values don't cascade",0,0,2,2);
  e|=ttr_vector(4,4,0,1,"Combines some, shifts 1",0,0,8,1);
  return e;
}

int main(int argc,char **argv)
{
  int e=0;
  e|=test_tilt_left();
  return e;
}