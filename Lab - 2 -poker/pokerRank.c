#include<stdio.h>
#include"pokerRank.h"

void extractValues(char t[5][3],int flag, int tomVal[5], int jerryVal[5]){
  int i,k=0;
  for(i=0;i<5;i++)
  {
   switch(t[i][0])
     {
       case '2': if(flag==0)
                 {
                  tomVal[k]=2;
                  k++;
                 }
                else{
                   jerryVal[k]=2;
                   k++;
                  }
                 break; 
       case '3': if(flag==0)
                 {
                  tomVal[k]=3;
                  k++;
                 }
                else{
                  jerryVal[k]=3;
                   k++;
                  }
                 break;
      case '4': if(flag==0)
                 {
                  tomVal[k]=4;
                  k++;
                 }
                else{
                  jerryVal[k]=4;
                  k++;
                 }
                 break; 
     case '5': if(flag==0)
                 {
                  tomVal[k]=5;
                  k++;
                 }
               else{
                   jerryVal[k]=5;
                    k++;
                  }
                 break; 
     case '6': if(flag==0)
                 {
                  tomVal[k]=6;
                  k++;
                 }
                else{
                   jerryVal[k]=6;
                   k++;
                  }
                 break;     
     case '7': if(flag==0)
                 {
                  tomVal[k]=7;
                  k++;
                 }
                else{
                   jerryVal[k]=6;
                   k++;
                  }
                 break; 
     case '8': if(flag==0)
                 {
                  tomVal[k]=8;
                  k++;
                 }
                else{
                   jerryVal[k]=8;
                   k++;
                  }
                 break; 
     case '9': if(flag==0)
                 {
                  tomVal[k]=9;
                  k++;
                 }
                else{
                   jerryVal[k]=9;
                   k++;
                  }
                 break;
     case 'T': if(flag==0)
                 {
                  tomVal[k]=10;
                  k++;
                 }
                else{
                   jerryVal[k]=10;
                   k++;
                  }
                 break;  
     case 'J': if(flag==0)
                 {
                  tomVal[k]=11;
                  k++;
                 }
                else{
                   jerryVal[k]=11;
                   k++;
                  }
                 break; 
     case 'Q': if(flag==0)
                 {
                  tomVal[k]=12;
                  k++;
                 }
                else{
                   jerryVal[k]=12;
                   k++;
                  }
                 break; 
     case 'K': if(flag==0)
                 {
                  tomVal[k]=13;
                  k++;
                 }
                else{
                   jerryVal[k]=13;
                   k++;
                  }
                 break; 
     case 'A': if(flag==0)
                 {
                  tomVal[k]=14;
                  k++;
                 }
                else{
                   jerryVal[k]=14;
                   k++;
                  }
                 break; 
     }
  }
}

int highCard(int t[5],int j[5]){
int i;
for(i=4;i>=0;i--)
{
  if(t[i]==j[i])
    continue;
  else if(t[i]>j[i])
    return 1;
  else
    return -1;
}
if(i==-1)
 return 0;
}

void tieResolve(int rank,int tomVal[5], int jerryVal[5], int samet[2][2], int samej[2][2]){
int at,aj,i;
switch(rank){
	 case 9: if(tomVal[4]==jerryVal[4])
	           printf("TIE\n"); 
			 else if(tomVal[4]>jerryVal[4]) 
               printf("Tom Wins!\n");
             else
               printf("Jerry Wins!\n");
			 break;
	 case 8: for(i=0;i<2;i++)
	           if(samet[i][0]==4)
			     at=samet[i][1];
			   if(samej[i][0]==4)
			     aj=samej[i][1];
			 if(at==aj)
	           printf("TIE\n"); 
			 else if(at>aj) 
               printf("Tom Wins!\n");
             else
               printf("Jerry Wins!\n");
			 break;
      case 7: for(i=0;i<2;i++)                      //same 2, same 3;
	           if(samet[i][0]==3)
			     at=samet[i][1];
			   if(samej[i][0]==3)
			     aj=samej[i][1];
			 if(at==aj)
	           printf("TIE\n"); 
			 else if(at>aj) 
               printf("Tom Wins!\n");
             else
               printf("Jerry Wins!\n");
			 break;
	  case 6: at = highCard(tomVal,jerryVal);
			 if(at==0)
	           printf("TIE\n"); 
			 else if(at>0) 
               printf("Tom Wins!\n");
             else
               printf("Jerry Wins!\n");
			 break;
	  case 5: if(tomVal[4]==jerryVal[4])
	           printf("TIE\n"); 
			 else if(tomVal[4]>jerryVal[4]) 
               printf("Tom Wins!\n");
             else
               printf("Jerry Wins!\n");
			 break;
	  case 4: for(i=0;i<2;i++)
	           if(samet[i][0]==3)
			     at=samet[i][1];
			   if(samej[i][0]==3)
			     aj=samej[i][1];
			 if(at==aj)
	           printf("TIE\n"); 
			 else if(at>aj) 
               printf("Tom Wins!\n");
             else
               printf("Jerry Wins!\n");
			 break;
	  case 3: at = aj =0;
          	  for(i=0;i<2;i++)
	           if(samet[i][0]==2){
			     if(at<samet[i][1])
			       at=samet[i][1];}
			   if(samej[i][0]==2){
			     if(aj<samej[i][1])
			       aj=samej[i][1];}
			 if(at==aj)
	           printf("TIE\n"); 
			 else if(at>aj) 
               printf("Tom Wins!\n");
             else
               printf("Jerry Wins!\n");
			 break;
	  case 2: if(samet[0][1]==samej[0][1]){
	            for(i=4;i>=0;i--)
                {
				 if(tomVal[i]!=samet[0][1] && jerryVal[i]!=samej[0][1])
				  {
				   if(tomVal[4]==jerryVal[4])
	                 printf("TIE\n"); 
			       else if(tomVal[4]>jerryVal[4]) 
                     printf("Tom Wins!");
                   else
                     printf("Jerry Wins!");
			       break; 
				  }
				}				
	          }
			  else if(samet[0][1]>samej[0][1])
			   printf("Tom Wins!\n");
	          else
			   printf("Jerry Wins!\n");
			  break;
	  case 1 : at = highCard(tomVal,jerryVal);
	          if(at==0)
	           printf("TIE\n"); 
			  else if(at>0) 
               printf("Tom Wins!\n");
              else
               printf("Jerry Wins!\n");
			   break;
	}
}