#include <stdio.h>
#include <stdlib.h>
#include "methods.h"

void main(){
	int V,i,j,f,s,t;
	float p;
	FILE *fp;
	fp=fopen("inputs.txt","r");
	fscanf(fp,"%d",&V);
	fscanf(fp,"%d %d",&s,&t);
	int **graph;
        float **prob;
	graph=(int **)malloc(V* sizeof(int *));
	for(i=0;i<V;i++)
	  graph[i]=(int *)malloc(V * sizeof(int));
	
	for(i=0;i<V;i++)
      for(j=0;j<V;j++)
	    graph[i][j]=0;
	
        prob=(float **)malloc(V* sizeof(float *));
	for(i=0;i<V;i++)
          prob[i]=(float *)malloc(V * sizeof(float));

	for(i=0;i<V;i++)
      for(j=0;j<V;j++)
	     prob[i][j]=0;
	
	while(!feof(fp)){
		fscanf(fp,"%d %d %d %f",&i,&j,&f,&p);
        graph[i][j]=f;
		prob[i][j] = p;
	}
    for(i=0;i<V;i++){
		for(j=0;j<V;j++)
			printf("%d,%.2f\t",graph[i][j],prob[i][j]);
		printf("\n");
	}
	fclose(fp);
    relPath(graph,s,t,V,prob);
     
}