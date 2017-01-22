#include<stdio.h>
#include<stdlib.h>
#include"funcs.h"

typedef struct rcTable ptable;

void main(){
FILE *fp;
int n,i;
int pcol;
fp = fopen("inputs.txt","r");
fscanf(fp,"%d",&n);
struct rcTable *table;
table = (struct rcTable *)malloc(sizeof(struct rcTable)*n);
i=0;
while(!feof(fp)){
  fscanf(fp,"%d %d",&table[i].row, &table[i].col);
  if(i!=0 && table[i].row!=pcol){
    printf("Invalid matrix chain supplied");
	exit(0);
  }
  pcol = table[i].col;
  i++;
}


printf("\t\t  Row\t Col");
for(i=0;i<n;i++){
  printf("\n\t\t%d %d\t %d",i+1,table[i].row,table[i].col);
}
int mins = mcmBForce(table,0,n-1);
printf("\n\n Minimum no. of multiplications by BruteForce : %d",mins);
mcmDP(table,n);
}