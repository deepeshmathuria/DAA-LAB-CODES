#include<stdio.h>
#include"methods.h"
#include<stdlib.h>
void printTable(int X[20][20][20],int l,int m,int n){
  int i,j,k;
  for(i=0;i<=l;i++){
    for(j=0;j<=m;j++){
	  for(k=0;k<=n;k++){
	    printf("\tA[%d][%d][%d]: %d",i,j,k, X[i][j][k]);
	  }
	  printf("\n");
	}
   }
}

int max(int a,int b,int c){
if(a>b){
  if(a>c)
    return a;
  else 
    return c;
 }
else{
  if(b>c)
    return b;
  else
    return c;
 }
}

void lcs( char X[20], char Y[20], char Z[20], int l, int m, int n ){  
   static int L[20][20][20];
   int i,j,k;
   printf("Input strings are: %s : %d %s : %d %s: %d\n",X,l,Y,m,Z,n);
   for (i=0; i<=l; i++){
     for (j=0; j<=m; j++){
	   for (k=0; k<=n; k++){
         if (i == 0 || j == 0 || k==0)
           L[i][j][k] = 0;
         else if (X[i-1] == Y[j-1] && X[i-1] == Z[k-1])
           L[i][j][k] = L[i-1][j-1][k-1] + 1;
         else
           L[i][j][k] = max(L[i-1][j][k], L[i][j-1][k],L[i][j][k-1]); 
        }
      }
    }
   //printTable(L,l,m,n);
   int index = L[l][m][n];
   char lcs[index+1];
   lcs[index] = '\0'; 
   i = l; j = m; k=n;
   while (i > 0 && j > 0 && k>0)
   {
      if (X[i-1] == Y[j-1] && X[i-1]== Z[k-1])
      {
          lcs[index-1] = X[i-1];		  
          i--; j--; k--; index--;    
      }
 
      else if (L[i-1][j][k] > L[i][j-1][k]){
	      if(L[i-1][j][k]>L[i][j][k-1])
		    i--;
		  else
		    k--;
	  }
      else{
	      if(L[i][j-1][k]>L[i][j][k-1])
		    j--;
		  else
		    k--;
	  }
   }
   printf("LCS is : %s", lcs);
}