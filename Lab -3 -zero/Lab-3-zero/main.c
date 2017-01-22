#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"reduction.h"

void initializeInputFile(FILE *fp){
  int i=0,n;
  while(i<64){
   n =  rand()%10+1;
   printf("%d ",n);
    fprintf(fp,"%d\t",n);
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
 	
  initializeInputFile(fp);
 	
  fp = fopen("inputs.txt","r");
	
 for(i=0;i<8;i++)
    for(j=0;j<8;j++){
      fscanf(fp,"%lld",&A[i][j]);
 }
  printf("\n");
  reduceToZero(A);  
 
  for(i=0;i<8;i++){
   for(j=0;j<8;j++)
     printf("%lld\t ",A[i][j]);
   printf("\n");
 }
 
 
 fclose(fp);
}