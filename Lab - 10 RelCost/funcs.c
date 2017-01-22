#include <stdio.h>
#include <stdlib.h>
#include "methods.h"
#define MAX_INT 100000

int q[100];
int front=0,rear=0;
int rgraph[10][10],parent[10];
int cpath[10];
int solpath[10];

void enqueue(int v){
	if(front!=rear+1)
       q[rear++]=v;
	else{
		printf("QUEUE OVERFLOW!!!\n");
		exit(0);
	}
}

int dequeue(){
	if(rear!=front)
        return q[front++];
	else{
		printf("QUEUE EMPTY!!!\n");
		exit(0);
	}
}

int BFS(int s,int t,int V){
    int visited[V],v,u,i;
    for(i=0;i<V;i++)
    	visited[i]=0;
    enqueue(s);
    visited[s] = 1;
    parent[s] = -1;
    
//    printf("%d  s=%d t=%d\n",V,s,t);
    while (front!=rear){
        u =dequeue();
        for (v=0; v<V; v++) {
       // 	printf("u=%d v=%d rgraph=%d\n",u,v,rgraph[u][v]);
            if ( visited[v]==0 && rgraph[u][v] > 0){
                enqueue(v);
                parent[v] = u;
                visited[v] = 1;
            }
        }
    }
	 printf("\n");
//    printf("t=%d\n",visited[t]);
    if(visited[t]==1)
    	return 1;
    return 0;
}

void relPath(int **graph,int s,int t,int V,float **prob){
    float cpflow,pflow=0;
    int i,j,k;
	float relCost;
    for(i=0;i<V;i++)
    	for(j=0;j<V;j++)
    		rgraph[i][j]=graph[i][j]; 
			
    while(BFS(s,t,V)){
         	k=0;
	        cpflow = 1;
			int path_flow = MAX_INT;
    		for(j=t;j!=s;j=parent[j]){
    			i=parent[j];			
				cpflow = cpflow*prob[i][j];
				//printf("\nprob: %f",prob[i][j]);
				cpath[k++] = i; 
				printf("\n%d cpath:",cpath[k-1]);
				path_flow=path_flow>rgraph[i][j]?rgraph[i][j]:path_flow;
    		}
		     	printf("\nCCprob: %f",cpflow);
			  for(j=t;j!=s;j=parent[j]){
    			i=parent[j];
    			rgraph[i][j]=rgraph[i][j]-path_flow;
    		}
			if(cpflow>pflow){
			    pflow = cpflow;
				for(i=0;i<k;i++)
				  solpath[i] = cpath[i];
				 relCost= 0;
                 for(j=t;j!=s;j=parent[j]){
    			  i=parent[j];
    			  relCost = relCost+ graph[i][j]*pflow;
    		     }				  
			}
    }
    printf("Most reliable path is :\n\t");
    for(i=0;i<k;i++)
	  	printf("%d\t",solpath[i]);
	printf("Total reliability cost is: %f", relCost);
	
}