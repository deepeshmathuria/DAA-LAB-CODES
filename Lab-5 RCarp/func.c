#include"util.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int convertToNumber(int start,int end,char *A){
int i=start,n=0;
while(i<end){
   n = n*10+(A[i]-48); 
   i++;
  }
return n;
}

void Carp(char *ip, char *pattern){
int i,v,lent=strlen(ip),lenp=strlen(pattern);
int p = convertToNumber(0,strlen(pattern),pattern);
int r = p%11;
int q = p/11;
int spurious = 0, exact=0, unsuccessful=0;
for(i=0;i<=(lent-lenp);i++){
 v = convertToNumber(i,i+strlen(pattern),ip);
 if((v/11)==q && (v%11)==r){
   if(ip[i]=='0')
     printf("Exact hit: 0%d at %d\n",v,i);
   else
     printf("Exact hit: %d at %d\n",v,i); 
   exact++;
   }
 else if((v/11)!=q && (v%11)==r){
   if(ip[i]=='0')
    printf("Spurious hit: 0%d\n",v);
   else
    printf("Spurious hit: %d\n",v);
   spurious++;
   }
 else{
    if(ip[i]=='0')
      printf("Unsuccessful hit: 0%d\n",v);
	else
	  printf("Unsuccessful hit: %d\n",v);
    unsuccessful++;
   }
}

printf("Total Successful hits : %d\nTotal Spurious hits :%d\nTotal Unsuccessful hits:%d",exact,spurious,unsuccessful);
}