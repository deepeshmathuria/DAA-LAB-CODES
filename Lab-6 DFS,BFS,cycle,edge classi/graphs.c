#include"graph.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define VER 8
#define SIZE 100
#define SIZE2 15
// color - 0 - white 1 - Gray  2 --> Black
struct Node{
char c;
int arr; int finish; 
int color; int deg; int index;
};
void DFS2(struct Node V);
int t=0,vertices,cyclic=1;
struct Node BFSQ[SIZE];
struct Node Stack[SIZE2];
int front =-1,rear = 0,verArr[VER],top=0;

struct Node **Graph;
int qNotEmpty(){
if(front==rear)
  return 0;
else 
  return 1;
}

void enqueue(struct Node V){
  if(front==-1){
     front++; rear++;
     BFSQ[front] = V;
	 BFSQ[front].color =1;
    }
  else{
     BFSQ[rear] = V;
	 BFSQ[rear].color = 1;
     rear++; 
  }
}

void dequeue(){
  Graph[BFSQ[front].index][0].color = 2;
  printf("\nDequed : %c",BFSQ[front].c);
  front++;
}

void push(struct Node V){
 Stack[top] = V; 
 top++;
}

void pop(){
 struct Node V;
 V = Stack[top];
 printf("\nVertex :%c Finish:%d",Graph[V.index][0].c,Graph[V.index][0].finish);
 top--;
}

int stackNotEmpty(){
if(top ==0)
  return 0;
return 1;
}

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
 for(j=0;j<Graph[i][0].deg+1;j++)
   printf("%c ", Graph[i][j].c); 
 printf("\n");
}
}

void printVerr(){
int i;
for(i=0;i<8;i++)
  printf("%d ",verArr[i]);
 printf("\n");
}

void printQ(){
int i;
printf("\n");
for(i=front;i<rear;i++)
  printf("%c ",BFSQ[i].c);
}

void BFS(struct Node ver){
struct Node V;
int i;
Graph[ver.index][0].color = 1;
enqueue(ver);
while(qNotEmpty()){
for(i=1;i<=BFSQ[front].deg;i++){
   V = Graph[BFSQ[front].index][i];
   if(Graph[V.index][0].color == 0){
     Graph[V.index][0].color = 1;
     enqueue(V);
	 }
	}
   dequeue();
 }
}

void decolorize(int v){
int i;
for(i=0;i<v;i++)
  Graph[i][0].color = 0;
}

int checkAllVisited(){
int i,ind=0;
for(i=1;i<vertices;i++){
 if(Graph[i][0].color!=2){
    ind = i;
	break;
  }
 }
 return ind;
}

void DFS(struct Node V){
  int d = V.deg;
  int j = 0;
    t++;
	Graph[V.index][0].color = 1;
	Graph[V.index][0].arr = t;
	//search for all neighbours
	for(j=1;j<=d;j++){
	   if(Graph[Graph[V.index][j].index][0].color==0){
	     printf("\nTree edge %c --> %c",Graph[V.index][0].c,Graph[Graph[V.index][j].index][0].c);
	     DFS(Graph[V.index][j]);
		 }
		  else if(Graph[Graph[V.index][j].index][0].color==1){
	     cyclic = 1;
		 printf("\nBack edge %c --> %c",Graph[V.index][0].c,Graph[Graph[V.index][j].index][0].c);
		 }
	   else if (Graph[Graph[V.index][j].index][0].color==2)
	     printf("\nCross edge/Back Edge %c --> %c",Graph[V.index][0].c,Graph[Graph[V.index][j].index][0].c);
	}
	t++;
	Graph[V.index][0].finish = t;
	Graph[V.index][0].color = 2;
	printf("\nVertex :%c Arrival:%d Finish:%d",Graph[V.index][0].c,Graph[V.index][0].arr,Graph[V.index][0].finish);
}

void findPath(int src,int dest){
int nop =0,p;
static int j=0;
static struct Node A[10];
int d,i; 
printf("%c %c\n",Graph[src][0].c,Graph[dest][0].c);
d = Graph[src][0].deg;
A[j] = Graph[src][0];
for(i=1;i<=d;i++){
   if(Graph[src][i].index == dest){
     printf("\npath found:");
     for(p=0;p<=j;p++)
       printf("%c ",A[p].c);
	   j--;
       return;	   
    }
   else{
    j++;
    findPath(Graph[src][i].index,dest);
    }
  }
  j--;
}


void top_sort(struct Node V){
  int d = V.deg;
  int j = 0;
    t++;
	Graph[V.index][0].color = 1;
	Graph[V.index][0].arr = t;
	//search for all neighbours
	for(j=1;j<=d;j++)
	   if(Graph[Graph[V.index][j].index][0].color==0)
	     top_sort(Graph[V.index][j]);
	t++;
	push(Graph[V.index][0]);
	Graph[V.index][0].finish = t;
	Graph[V.index][0].color = 2;
	//printf("\nVertex :%c Arrival:%d Finish:%d",Graph[V.index][0].c,Graph[V.index][0].arr,Graph[V.index][0].finish);
}

void generateGraph(int v, int deg){
srand(time(NULL));
int i,j,k,edges,index,src,dest;
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
		  Graph[i][k] = Graph[index][0];
		  verArr[k-1] = index;
		   k++;
		  j--;  
		}
	  }
    }  
  printGraph(v);
  printf("\nBFS traversal of above graph is:");
  BFS(Graph[0][0]);
  while(checkAllVisited()!=0){
    printf("\nNext BFS tree:");
    BFS(Graph[checkAllVisited()][0]);
  }
  decolorize(v);
  printf("\n\nDFS traversal of above graph is:");
  DFS(Graph[0][0]);
  while(checkAllVisited()!=0){
    printf("\n\nNext DFS tree:");
    DFS(Graph[checkAllVisited()][0]);
  }
  if(cyclic){
    printf("\n\nCYCLE EXISTS IN GRAPH!");
	printf("\n Topological sort cannot be performed!");
	}
  else{
   printf("\n\nNO CYCLE EXISTS IN GRAPH!"); 
      top_sort(Graph[0][0]);
   while(checkAllVisited()!=0)
    top_sort(Graph[checkAllVisited()][0]);
   printf("\n\nTopologically sorted graph:");
   while(stackNotEmpty())
     pop();
   }
   printf("Write the nodes you want the path for: ");
   scanf("%d%d",&src,&dest);
   findPath(src,dest);
}