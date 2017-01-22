#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"funcs.h"
#define MAX_INT 1000000
typedef struct rcTable pTab;
int sz,smin=MAX_INT;
clock_t start,end;
void testCaseGenerator(int T){
srand(time(NULL));
int i,j,p;
FILE *fp;
fp = fopen("input_file.txt","w");
fprintf(fp,"%d\n",T);
i = rand()%10+1;
j = rand()%10+1;
fprintf(fp,"%d %d\n",i,j);
for(i=2;i<T;i++){
  p = rand()%10+1;
  fprintf(fp,"%d %d\n",j,p);
  j=p;
}
  p = rand()%10+1;
  fprintf(fp,"%d %d",j,p);
fclose(fp);
}

void printSmin(){
printf("\nSecond minimum is: %d",smin);
}

void printOrder(int s[sz][sz],int i, int j){
   if(i==j)
     printf("M%d",i+1);
   else{
    printf("(");
    printOrder(s,i,s[i][j]);
    printOrder(s,s[i][j]+1,j);
    printf(")");
   }
}

void mcmDP(pTab *table,int size){
  
  sz= size;
  int mul[size][size],l,i,j,k,min;  //l =length of chain
  int trace[size][size];

  for(i=0;i<size;i++){
    for(j=0;j<size;j++){
      mul[i][j]=0;
      trace[i][j]=0;
    }
  }
  start = clock();
  for(l=1;l<size;l++){
    for(i=0;i<size-l;i++){
      j = i+l;
	  if(i==j)
	    mul[i][j] =0;
	  else
        mul[i][j] = 99999; 
	  for(k=i;k<j;k++){
	    min = mul[i][k]+ mul[k+1][j]+ table[i].row*table[k].col*table[j].col;
	    if(min<mul[i][j]){
	      mul[i][j] = min;
	      trace[i][j] =k;
	    }
	   }
    }
}
end =  clock();

  printf("\n\n");
  for(i=0;i<size;i++){
    for(j=0;j<size;j++)
      printf("%d\t\t",mul[i][j]);
      printf("\n");
   }
  printf("\n\n\n");

  for(i=0;i<size;i++){
    for(j=0;j<size;j++)
      printf("%d\t\t",trace[i][j]);
      printf("\n");
  }
  printf("\nChain Order is:\n\t");
  printOrder(trace,0,size-1);
  printf("\n\nExecution time: %f",(double)(end - start)/CLOCKS_PER_SEC);
}

int mcmBForce(pTab *table, int i, int j){
    if(i==j)
      return 0;
    int k, muls;
    int min = MAX_INT;
    for (k=i; k<j; k++){
      muls = mcmBForce(table, i, k) +  mcmBForce(table, k+1, j) + table[i].row*table[k].col*table[j].col;
      if (muls < min)
        min = muls;
	  else if(muls < MAX_INT)
	    smin = muls;
    }	
    return min;
}