#include<stdio.h>
#include"graph.h"
#include<stdlib.h>
#include<time.h>
#define VERTICES 5
#define DEGREE 2

void main(){
int V;
srand(time(NULL));
V = (rand()%8)+2;
printf("vertices : %d\n",V);
generateGraph(V,DEGREE);
//BFS();





}