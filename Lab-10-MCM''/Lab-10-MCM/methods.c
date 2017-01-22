#include<stdio.h>
#include"funcs.h"
#define INT_MAX 32765
typedef struct rcTable pTab;
int sz;

void printOrder(int s[sz][sz],int i, int j){
   if(i==j)
     printf("M%d",i+1);
   else{
    printf("(");
    printOrder(s,i,s[i][j]);
    printOrder(s,s[i][j]+1,j);
    printf(")");
   }
}

void mcmDP(pTab *table,int size){
  sz= size;
  int mul[size][size],l,i,j,k,min;  //l =length of chain
  int trace[size][size];

  for(i=0;i<size;i++){
    for(j=0;j<size;j++){
      mul[i][j]=0;
      trace[i][j]=0;
    }
  }

  for(l=1;l<size;l++){
    for(i=0;i<size-l;i++){
      j = i+l;
	  if(i==j)
	    mul[i][j] =0;
	  else
        mul[i][j] = 99999; 
	  for(k=i;k<j;k++){
	    min = mul[i][k]+ mul[k+1][j]+ table[i].row*table[k].col*table[j].col;
	    if(min<mul[i][j]){
	      mul[i][j] = min;
	      trace[i][j] =k;
	    }
	   }
    }
}
  printf("\n\n");
  for(i=0;i<size;i++){
    for(j=0;j<size;j++)
      printf("%d\t\t",mul[i][j]);
      printf("\n");
   }
  printf("\n\n\n");

  for(i=0;i<size;i++){
    for(j=0;j<size;j++)
      printf("%d\t\t",trace[i][j]);
      printf("\n");
  }
  printf("\nChain Order is:\n\t");
  printOrder(trace,0,size-1);
}

int mcmBForce(pTab *table, int i, int j)
{
    if(i==j)
      return 0;
    int k, muls;
    int min = INT_MAX;
    for (k=i; k<j; k++){
      muls = mcmBForce(table, i, k) +  mcmBForce(table, k+1, j) + table[i].row*table[k].col*table[j].col;
      if (muls < min)
        min = muls;
    }	
    return min;
}