#include<stdio.h>
#include"matrix.h"
#include<stdlib.h>
#include<time.h>
void initializeMatrix(int **A,int row,int col){
int i,j;
srand(time(NULL));
  for(i=0;i<row;i++)
    for(j=0;j<col;j++)
      A[i][j] = rand()%10;
}

void printMatrix(int **A,int row,int col){
  int i,j;
  for(i=0;i<row;i++){
    for(j=0;j<col;j++)
      printf("%d ",A[i][j]);
   printf("\n");
  }
  printf("\n");
}

void spiralize(int **A,int row,int col){
 int left=0,right=row-1,top=0,bottom=col-1;
 int lb=col-2,rb=1,bb=row-2,tb=1,i;
 while(top<=right && left<bottom){
   for(i=left;i<=lb;i++)
     A[left][i] = left;
     left++;   
	 lb--;
   
   //printMatrix(A,row,col);
   for(i=col-1-bottom;i<=bb;i++)
     A[i][bottom] = col-1-bottom;
	 bottom--;
     bb--;
   
   //printMatrix(A,row,col);
   for(i=col-(row-right);i>=rb;i--)
     A[right][i] = row-1-right; 
     right--;
	 rb++;
    
	//printMatrix(A,row,col);
	for(i=row-1-top;i>=tb;i--)
	 A[i][top] = top;
	 top++;
	 tb++;
	
	//printMatrix(A,row,col);
	//printf("\ntop: %d bottom: %d left: %d right: %d\n",top,bottom,left,right);
  }
  
  if(row==col && row%2!=0)
    A[row/2][col/2]=left;
}