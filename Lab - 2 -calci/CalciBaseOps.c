#include"CalciBaseOps.h"
#include<stdio.h>
#define SIZE 20

struct entry{    //Entry struct for Look-up table
int v;
char c;
};
 
struct entry LookUpTable[SIZE];
int n=0;

int initializeCalciBase(FILE *fp){
char str[2];
while(1){
  fscanf(fp,"%s",str);
  if(feof(fp))
    break;
  LookUpTable[n].c = str[0];
  LookUpTable[n].v = n;
  n++;
 }
 fclose(fp);
 return n;
}

int CalciLookup(char c)
{ /*: looks-up the character in the Base lookup table and returns the value associated with the character. */
  int i;
  for(i=0;i<n-1;i++)
    if(c==LookUpTable[i].c)
	  return LookUpTable[i].v;
} 

char valueLookup(int v){
  int i;
  for(i=0;i<n-1;i++)
    if(v==LookUpTable[i].v)
	  return LookUpTable[i].c;
}

