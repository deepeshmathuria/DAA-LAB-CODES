#include"CalciNumberOps.h"
#include"CalciBaseOps.h"
#include<string.h>
#include<stdlib.h> 
#include<math.h>
#include<stdio.h>
typedef struct Nums nums;
typedef struct number Number;

Number createCalciNumber(char *number_format) {
 /*takes the number format as a string containing the base of the number, followed by a space, followed by the number using the custom 
 characters(Most Significant Digit first). This function then creates a Number using the values corresponding to the digits and returns it. */
   int i=0;
   Number n;
   char ch=number_format[i];
   n.base = 0;
   while(ch=number_format[i]){
     if(ch==' ')
	   break;
     n.base = 10*n.base+(ch-48);
     i++;
   }
   n.head = NULL;
   n.length = 0;
   nums *temp,*begin;
   if(n.base<=9)
     i=2;
   else
     i=3;
   for(;i<strlen(number_format);i++){ 
	   temp = (nums *) malloc(sizeof(nums));
	   temp->next = NULL;
	   temp->digit = CalciLookup(number_format[i]);
	   if(temp->digit>n.base-1){
	    printf("Illegal input digit %d for base %d\n",temp->digit,n.base);
        printf("OPERATION ABORTED!");
        exit(0);  		
	  }
	  if(n.head ==NULL){
	    n.head = temp;
		n.length++;
		}
	  else{
	    temp->next = n.head;
		n.head = temp; 
		n.length++;
	    }
	 }
	 temp = n.head;
	 while(temp!=NULL)
	 { 
	   printf("\nno=%d ",temp->digit);
	   temp=temp->next;
	  }
	 return n;
 }

 Number calciConvert(Number no,int to_base){
 int n=0,i=0,r,j,A[10],len=0;	
   nums *temp,*temp1;
   Number a;
   temp=no.head;	
   a.head=NULL;
     while(temp!=NULL){
      n=n+(temp->digit)*pow(no.base,i);
      temp=temp->next;
      i++;
     }
	 
	 
   i=0;
   while(n>0){
   	  r=n%to_base;
   	  n=n/to_base;
      A[i++]=r;
   }
   
   for(j=i-1;j>=0;j--){
          temp1=(nums *)malloc(sizeof(nums)); 
          temp1->digit=A[j];
          if(a.head==NULL){
             temp1->next=NULL;
             a.head=temp1;      
          }
   	  else{
             temp1->next=a.head;
             a.head=temp1;
          }
          len++;
   }
  a.base=to_base;
  a.length=len;
  return a;
}

 Number sum(Number a, Number b){
 //algorithm for summation
   Number res;
   nums *temp1,*temp2,*temp3;   //c-> carry temp 1 and temp 2 operand pointers and temp3 -> result
   res.head=NULL;
   int c=0,i=0,len=0;    
   temp1=a.head; 
   temp2=b.head;
   while(i<a.length || i<b.length){
   	  if(temp1==NULL && temp2!=NULL){
             temp3=(nums *)malloc(sizeof(nums));
             temp3->digit=(temp2->digit+c)%a.base;
             c=(temp2->digit+c)/a.base;
             temp3->next=res.head;
             res.head=temp3;
             temp2=temp2->next;
   	  }
   	  else if(temp1!=NULL && temp2==NULL){
             temp3=(nums *)malloc(sizeof(nums));
             temp3->digit=(temp1->digit+c)%a.base;
             c=(temp1->digit+c)/a.base;
             temp3->next=res.head;
             res.head=temp3;
             temp1=temp1->next;  
   	  }	
   	  else{    
   	      temp3=(nums *)malloc(sizeof(nums));
           if(res.head==NULL){
         	temp3->digit=(temp1->digit+temp2->digit+c)%a.base;
         	c=(temp1->digit+temp2->digit+c)/a.base;
         	temp3->next=NULL;
         	res.head=temp3;
              }
            else
              {
                temp3->digit=(temp1->digit+temp2->digit+c)%a.base;
         	c=(temp1->digit+temp2->digit+c)/a.base;
         	temp3->next=res.head;
         	res.head=temp3;	
              }
              temp1=temp1->next;
              temp2=temp2->next;
   	  }
   	  i++;
	  len++;
   }
   if(c!=0){
     temp3=(nums *)malloc(sizeof(nums));
     temp3->digit=c;
     temp3->next=res.head;
     res.head=temp3;
     len++;
   }
   res.length=len;
   res.base=a.base; 
   return res;
 
 }
 
Number invert(Number a){
  Number n;
  nums *temp1,*temp2;
  temp1=a.head;
  n.head=NULL;
  n.length=a.length;
  n.base=a.base;
  
  while(temp1!=NULL){
    temp2=(nums *)malloc(sizeof(nums));
    temp2->digit=temp1->digit;
    if(n.head==NULL)
      temp2->next=NULL;
    else
       temp2->next=n.head;
    n.head=temp2;
    temp1=temp1->next;
  }
  
  return n;
}


Number complement(Number a,int size){
  int n= pow(a.base,size);       //r^n where n = no. of digits  
  int i,c=0,len=0,base=a.base;  
  nums *temp,*temp1;
  Number b;
  b.head=NULL;
  b.base=10;
  a=calciConvert(a,10);
  temp=a.head;
  
  while(n>0){
       temp1=(nums *)malloc(sizeof(nums));
       if(temp==NULL){
          temp1->digit=n%10-c;
          c=0;
       }
       else{
          if((n%10)-c>=temp->digit){
             temp1->digit=(n%10)-c-temp->digit;
             c=0;
          }
          if((n%10)-c<temp->digit){  
             temp1->digit=(n%10)-c+10-temp->digit;
             c=1;
          }
          temp=temp->next;
        }   
        if(b.head==NULL)
            temp1->next=NULL;
        else
            temp1->next=b.head;
        b.head=temp1;
        n=n/10;
        len++;
  }
  b.length=len;
  b=invert(b);
  b=calciConvert(b,base);
  return b;
}
 
Number minus(Number a,Number b) {
   Number res;
   nums *temp1,*temp2,*temp3;
   res.head=NULL;
   int c=0,flag=0,size;
   
   if(a.length>b.length)
      size=a.length;
   else
     size=b.length;
	 
   res=sum(a,complement(b,size));
   
   if(res.length>size)
      res.head=res.head->next; 
   else
   {
     temp1=a.head; 
	 temp2=b.head;/*
     while(temp1!=NULL && temp2!=NULL && a.length==b.length)
     {
        if(temp1->digit>temp2->digit)
           flag=1;
        temp1=temp1->next;
		temp2=temp2->next; 
     }*/
     if(flag==1)
       res=complement(invert(res),res.length);
   }
   return res;
} 

void printNumber(Number n)
{
  FILE *fp;
  fp=fopen("Outputs.txt","a+");
  nums *temp;
  temp=n.head;
  int a[10],i=0,j;
  while(temp!=NULL)
  {
  	 a[i++]=temp->digit;
  	 temp=temp->next;
	 printf("%d\t",a[i-1]);
  }
  for(j=0;j<i;j++)
  {  
     printf("%c",valueLookup(a[j]));
  	 fprintf(fp,"%c",valueLookup(a[j]));
  }
  fprintf(fp,"(%d)\n",n.base);
  fclose(fp);
}