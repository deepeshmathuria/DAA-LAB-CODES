#include<stdio.h>
#include"generator.h"
#include<stdlib.h>
#include<time.h>
#include<string.h>

char cards[] = {'2','3','4','5','6','7','8','9','T','J','Q','K','A'};
char suite[] = {'S','C','D','H'};

void testGenerator(){
int i,n,j;
char line[31]="",str[4];
FILE *fp;
fp = fopen("inputs.txt","w+");
srand(time(NULL));

printf("Enter the number of test-cases to be generated : ");
scanf("%d",&n);

for(i=0;i<n;i++)
  { 
  for(j=0;j<10;j++)
  { 
    str[0]=cards[rand()%13];
	str[1]= suite[rand()%4];
	if(j!=9)
	 str[2]= ' ';	 
    strcat(line,str);
   }
   fprintf(fp,"%s",line);
   printf("%s\n",line);
   line[0]='\0';
}

fclose(fp);
}