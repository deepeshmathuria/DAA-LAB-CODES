#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"reduction.h"

void initializeInputFile(FILE *fp){
  int i=1;
  while(i<=64){
    fprintf(fp,"%d\t",rand()%10+1);
    i++;
  }
 fclose(fp);
}

void main(){
  long long int A[8][8];
  int i,j;
  srand(time(NULL));
  FILE *fp;
  fp = fopen("inputs.txt","w+");
  printf("Here I am babe!\n");	
  //initializeInputFile(fp);
  printf("Here I am babe! 2 \n");	
  fp = fopen("inputs.txt","r");
  printf("Here I am babe! 3 \n");
  
  for(i=0;i<8;i++)
   for(j=0;j<8;j++)
      A[i][j] = rand()%10+1;
	
  reduceToZero(A);
  
  for(i=0;i<8;i++){
   for(j=0;j<8;j++)
     printf("%lld\t ",A[i][j]);
   printf("\n");
 }
 
 fclose(fp);
}