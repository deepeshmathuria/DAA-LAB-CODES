#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"matrix.h"

void main(int argc,char *argv[]){
  int i,n = 0,row,col,j,*temp;
  int **arr;  
  printf("What's going on!");
  
  if(argc==1){
    printf("Too few arguments supplied.\nPROCESS ABORTED!!");
    exit(0);
  }
  else{
    for(i=0;i<strlen(argv[1]);i++)
      n = (argv[1][i]-48)+n*10;
	printf("\n%d : n",n);
    if(argc!=n+2){
      printf("Arguments supplied: %d, Expected arguments: %d\nPROCESS ABORTED!!",argc-2,n);
      exit(0);
    }
    else{
      for(i=2;i<argc;i++){
	    row = 0; col=0;
        for(j=0;argv[i][j]!='x';j++)
		  row = (argv[i][j]-48)+row*10;
		for(j=j+1;j<strlen(argv[i]);j++)
          col = (argv[i][j]-48)+col*10;
		  
		printf("\n%d : rows %d : cols\n\n", row,col);
		arr = (int **)malloc(row * sizeof(int*));
        for (j=0;j<row;j++) 
         arr[j] = (int *)malloc(col * sizeof(int));
		initializeMatrix(arr,row,col);
		printMatrix(arr,row,col);
        spiralize(arr,row,col);
		printMatrix(arr,row,col);
		for (j = 0; j< row; j++)
          free(arr[j]);
	     free(arr);
    }
  }
 }
}