#include<stdio.h>
#include"util.h"
void main(){
FILE *fp;
char ip[100], pattern[50]; 
fp = fopen("inputs.txt","r");
while(!feof(fp)){
fscanf(fp,"%s",ip);
fscanf(fp,"%s",pattern);
printf("Text: %s Pattern : %s\n",ip,pattern);
Carp(ip,pattern);
findShifts(ip,pattern);
KMP(ip,pattern);
 }
fclose(fp);
}