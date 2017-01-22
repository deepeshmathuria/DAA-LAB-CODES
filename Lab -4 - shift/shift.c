#include<string.h>
#include<stdio.h>
#include"methods.h"

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
	    k=-1;
		//printf("\nip[%d]: %c pat[%d] %c",i,ip[i],j,pattern[j]);
        if(ip[i]==pattern[j]){
	      k=i;
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
		   if(!flag && i!=strlen(ip)){
		     i= i-1;
		     printf("\nShift : %d",k);
			// printf("\n i : %d",i);
			 }
		   j=0; 
        }
	  }
    }
 
}
