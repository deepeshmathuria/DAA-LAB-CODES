#include<stdio.h>
#include"LCS.h"
#include<string.h>
void main(){
int i;
FILE *fp;
char str1[50], str2[50];
fp =fopen("inputs.txt","r");

while(!feof(fp)){
 fscanf(fp,"%s",str1); 
 fscanf(fp,"%s",str2);
 printf("Input Strings : %s and %s\n",str1,str2);
 for(i=0;i<strlen(str1);i++)
   findLCS(i,str1,str2);
for(i=0;i<strlen(str1);i++)
   findLCS(i,str2,str1);
   displayLCS();
}
 fclose(fp);
}