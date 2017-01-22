#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 30

int k=0,flag=1;
char tempStr[SIZE];

struct StringList {
char *str;
struct StringList *next;
};

struct StringList *head = NULL;

void appendStr(char *str) {
  struct StringList *temp;
  temp = (struct StringList *) malloc(sizeof(struct StringList));
  temp->str = str;
  temp->next = NULL; 
  if(head==NULL){
     head = temp;
    }
  else{
    temp->next = head;  
    head = temp;
  }
}

int max(int a,int b){
if(a>b) 
  return a;
return b;
}

int findLCS(char *str1,char *str2){ 
int i;
    if (*str1 == '\0' || *str2 == '\0'){	
	  return 0;
	else if (*str1 == *str2) 
	  return 1 + findLCS(str1+1, str2+1);
	else
	  return max(findLCS(str1+1,str2), findLCS(str1,str2+1));
	 
}

void displayLCS(char *str1, char *str2){
   int len = findLCS(str1,str2); 
   struct StringList* temp = head;
   printf("The length of longest common subsequence is: %d",len);
   printf("The longest common subsequence(s) are:\n");
   while(temp!=NULL){
    if(strlen(temp->str)==len)
	printf("%s\n",temp->str);
    temp = temp->next;
   }
}
