#include<stdio.h>
#include"funcs.h"
#include<stdlib.h>

void main()
{
FILE *fp;
int n,**A,i,j,u,v,w;
fp = fopen("inputs.txt","r");
if(fp==NULL)
  printf("\n\nBrutal\n\n");
fscanf(fp,"%d",&n);
A = (int **)malloc(sizeof(int*)*n);
for (j=0;j<n;j++) 
A[j] = (int *)malloc(sizeof(int)*n);
for(i=0;i<n;i++)
  for(j=0;j<n;j++)
    A[i][j] = 0;
while(!feof(fp)){
fscanf(fp,"%d %d %d",&u,&v,&w);
A[u][v] = w;
}
fclose(fp);
//scanf("%d %d",u,v);
for(i=0;i<n;i++){
  for(j=0;j<n;j++)
    printf("%d\t",A[i][j]);
   printf("\n");
   }
maxFlow(A,0,5,n);
}