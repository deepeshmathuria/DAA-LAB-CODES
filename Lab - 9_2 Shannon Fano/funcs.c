#include<stdio.h>
#include<stdlib.h>
#include"funcs.h"
typedef struct pTable pTab;

void sort(pTab *table,int size) {
  int max,pos,i,j;
  pTab temp;
  for(i=0;i<size;i++){
    max = table[i].count;
	pos = i;
    for(j=i;j<size;j++){
      if(table[j].count>max){
	    pos = j;
		max = table[j].count;
		printf("\n%d A[i] =%d",max);
		}
    }
	temp = table[i];
	table[i] = table[pos];
	table[pos] = temp; 
 }
}

void shannonFano(pTab *table,int size, char *fname){
int i,j;
char ch;
FILE *fp1;
FILE *fp2;
sort(table,size);
	printf("\n\n\t\t\tSORTED SEQUENCE OF LETTERS\n");
  printf("\t Char\t Count\t Probability");
 for(i=0;i<size;i++){
   printf("\n\t %c\t %d\t %.2f",table[i].c,table[i].count,table[i].prob);
 }

for(i=0;i<size-1;i++){
    table[i].code[table[i].index] = '0';
	table[i].code[table[i].index+1] = '\0';
    for(j=i+1;j<size;j++){
	   table[j].code[table[j].index] = '1';
	   table[j].index++;
	}	
}
table[size-1].code[table[size-1].index+1] = '\0';
printf("\n\n\t\t\tENCODING\n");
for(i=0;i<size;i++)
printf("\n%c : is encoded to %s",table[i].c,table[i].code);

fp1 = fopen(fname,"r");
fp2 = fopen("encode.txt","w");
while(!feof(fp1)){
 ch = fgetc(fp1);
 for(i=0;i<size;i++)
  if(table[i].c ==ch){
    fprintf(fp2,"%s",table[i].code);
    break; 	
  }
}

fclose(fp1);
fclose(fp2);
}