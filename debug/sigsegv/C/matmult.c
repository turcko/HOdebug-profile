/* 
 * This source code was implemented as example for a debugging session
 * of the Workshop on Advanced Techniques for Scientific Programming
 * and Management of Open Source Software Packages.  The code
 * impements an inefficient version of a matrix multiplication such as
 * C = A * AT.  Where A, AT and C are square matrix of dimension SIZE
 * x SIZE.
 */ 


#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#ifdef __SMALL
#define SIZE 100
#else 
#define SIZE 2500
#endif

void mat_Tmat_mul( float * A, float * C ){

  int i, j, k;
  //float temp[SIZE][SIZE];
  temp = (float *) malloc(SIZE * SIZE * sizeof(float));

  for (i = 0; i < SIZE; i++)
    for (j = 0; j < SIZE; j++)
      //temp[j][i] = A[(i * SIZE) + j];
      temp[(i * SIZE) + j] = [(i * SIZE) + j];

  for (i = 0; i < SIZE; i++)
    for (j = 0; j < SIZE; j++)
      for (k = 0; k < SIZE; k++)
        C[(i * SIZE) + j] += A[(i * SIZE ) + k] * temp[k][j];
  
}

int main(int argc, char * argv[]){
  
  int i, j;
  float *A, *C;
  
  A = (float *) malloc(SIZE * SIZE * sizeof(float));
  C = (float *) malloc(SIZE * SIZE * sizeof(float));
  
  for (i = 0; i < SIZE; i++) {
    for (j = 0; j < SIZE; j++) {
      A[(i * SIZE) + j] = ((float) i) / j;
    }
  }
   
  memset(C, 0, SIZE * SIZE * sizeof(float));
  
  mat_Tmat_mul(A, C);
  
  free(A);
  free(C);

  return 0;
}