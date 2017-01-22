#include<stdio.h>
#include<string.h>
#include"CalciBaseOps.h"
#include"CalciNumberOps.h"

typedef struct Nums nums;
typedef struct number Number;

void printOp(char *op1,char *op2, Number r,FILE *fp,char* oper)
{ int i=0;
  nums *temp;
  fprintf(fp,"%c",'(');
  while(op1[i]!=' ')
   fprintf(fp,"%c",op1[i++]);
  fprintf(fp,"%c",')');
  i++;
  while(i<strlen(op1))
    fprintf(fp,"%c",op1[i++]);
  
  if(!strcmp(oper,"sum")) 
   fprintf(fp,"%c",'+');
  else
   fprintf(fp,"%c",'-');
   
  i=0; 
  fprintf(fp,"%c",'(');
  while(op2[i]!=' ')
   fprintf(fp,"%c",op2[i++]);
  fprintf(fp,"%c",')');
  i++;
  
  while(i<strlen(op2))
    fprintf(fp,"%c",op2[i++]);
  
  fprintf(fp,"%c",'=');
  temp = r.head;
  fprintf(fp,"(%d)",r.base);  
   while(temp!=NULL){
    printf("%c\n",valueLookup(temp->digit));
    fprintf(fp,"%c",valueLookup(temp->digit));
    temp= temp->next;    
  }
  fprintf(fp,"\n");
}

void main(){
  FILE *fp, *fp1, *fp2;    //fp -inputs fp1 - outputs fp2 - base initialization
  char op[6],b1[21],oper1[21],b2[21],oper2[21];
  Number a,b,r,ai,bi;
  nums *temp;
  fp2 = fopen("base.txt","r");
  fp1 = fopen("output.txt","a+");
  int maxD = initializeCalciBase(fp2);
  fp = fopen("inputs.txt","r");
  while(1){
    fscanf(fp,"%s",op);
	if(feof(fp))
	 break;
	printf("op - %s\n",op);
	fscanf(fp,"%s",b1);
	fscanf(fp,"%s",oper1);
	strcat(b1," ");
	strcat(b1,oper1);
	printf("op1 - %s\n",b1);
    fscanf(fp,"%s",b2);
	fscanf(fp,"%s",oper2);
	strcat(b2," ");
	strcat(b2,oper2);
	printf("op2 - %s\n",b2);
	
	a = createCalciNumber(b1);
	ai=a;
	temp = a.head;
	printf("\n");
	while(temp!=NULL)
	{
	 printf("%d ",temp->digit);
	 temp=temp->next;
	}
	printf("\t%d",a.base);
	b = createCalciNumber(b2);
	bi=b;
	temp = b.head;
	printf("\n");
	while(temp!=NULL)
	{
	 printf("%d ",temp->digit);
	 temp=temp->next;
	}
	printf("\t%d",b.base);
	//printNumber(a);
	//printNumber(b);
	if(a.base>b.base){
	
     b = calciConvert(b,a.base); 
	 temp = b.head;
	 printf("Converted\n");
	 while(temp!=NULL){
	 printf("%d ",temp->digit);
	 temp=temp->next;
	  }
	} 
    else if(a.base<b.base){
     a = calciConvert(a,b.base);
	 temp = a.head;
	printf("Converted:\n");
	while(temp!=NULL){
	 printf("%d ",temp->digit);
	 temp=temp->next;
	 }
	
	}
	if(!strcmp(op,"sum"))
	  r = sum(a,b);
	else
	  r = minus(a,b);
	temp = r.head;
	printf("Result:\n");
	while(temp!=NULL)
	{
	 printf("%d ",temp->digit);
	 temp=temp->next;
	}
    //printNumber(r);
	printOp(b1,b2,r,fp1,op);
	
  }
  fclose(fp);
  fclose(fp2);
}
