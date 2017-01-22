#include<stdio.h>
#include"reduction.h"
#define INT_MAX 100000

int zeroCheck(long long int A[8][8],int col){
//returns 0 if all elements are zero.
 int i;
 int flag=0;
 for(i=0;i<8;i++)
   if(A[i][col]!=0){
     flag=1;
	 break;
   }
  return flag;
}

void printMatrix(long long int A[8][8])
{
int m,n;
for(m=0;m<8;m++){
   for(n=0;n<8;n++)
     printf("%lld\t ",A[m][n]);
   printf("\n");
   }
   printf("\n");

}

int all1(long long int A[8][8],int col){
 int i;
 int flag=0;
 for(i=0;i<8;i++)
   if(A[i][col]!=1){
     flag=1;
	 break;
   }
  return flag;
}

int all2(long long int A[8][8],int col){
 int i;
 int flag=0;
 for(i=0;i<8;i++)
   if(A[i][col]!=2){
     flag=1;
	 break;
   }
  return flag;
}


void doubleRow(long long int A[8][8],int row){
  int i;
  for(i=0;i<8;i++)
   A[row][i]*= 2;
}

void decrementCol(long long int A[8][8],int col){
 int i;
 for(i=0;i<8;i++)
   A[i][col]-= 1;
}

void minimizeCols(long long int A[8][8],int col)
{
  int i,j,min;
  for(j=0;j<8;j++){
   if(j==col)
     continue;
   min=INT_MAX;
   for(i=0;i<8;i++){
     if(A[i][j]<min)
	   min=A[i][j];
     if(min!=1)
       while(min>1){
	    decrementCol(A,j);
	    min--;
	 }
   }
 
  } 

}


void reduceToZero(long long int A[8][8]){
int i,j,min,max,times,a,m,n;
printMatrix(A);
for(j=0;j<2;j++){ 
  //printf("COLUMN: %d\n",j+1);
  while(zeroCheck(A,j)){
  //printf("\nZero status : %d\n",zeroCheck(A,j));
  min = INT_MAX;
  //printing matrix here: 
  //printMatrix(A);
     for(i=0;i<8;i++){
	     if(A[i][j]<min)
	       min = A[i][j];
     }
	// printf("\n%d -> minimum\n",min);
     times = min;
         for(i=0;i<8;i++){
	       if(min!=1){
	         if(A[i][j]==min){
               //printf("n>1 == min\n");			 
	           while(times!=1){
                decrementCol(A,j);
	             times--;
               }	   
             }	   
	       }     
	      else{
	         if(A[i][j]==min){
	          	 if(all1(A,j)){
                    //printf("One is min element here\n");
	                doubleRow(A,i);
	        	  }
				  else 
	        		decrementCol(A,j);
				  if(!all2(A,j))
				  {
				   decrementCol(A,j);
				   decrementCol(A,j);
				  }
	        	 
	          }  
	       }
		   //minimizeCols(A,j);
		    //printf("\nAftr minimizations:\n");
			//printMatrix(A);
		}
     }
   
 }
 for(i=0;i<8;i++){
   for(j=0;j<8;j++)
     if(A[i][j]!=0)
      A[i][j]*=0;
 }
}