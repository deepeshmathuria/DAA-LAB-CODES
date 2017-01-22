#include"util.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void copy(char *A, char *B,int start,int end){
int i,j;
 for(j=0,i=start;i<end; ++i,++j)
    {
        A[j]=B[i];
    }
    A[j]='\0';
}

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
char *A;
A = (char *) malloc(lenp*sizeof(char));
int spurious = 0, exact=0, unsuccessful=0;
for(i=0;i<=(lent-lenp);i++){
 v = convertToNumber(i,i+strlen(pattern),ip);
 copy(A,ip,i,i+strlen(pattern));
 if((v/11)==q && (v%11)==r){
     printf("Exact hit: %s at %d\n",A,i); 
     exact++;
   }
 else if((v/11)!=q && (v%11)==r){
    printf("Spurious hit: %s\n",A);
    spurious++;
   }
 else{
	printf("Unsuccessful hit: %s\n",A);
    unsuccessful++;
   }
}

printf("Total Successful hits : %d\nTotal Spurious hits :%d\nTotal Unsuccessful hits:%d",exact,spurious,unsuccessful);
}

void findShifts(char *ip, char *pattern){
int i,j=0,k,flag=1;
const char *in,*pat;
 in = ip;
 pat = pattern;
   if(strlen(pattern)>strlen(ip)){
     printf("\nPattern cannot be of higher size than input string!");
     return;
   }
   else if(strlen(pattern)==strlen(ip)){
     if(strcmp(in,pat)){
       printf("\nThe pattern does not correspond to any shift in the input");
	   return;
     }
     else
       printf("shift is : %d",0);  
   }
   else{
     for(i=0;i<strlen(ip);i++){
	    flag=1;
	    k=i;
		//printf("\nip[%d]: %c pat[%d] %c",i,ip[i],j,pattern[j]);
        if(ip[i]==pattern[j]){
              flag=0;
          for(j=j+1,i=i+1;j<strlen(pattern)&&i<strlen(ip);j++,i++){
		  //printf("\n22. ip[%d]: %c pat[%d] %c",i,ip[i],j,pattern[j]);
	        if(ip[i]!=pattern[j]){
		      flag=1;
			  //i= i-1;
			  i = k;
			  break;
		    }
		   }
		   if(!flag&& i!=strlen(ip)){
		     //i= i-1;
			 i=k;
		     printf("\nValid Shift : %d",k);
			// printf("\n i : %d",i);
			 }
		   else{
		     printf("\n Invalid Shift : %d",k);
		   }
		   j=0; 
        }
		else
		  printf("\n Invalid Shift : %d",k);
	  }
    }
 
}

int * computePrefix(char *pattern){
int m = strlen(pattern),k=0,i=1;
int *A;
A = (int *) malloc((m)*sizeof(int));
A[0] = 0;
while(i<m){
 if(pattern[k]==pattern[i]){
     k = k+1;
	 A[i]=k;
	 i++;
	 }
  else{
    if(k!=0)  //for ending point AAACAAAA
	 k = A[k-1];
    else{
	 A[i] = 0;
	 i++;
	 }
  }
}
return A;
}

void KMP(char *ip, char *pattern){
printf("\nHello");
int lenp = strlen(pattern), lent = strlen(ip),j,i,k = -1;
int *A = computePrefix(pattern);
printf("\nprefix array computed:");
for(i=0;i<lenp;i++)
  printf("%d ",A[i]);
 i=0,j=0;
for(i=0;i<lent;i++){
  while(k > -1 && pattern[k+1] != ip[i]){
	     k = A[k];
		 i++;
		 }
		if (ip[i] == pattern[k+1])
			k++;
		if (k == lenp - 1) {
			printf("\npattern occured at index %d",i-k);
		}
	}
	
} 
