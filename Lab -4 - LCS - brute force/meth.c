#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 50
#include"LCS.h"
static int max=0;
void copy(char *A, char *B){
int i;
 for(i=0; B[i]!='\0'; ++i)
    {
        A[i]=B[i];
    }
    A[i]='\0';
}

char LCS[SIZE];
char A[SIZE];
int h=0;
void findLCS(int begin,char *str1,char *str2){
int i=begin,j,k,last;
j=k=last=0;
//printf("%s %s\n",str1,str2);
while(i<strlen(str1)){
 if(last == strlen(str2) && i!=strlen(str1))
   break;
 if(j==strlen(str2)){
  j = last;
  i++;
 }
   
 if(str1[i]==str2[j]){
    LCS[k++] = str1[i];
	i++; j++;
    last = j; 
  }
  else
   j++;
  
}

/*A[h] = LCS;
h++;*/
//printf("LCS is   %s  , length :  %d\n",LCS,k);
if(strlen(LCS)>max){
 max = strlen(LCS);
 copy(A,LCS);
 }
}

void displayLCS(){
  if(max==0)
    printf("No common subsequence exists in the given pair of strings.\n");
  else  
    printf("The longest common subsequence is: %s of length %d",A,max);
} 