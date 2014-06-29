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

int board_vector_test(int i1,int i2,int i3,int i4,char *msg,
                      int o1,int o2,int o3,int o4, int (*func)(int,int **))
{
  int **board=alloca(2*sizeof(int*));
  board[0]=alloca(sizeof(int)*2);
  board[1]=alloca(sizeof(int)*2);
  board[0][0]=i1; board[1][0]=i2; board[0][1]=i3; board[1][1]=i4;

  if (msg) printf("%s - ",msg); 
  else {
    printf("Board operation on {{%d,%d},{%d,%d}} yields {{%d,%d},{%d,%d}} - ",
             i1,i2,i3,i4,o1,o2,o3,o4);
  }
  fflush(stdout);
  func(2,board);
  if ((board[0][0]!=o1)||(board[1][0]!=o2)
      ||(board[0][1]!=o3)||(board[1][1]!=o4))
    {
      printf("FAILED: {{%d,%d},{%d,%d}} became {{%d,%d},{%d,%d}} instead of"
             " {{%d,%d},{%d,%d}}\n",
             i1,i2,i3,i4,
             board[0][0],board[1][0],board[0][1],board[1][1],
             o1,o2,o3,o4);
      return -1;
    } 
  printf("PASSED.\n");
  return 0;
}

int board3_vector_test(int i1,int i2,int i3,int i4,int i5,
                       int i6,int i7,int i8,int i9,char *msg,
                       int o1,int o2,int o3,int o4,int o5,
                       int o6,int o7,int o8,int o9,
                       int (*func)(int,int **))
{
  int **board=alloca(3*sizeof(int*));
  board[0]=alloca(sizeof(int)*3);
  board[1]=alloca(sizeof(int)*3);
  board[2]=alloca(sizeof(int)*3);
  board[0][0]=i1; board[1][0]=i2; board[2][0]=i3;
  board[0][1]=i4; board[1][1]=i5; board[2][1]=i6;
  board[0][2]=i7; board[1][2]=i8; board[2][2]=i9;

  if (msg) printf("%s - ",msg); 
  else {
    printf("Board operation on {{%d,%d,%d},...} yields {{%d,%d,%d}...} - ",
             i1,i2,i3,o1,o2,o3);
  }
  fflush(stdout);
  func(3,board);
  if (
      (board[0][0]!=o1)||(board[1][0]!=o2)||(board[2][0]!=o3)||
      (board[0][1]!=o4)||(board[1][1]!=o5)||(board[2][1]!=o6)||
      (board[0][2]!=o7)||(board[1][2]!=o8)||(board[2][2]!=o9)
      )
    {
     printf("FAILED: {{%d,%d,%d},{%d,%d,%d},{%d,%d,%d}} became {{%d,%d,%d},{%d,%d,%d},{%d,%d,%d}} instead of"
             " {{%d,%d,%d},{%d,%d,%d},{%d,%d,%d}}\n",
             i1,i2,i3,i4,i5,i6,i7,i8,i9,
             board[0][0],board[1][0],board[2][0],
             board[0][1],board[1][1],board[2][1],
             board[0][2],board[1][2],board[2][2],
             o1,o2,o3,o4,o5,o6,o7,o8,o9);
      return -1;
    } 
  printf("PASSED.\n");
  return 0;
}

int board4_vector_test(int i1,int i2,int i3,int i4,
					   int i5,int i6,int i7,int i8,
					   int i9,int i10, int i11, int i12, 
					   int i13, int i14, int i15, int i16, char *msg,
                       int o1,int o2,int o3,int o4,
					   int o5,int o6,int o7,int o8,
					   int o9,int o10,int o11,int o12, 
					   int o13, int o14, int o15, int o16,
                       int (*func)(int,int **))
{
  int **board=alloca(4*sizeof(int*));
  board[0]=alloca(sizeof(int)*4);
  board[1]=alloca(sizeof(int)*4);
  board[2]=alloca(sizeof(int)*4);
  board[3]=alloca(sizeof(int)*4);
  board[0][0]=i1; board[1][0]=i2; board[2][0]=i3; board[3][0]=i4; 
  board[0][1]=i5; board[1][1]=i6; board[2][1]=i7; board[3][1]=i8;
  board[0][2]=i9; board[1][2]=i10; board[2][2]=i11; board[3][2]=i12;
  board[0][3]=i13;board[1][3]=i14; board[2][3]=i15; board[3][3]=i16; 


  if (msg) printf("%s - ",msg); 
  else {
    printf("Board operation on {{%d,%d,%d,%d},...} yields {{%d,%d,%d,%d}...} - ",
             i1,i2,i3,i4,o1,o2,o3,o4);
  }
  fflush(stdout);
  func(4,board);
  if (
      (board[0][0]!=o1)||(board[1][0]!=o2)||(board[2][0]!=o3)||(board[3][0])||
      (board[0][1]!=o4)||(board[1][1]!=o5)||(board[2][1]!=o6)||(board[3][1])||
      (board[0][2]!=o7)||(board[1][2]!=o8)||(board[2][2]!=o9)||(board[3][2])||
	  (board[0][3]!=o7)||(board[1][3]!=o8)||(board[2][3]!=o9)||(board[3][3])      
      )
    {
     printf("FAILED: {{%d,%d,%d,%d},{%d,%d,%d,%d},{%d,%d,%d,%d}} became {{%d,%d,%d,%d},{%d,%d,%d,%d},{%d,%d,%d,%d}} instead of"
             " {{%d,%d,%d,%d},{%d,%d,%d,%d},{%d,%d,%d,%d}}\n",
             i1,i2,i3,i4,i5,i6,i7,i8,i9,i10,i11,i12,i13,i14,i15,i16,
             board[0][0],board[1][0],board[2][0],board[3][0],
             board[0][1],board[1][1],board[2][1],board[3][1],
             board[0][2],board[1][2],board[2][2],board[3][2],
			 board[0][3],board[1][3],board[2][3],board[3][3],
             o1,o2,o3,o4,o5,o6,o7,o8,o9,o10,o11,o12,o13,o14,o15,o16);
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
  e|=ttl_vector(0,0,0,0,"(L)Empty list is empty after shift",0,0,0,0);
  e|=ttl_vector(1,0,0,0,"(L)Value on left stays on left after shift",1,0,0,0);
  e|=ttl_vector(0,0,0,1,"(L)Value on right shifts to left edge after shift",1,0,0,0);
  e|=ttl_vector(0,0,1,0,"(L)Value in middle shifts to left edge after shift",1,0,0,0);
  e|=ttl_vector(1,2,4,8,"(L)Distinct values don't combine",1,2,4,8);
  e|=ttl_vector(1,1,1,1,"(L)Combinations don't cascade",2,2,0,0);
  e|=ttl_vector(1,1,1,0,"(L)Cominations do occur from left when tilting from left.",2,1,0,0);
  e|=ttl_vector(0,0,1,1,"(L)Combinations occur on shift",2,0,0,0);
  e|=ttl_vector(4,0,1,1,"(L)Combinations occur on partial shift",4,2,0,0);
  e|=ttl_vector(2,0,1,1,"(L)Single combination does not cascade",2,2,0,0);
  return e;
}

int test_tilt_right()
{
  int e=0;
  e|=ttr_vector(0,0,0,0,"(R)Empty list is empty after shift",0,0,0,0);
  e|=ttr_vector(0,0,0,1,"(R)Value on right stays on right after shift",0,0,0,1);
  e|=ttr_vector(1,0,0,0,"(R)Value on left shifts to right edge after shift",0,0,0,1);
  e|=ttr_vector(0,0,1,0,"(R)Value in middle shifts to right edge after shift",0,0,0,1);
  e|=ttr_vector(1,2,4,8,"(R)Distinct values don't combine",1,2,4,8);
  e|=ttr_vector(1,1,1,1,"(R)Combinations don't cascade",0,0,2,2);
  e|=ttr_vector(1,1,1,0,"(R)Cominations do occur from left when tilting from left.",0,0,1,2);
  e|=ttr_vector(0,0,1,1,"(R)Combinations occur on shift",0,0,0,2);
  e|=ttr_vector(1,1,0,4,"(R)Combinations occur on partial shift",0,0,2,4);
  e|=ttr_vector(2,0,1,1,"(R)Single combination does not cascade",0,0,2,2);
  return e;
}

int test_board2()
{
  int e=0;
  e|=board_vector_test(1,0,0,0,"Tilt single value Right",0,1,0,0,board_rotate_right);
return e;
}

int main(int argc,char **argv)
{
  int e=0;
  e|=test_tilt_left();
  e|=test_tilt_right();
  e|=test_board2();
  return e;
}
