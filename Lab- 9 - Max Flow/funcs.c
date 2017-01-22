#include<stdio.h>
#include"funcs.h"
#define INT_MAX 32765
#include<stdlib.h>
int nz;
int queue[40],front,rear;
int parent[20], res[50][50]; 
 
 
void enqueue(int v){
if(!(front==rear+1)){
  queue[rear] = v;
  rear++;  
}
} 

int Qempty(){
if(front == rear)
  return 1;
else 
  return 0;
}

void dequeue(){
  if(!Qempty())
     front++;
}

int bfs(int s, int t, int n){
front = 0;
rear=0;
int traversed[n],i,u,v;
for(i=0;i<n;i++){
  traversed[i] = 0;
  }
enqueue(s);
parent[s]= -1;
traversed[s] = 1;
 while (!Qempty())
    {
        u = front;
		printf("\nDequeued : %d : v\n");
        dequeue();
        for (v=0; v<n; v++)
        {
            if (traversed[v]==0 && res[u][v] > 0)
            {
                enqueue(v);
                parent[v] = u;
                traversed[v] = 1;
            }
        }
    }
	printf("t: %d, traversed[t]: %d",t, traversed[t]);
  return traversed[t];
  
} 

int min(int a,int b){
 if(a<b)
   return a;
 else 
   return b;
} 
 
void maxFlow(int **A, int s, int t, int n){

int i,j,u,v,pflow;
for (u = 0; u < n; u++)
        for (v = 0; v < n; v++)
             res[u][v] = A[u][v];		 
int mflow = 0;
nz = n;
int count = 20; 
 while(count !=0){
    bfs(s,t,n);
    pflow = INT_MAX;
	for(v=t;v!=s;v= parent[v]){
	  u = parent[v];
	  pflow = min(pflow,res[u][v]);
	}
	for(v=t;v!=s;v= parent[v]){
	  u = parent[v];
	  res[u][v] -= pflow;
	  res[v][u] += pflow;
	}
	
	mflow += pflow;/*
	    for (u = 0; u < n; u++)
        for (v = 0; v < n; v++)
             printf("u.v : %d %d %d \n",u,v,res[u][v]);*/
    count--;			 
 }
  
 printf("Maximum flow is: %d",mflow);
}