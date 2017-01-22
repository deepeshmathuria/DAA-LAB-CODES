#include"graph.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define VER 8
#define MAX_NO 32765

struct Node{
char c;
int deg; 
int index;
int wt;
};

struct Table{
struct Node ver;
int d;
};

struct Table table[VER];

int vertices,verArr[VER];
struct Node **Graph;

void setArrToZero(){
  int i;
  for(i=0;i<VER;i++)
    verArr[i] = -1;
}

int ensureRandom(int n,int end){
  int i,flag=0;
  for(i=0;i<end;i++)
    if(verArr[i] == n){
	  flag=1;
	  break;
    }
  if(flag)
    return 0;
  else 
    return 1;
}

void printGraph(int v){
int i,j;
for(i=0;i<v;i++){
 printf("%c ",Graph[i][0].c);
 for(j=1;j<Graph[i][0].deg+1;j++)
   printf("%c(%d) ", Graph[i][j].c,Graph[i][j].wt); 
 printf("\n");
}
}

void relax(int u, int v,int wt){
  table[v].d = table[v].d-(table[u].d+wt)<0 ? table[v].d : table[u].d+wt;
}

void printTable(){
int i;
printf("\nVERTEX\t\td\n");
for(i=0;i<vertices;i++)
  printf("%c\t\t%d\n",table[i].ver.c,table[i].d);
}

void bellmanFord(int src){
  int i,j,k;
  for(i=0;i<vertices;i++){
    table[i].ver = Graph[i][0]; 
	table[i].d = MAX_NO; 	 
  }
  table[src].d = 0;
  for(i=0;i<vertices-1;i++){
    for(j=0;j<vertices;j++)
      for(k=1;k<Graph[j][0].deg+1;k++)
	    relax(Graph[j][0].index,Graph[j][k].index,Graph[j][k].wt);	
  }
  printTable();
}

void generateGraph(int v, int deg){
srand(time(NULL));
int i,j,k,edges,index,a,wt;
Graph = (struct Node **) malloc(v * sizeof(struct node*));
vertices =v;
//creating vertices
 for(i=0;i<v;i++){
     edges = (rand()%deg)+1;
    Graph[i] = (struct Node *)malloc((edges+1) * sizeof(struct Node));
	Graph[i][0].deg = edges;
	Graph[i][0].index = i;
	Graph[i][0].c = 65+i;
    }
	
 //add neighbours to each vertex
 for(i=0;i<v;i++){
     j= Graph[i][0].deg;
	 k=1;
	 setArrToZero();
	 while(j>0){
	   index = rand()%v;
	    if((i!=index) && ensureRandom(index,k-1)){
		  wt = rand()%10 + 1;
		  a = rand()%100;
          if(a>=60 && a<=90)
            wt*=-1;		  
		  Graph[i][k] = Graph[index][0];
		  Graph[i][k].wt = wt;
		  verArr[k-1] = index;
		   k++;
		  j--;  
		}
	  }
    }  
  printGraph(v);
  bellmanFord(0);
}