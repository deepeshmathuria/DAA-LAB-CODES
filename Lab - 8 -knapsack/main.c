#include<stdio.h>
#include<stdlib.h>
#include"methods.h"
void main(){
  FILE *fp;
  fp = fopen("items.txt","r");
  if(fp==NULL){
    printf("NULLIFIED");
  exit(0);
  }
  int n,i;
  int W;
  int **A;
  fscanf(fp,"%d",&n);
  A = (int **) malloc( n * sizeof(int*));
  for(i=0;i<n;i++)
    A[i] = (int *) malloc(2*sizeof(int));
  fscanf(fp,"%d",&W);
   printf("%d -> n , %d ->W\n",n,W);  
  i=0;
  while(!feof(fp)){
  fscanf(fp,"%d %d",&A[i][0],&A[i][1]);
  i++;
  }
  
 
  for(i=0;i<n;i++){
    printf("%d  %d\n",A[i][0],A[i][1]);
  
  }

  fracKnapsack(A,n,W);
  zero1Knapsack(A,n,W);
}