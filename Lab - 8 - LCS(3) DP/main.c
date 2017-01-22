#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"methods.h"

int main()
{
  char X[20],Y[20],Z[20];
  FILE *fp;
  fp = fopen("inputs.txt","r");
  fscanf(fp,"%s",X);
  fscanf(fp,"%s",Y);
  fscanf(fp,"%s",Z);
  fclose(fp);
  int l = strlen(X);
  int m = strlen(Y);
  int n = strlen(Z);
  lcs(X, Y, Z, l, m, n);
  return 0;
}