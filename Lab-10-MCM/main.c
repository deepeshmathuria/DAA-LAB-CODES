#include<stdio.h>
#include<stdlib.h>
#include"funcs.h"
#include<time.h>
typedef struct rcTable ptable;

void main(){
FILE *fp;
clock_t start, end;
int n,i;
int pcol;
int T;
printf("Enter Test Cases to be generated: ");
scanf("%d",&T);
testCaseGenerator(T);
fp = fopen("input_file.txt","r");
fscanf(fp,"%d",&n);
printf("%d\n",n);
struct rcTable *table;
table = (struct rcTable *)malloc(sizeof(struct rcTable)*n);
i=0;
while(!feof(fp)){
  fscanf(fp,"%d %d",&table[i].row, &table[i].col);
  printf("%d %d\n",table[i].row, table[i].col);
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
start = clock();
int mins = mcmBForce(table,0,n-1);
end = clock();
printf("\n\n Minimum no. of multiplications by BruteForce : %d",mins);
printSmin();
printf("\n\nExecution time: %f",(double)(end - start)/CLOCKS_PER_SEC);
mcmDP(table,n);
}