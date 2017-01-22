#include<stdio.h>
#include<stdlib.h>

struct table{
float ratio;
int index;
};

void sort(struct table *A,int n){
  int pos,i,j;
  struct table temp;
  float max;
  for(i=0;i<n;i++){
    max = A[i].ratio;
	pos = i;
    for(j=i;j<n;j++){
      if(A[j].ratio>max){
	    pos = j;
		max = A[j].ratio;
		}
    }
	temp = A[i];
	A[i] = A[pos];
	A[pos] =temp;
  }
}

void fracKnapsack(int **A,int n,int W){ 
  int i; float val;
  float w =(float)W;
  float fraction = 0.00,b;
  struct table *B;
  B = (struct table *)malloc(n*sizeof(struct table));
  for(i=0;i<n;i++){
    B[i].ratio = (float)A[i][1]/A[i][0] ;
    B[i].index = i; 
   }	
 sort(B,n);
 i = 0;
 val =0;
while(w>0)
  {
    if(w - (float)A[B[i].index][0]>0){
	   w = w - (float)A[B[i].index][0];
           val = val+ A[B[i].index][1];
	  printf("Item picked-> value : %d, weight : %d Remaining weight: W %f\n",A[B[i].index][1],A[B[i].index][0],w);
	  i++;
	}
	else{
	  b = w;
	  while(b>0){
	     fraction+=0.01;
		  b = (float) b-fraction*A[B[i].index][0];
	  }
          val = val + fraction*A[B[i].index][1];
	  printf("Last item picked :  value : %d, weight : %d , fraction %f\n",A[B[i].index][1],A[B[i].index][0],fraction);
	  w*=-1;
	}
  }
  printf("Total profit obtained : %f\n",val);
}

int max(int a, int b){
 if(a-b>=0)
  return a;
  else
  return b; 
}

void zero1Knapsack(int **A,int n,int W){
int B[n+1][W+1],i,j;
for(i=0;i<W+1;i++)
  B[0][i] = 0;

 for(i=1;i<=n;i++){
   for(j=0;j<=W;j++){
     if(A[i-1][0]>j)
	   B[i][j] = B[i-1][j];
	 else{
	   B[i][j] = max(B[i-1][j], B[i-1][j-A[i-1][0]]+A[i-1][1]); 
	 }   
   } 
  }
  
  printf("\n");
   for(i=1;i<=n;i++){
   for(j=1;j<=W;j++){
   printf("%d\t",B[i][j]);
   }
   printf("\n");
   }
   
   printf("Items picked: \n");
   i=n;
   j=W;
   while(B[i][j]){
    if(B[i][j]==B[i-1][j])
     i--;
    else
    {  printf("Item : %d\n",i-1);
       j = j - A[i-1][0];
       i--;	   
   }
   }
   printf("Max profit obtained : %d",B[n][W]);
}