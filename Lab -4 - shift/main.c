#include<stdio.h>
#include<string.h>
#include"methods.h"
#include<stdlib.h>
void main(){
FILE *fp;
char ip[100],pattern[50];
fp = fopen("inputs.txt","r");
fscanf(fp,"%s",ip);
fscanf(fp,"%s",pattern);
//gets(ip);
printf("\nInput string:%s",ip);
//gets(pattern);
printf("\npattern string:%s",pattern);
findShifts(ip,pattern);
fclose(fp);
}