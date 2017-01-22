#include<stdio.h>
#include<stdlib.h>
#include"funcs.h"
typedef struct pTable pTab;

pTab table[256];
pTab Ftable[256];

void main(int argc,char *argv[]){

if(argc==1){
    printf("Too few arguments supplied.\nPROCESS ABORTED!!");
    exit(0);
  }
  
FILE *fp;
char c; int ch; int n=0; int k=0;
int i;
fp = fopen(argv[1],"r");
if(fp==NULL){
    printf("Illegal file name supplied.\nPROCESS ABORTED!!");
    exit(0);
}
while(!feof(fp))  {
  n++;
  ch = fgetc(fp);
  c = ch;
  if(ch>=0){
 if(table[ch].count==0){
     table[ch].c = c;
     table[ch].count++;	 
 }
 else
     table[ch].count++;
	 }
}
fclose(fp);

for(i=0;i<256;i++){
 if(table[i].count!=0){
    Ftable[k].c = table[i].c;
    Ftable[k].count = table[i].count;
    Ftable[k].prob = (float) table[i].count/n;
    k++;	
  }
 }
 printf("\t Char\t Count\t Probability");
 for(i=0;i<k;i++){
   Ftable[i].index = 0;
   printf("\n\t %c\t %d\t %.2f",Ftable[i].c,Ftable[i].count,Ftable[i].prob);
 }
 shannonFano(Ftable,k,argv[1]);
}