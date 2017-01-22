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

void reduceToZero(long long int A[8][8]){
int i,j,min,max,times,flag,a,m,n,onef;

for(j=0;j<1;j++){ 
  flag = 1;
  printf("COLUMN: %d\n",j+1);
  while(zeroCheck(A,j)){
  printf("\nZero status : %d\n",zeroCheck(A,j));
  onef=0;
  min = INT_MAX;
  //printing matrix here: 
   for(m=0;m<8;m++){
   for(n=0;n<8;n++)
     printf("%lld\t ",A[m][n]);
   printf("\n");
 }
 printf("\n");

     for(i=0;i<8;i++){
	     if(A[i][j]<min)
	       min = A[i][j];
     }
	 printf("\n%d -> minimum\n",min);
     times = min;
	 
         for(i=0;i<8;i++){
	       if(min!=1){
	         if(A[i][j]==min){
               printf("n>1 == min\n");			 
	           while(times!=1){
                decrementCol(A,j);
	             times--;
               }	   
	          doubleRow(A,i);
             }	   
	       }     
	      else{
	        if(A[i][j]==min){
			 printf("One is min element here\n");
	          doubleRow(A,i);
			  onef=1;}
	        }
		  }
		  if(onef){
		    printf("\n decreasing\n");
		    decrementCol(A,j);
		}
		for(i=0;i<8;i++)
		  if(A[i][j]!=1){
		    flag=0;
			break;
		  }
		
		if(flag){
		decrementCol(A,j);
		break;
		}
     }
  
 }

}