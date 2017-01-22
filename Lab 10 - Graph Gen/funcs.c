#include<stdio.h>
#include<stdlib.h>
#include"methods.h"

void transform(int **Graph, int V){
int i,j,k;
for(i=0;i<V;i++){
 for(j=0;j<V;j++){
   if(Graph[i][j]<2 && i!=j){
   for(k=0;k<V;k++){
      if(j!=k && Graph[i][k]!=0){
	    if(Graph[k][j]>=1){
	      Graph[i][j] = 0;
		  Graph[i][k]+=1;
		  break;
	    }	
	  }  
    }
   }
 }
}
}

void generateGraph(int V){
int **Graph;
int i,j;
Graph = (int **) malloc(V*sizeof(int *));
for(i=0;i<V;i++)
  Graph[i] = (int *)malloc(V*sizeof(int));
  
for(i=0;i<V;i++)
  for(j=0;j<V;j++){
    if(i!=j)
	  Graph[i][j] = 1;
	else 
	  Graph[i][j] = 0;
  }
     
for(i=0;i<V;i++){
  printf("%c -->",65+i);   
  for(j=0;j<V;j++)
    if(i!=j)
      printf(" %c  ",65+j);
   printf("\n");
    }
	
printf("\n\nAfter applying transform function\n");	
	
transform(Graph,V);
int noe =0;
for(i=0;i<V;i++){
  printf("%c -->",65+i);   
  for(j=0;j<V;j++)
   if(Graph[i][j]!=0){
      printf(" %c  ",65+j);
      noe++;
    }
   printf("\n")  ;
    }
printf("\n No. of edges-> before transform: %d after transform: %d ",V*(V-1),noe);
}