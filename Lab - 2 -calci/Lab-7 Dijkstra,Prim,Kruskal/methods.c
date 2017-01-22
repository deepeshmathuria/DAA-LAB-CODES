#include"graph.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define VER 9
#define EDGES 20
#define MAX_NO 32765

struct Node{
char c;
int color; 
int deg; 
int index;
int start;  //start index for adjacency list
int wt;
};

struct Table{
struct Node ver;
int p;
int d;
};

struct Edge{
struct Node u;
struct Node v;
int wt;
};

struct set{
int filled;
struct Node nodes[VER];
int emptied;
};

struct Table table[VER];
struct set sets[VER];
struct Edge edges[EDGES],soln[VER];
int vertices,qlen,noe;    //no of edges
struct Node **Graph,path[VER];
int heap[VER][2];                                              //0th column contains index and 1th column D-values; 

int ensureRandom(int src,int addn){
  int i,flag=0;
  //printf("src : %c  addn:%c\n",Graph[src][0].c,Graph[addn][0].c);
  for(i=1;i<=Graph[src][0].start;i++){
    if(Graph[src][i].index==addn){
	  flag = 1;
	  break;
	 }
	}
  if(flag)
    return 0;
  else 
    return 1;
}

void printGraph(int v){
 int i,j;
 for(i=0;i<v;i++){
 printf("%c ", Graph[i][0].c); 
 for(j=1;j<Graph[i][0].deg+1;j++)
   printf("%c(%d)", Graph[i][j].c,Graph[i][j].wt); 
 printf("\n");
}
}

int appendable(int index){
  int i,flag=0,ans;
  for(i=index;i<vertices;i++){
      if(i==index)
	    continue;
	  if(Graph[i][0].deg - Graph[i][0].start){
	     ans = ensureRandom(index,i);
		 if(ans){
	     flag = 1;
          break;
		  }		 
	  }
	}
  if(flag==0){
    Graph[index][0].deg = Graph[index][0].start;
	}
  return flag;
  }

void printHeap(){
int i;
printf("INDEX\t\tD\n");
for(i=0;i<qlen;i++)
  printf("%d\t\t%d\n",heap[i][0],heap[i][1]);
}

void printPriorityQueue(){
int i;
printf("\nVERTEX\t\td\t\tpi\n");
for(i=0;i<vertices;i++)
  printf("%c\t\t%d\t\t%d:\n",table[i].ver.c,table[i].d,table[i].p);
}
  
void makePriorityQueue(){
  int i;
  for(i=0;i<vertices;i++){
    table[i].ver = Graph[i][0]; 
	table[i].p = -1;  //equivalent to NIL
	heap[i][0] = i;
	heap[i][1]= MAX_NO;
    table[i].d = heap[i][1];	 
  }
 }

void shiftby1(){
  int i;
  for(i=0;i<qlen-1;i++){
    heap[i][0] = heap[i+1][0];
    heap[i][1] = heap[i+1][1];	
    }
	qlen--;
}

void prioritize(){
  int min = heap[0][1],pos,index,temp,i;
  for(i=0;i<qlen;i++)
    if(heap[i][1]<min){
      index = i;
    } 
  temp = heap[0][0];	
  heap[0][0] = heap[index][0];
  heap[index][0] = temp;
  temp = heap [0][1];	
  heap[0][1] = heap[index][1];
  heap[index][1] = temp;
}

int inQueue(int j){
  int i,found=0;
  for(i=0;i<qlen;i++){
     if(heap[i][0]==j){
	   found = 1;
	   break;
	 }
    }
 return found;
}

void prim(){
  heap[0][1]= table[0].d =0;
  qlen = vertices;
  struct Node min;
  int i,j;
  while(qlen>0){   //while Queue is not Empty
    min = Graph[heap[0][0]][0];  //- > neighbours
	shiftby1();                 //dequeued
    for(i=1;i<min.deg+1;i++){
      if(inQueue(Graph[min.index][i].index) && table[Graph[min.index][i].index].d>Graph[min.index][i].wt){
	     table[Graph[min.index][i].index].p = min.index; 
	     table[Graph[min.index][i].index].d = Graph[min.index][i].wt;
	     for(j=0;j<qlen;j++){
		   if(heap[j][0]  == Graph[min.index][i].index)
		     heap[j][1] = Graph[min.index][i].wt;
		    }
        }
    }
	prioritize();
  }
}

void dijsktra(int src){
  heap[src][1]= table[src].d =0;
  qlen = vertices;
  prioritize();
  struct Node min;
  int i,j,k=0;
  while(qlen>0){   //while Queue is not Empty
    min = Graph[heap[0][0]][0];  //- > neighbours
	path[k++] = min;
	shiftby1();                 //dequeued
    for(i=1;i<min.deg+1;i++){
      if(table[Graph[min.index][i].index].d>table[min.index].d+Graph[min.index][i].wt){
	     table[Graph[min.index][i].index].p = min.index; 
	     table[Graph[min.index][i].index].d = table[min.index].d+ Graph[min.index][i].wt;
	     for(j=0;j<qlen;j++){
		   if(heap[j][0]  == Graph[min.index][i].index)
		     heap[j][1] = table[min.index].d + Graph[min.index][i].wt;
		    }
        }
    }
	prioritize();
  }
}

void printEdges(){
int i;
printf("\n\nu\t\tv\t\tWT\n");
for(i=0;i<noe;i++)
  printf("%c\t\t%c\t\t%d\n",edges[i].u.c,edges[i].v.c,edges[i].wt);
}


void sortEdges(){
  int min,pos,i,j;
  struct Edge temp;
  for(i=0;i<noe;i++){
    min = edges[i].wt;
	pos = i;
    for(j=i;j<noe;j++){
      if(edges[j].wt<min){
	    pos = j;
		min = edges[j].wt;
		}
    }
	temp = edges[i];
	edges[i] = edges[pos];
	edges[pos] =temp;
  }
}

void makeSet(){
int i;
for(i=0;i<vertices;i++){
  sets[i].nodes[sets[i].filled] = Graph[i][0];  
  sets[i].filled++; 
 }
}

int findSet(struct Node v){
  int i,j,pos=-1;
  for(i=0;i<vertices;i++){
    if(sets[i].emptied==1)
      continue;
    else{
	 for(j=0;j<sets[i].filled;j++)
	   if(sets[i].nodes[j].c==v.c)
	     pos = i;
	}
    if(pos==i)
      break;	
  }
  return pos;
}

void merge(int a1,int a2){
int i,j;
sets[a2].emptied = 1;
for(i=0,j=sets[a1].filled;i<sets[a2].filled;i++,j++,sets[a1].filled++)
   sets[a1].nodes[j] = sets[a2].nodes[i];
}

void kruskal(){
  int i,a,b,k=0;
  makeSet();
  for(i=0;i<noe;i++){
     a = findSet(edges[i].u);
	 b = findSet(edges[i].v);
    if(a!=b){
	  soln[k++] = edges[i];
	  merge(a,b);
	}
  }
  for(i=0;i<k;i++)
    printf("u:%c v:%c\n",soln[i].u.c,soln[i].v.c);
}

void generateGraph(int v, int deg){
srand(time(NULL));
int i,j,k=0,Edges,index,w;
Graph = (struct Node **) malloc(v * sizeof(struct node*));
vertices =v;
//creating vertices
 for(i=0;i<v;i++){
     Edges = (rand()%deg)+1;
	 if(Edges<=v-2){
    Graph[i] = (struct Node *)malloc((Edges+1) * sizeof(struct Node));
	Graph[i][0].deg = Edges;
	Graph[i][0].index = i;
	Graph[i][0].c = 65+i;
	Graph[i][0].start = 0;
	//printf("Node : %c,degree: %d\n", Graph[i][0].c,Graph[i][0].deg);
	}
	else
	 i--;
    }
	
 //add neighbours to each vertex
 for(i=0;i<v-1;i++){
     j= Graph[i][0].deg-Graph[i][0].start;
	 while(j>0 && appendable(i)){
	    index = (rand()%(v-(i+1)))+i+1;
	    if(i!=index && ensureRandom(i,index) && Graph[index][0].deg-Graph[index][0].start>0){
		  w = rand()%10+1;
		  Graph[i][0].start++;
		  Graph[i][Graph[i][0].start] = Graph[index][0];
		  Graph[i][Graph[i][0].start].wt = w;
		  Graph[index][Graph[index][0].start+1] = Graph[i][0];
		  Graph[index][Graph[index][0].start+1].wt = w;
		  Graph[index][0].start++;
		  edges[k].u = Graph[i][0];
          edges[k].v = Graph[index][0];
          edges[k].wt = w;		 
          k++;		  
		  j--;  
		}
	  }
    } 
   noe = k;	
  printGraph(v);
 makePriorityQueue();  //makes both pi,d table and minHeap;
  prim();
  printf("\nPRIM\n");
  printPriorityQueue();
  sortEdges();
  //printEdges();
  printf("\nKRUSKAL\n");
  kruskal();
  makePriorityQueue();
  dijsktra(0);
  printf("\nDIJKSTRA\n");
   printPriorityQueue();
}