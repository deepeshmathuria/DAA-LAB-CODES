/*
Name - Deepesh Mathuria
ID - 2014UCP1263
Batch - CP3
Assignment #1
*/

#include<stdio.h>
#include<time.h>
#include"sort.h"
#include"generator.h"
#include"pokerRank.h"

int tomVal[5], jerryVal[5],samet[2][2],samej[2][2];

int cardSuite(char t[5][3]){
 int i,match=1;
 char initial = t[0][1];
 
for(i=1;i<5;i++) {
  if(t[i][1]!=initial){ 
      match = 0;
      break;
    }
 }
 return match;
}

int pairs(int A[],int same[2][2]){  
  int prev=0,i,k=1,j=-1;
   same[0][0]=same[0][1]=same[1][0]=same[0][1] = 0;  //keep all values to zero initially  
   // Straight flush - all cards of same suite and consecutive.
     for(i=0;i<4;i++){
    	if(A[i+1]-A[i]!=1)
          k=0; 
	    if(A[i+1]==A[i]){   //highest number of matching pairs will be found using this code.
	     if(prev)
		  same[j][0]++;		  
		 else{
		  same[++j][0]++;
		  same[j][1]=A[i];
		  }
		 prev = 1;
	    }
       	else
          prev=0;		
     }
	 if(k) 
	   return 9;
	 else{
	    if(same[0][0]==3||same[1][0]==3)
		 return 8;
		else if((same[0][0]==1 && same[1][0]==2) || (same[0][0]==2 && same[1][0]==1) )
		 return 7;
		else if(same[0][0]==2||same[1][0]==2)
		 return 4;
		else if(same[0][0]==1 && same[1][0]==1)
		 return 3;
		else if(same[0][0]==1 || same[1][0]==1)
		 return 2;
		else if(same[0][0]==0)
		 return 1;
	    }
}

int analyse(char t[5][3],int flag)
{ 
  int i,k=1,prev=0,j=-1,r;
  int match = cardSuite(t);
  extractValues(t,flag,tomVal,jerryVal);
  
  if(flag==0){
    quickSort(tomVal,0,4);
	r = pairs(tomVal,samet);
	}
  else{
    quickSort(jerryVal,0,4);
	r = pairs(jerryVal,samej);
    }
	
	//rank return statements
	if(r==9 && match)
	  return 9;
	else if(r==9)
	  return 5;
	else if(r==8)
	  return 8;
	else if(r==7)
      return 7;	  
	else if(match)
	  return 6;
	else if(r==4)
	  return 4;
	else if(r==3)
	  return 3;
	else if(r==2)
	  return 2;
    else 
      return 1;	
}

void poker(char t[5][3], char j[5][3]){ 
  int rankTom = analyse(t,0);
  int rankJerry = analyse(j,1);
  
  if(rankTom==rankJerry)           
    tieResolve(rankTom,tomVal,jerryVal,samet,samej); //to resolve ranking conflicts in case of a tie.
  else if(rankTom>rankJerry) 
     printf("Tom Wins!\n");
  else
    printf("Jerry Wins!\n");

}

void main(){ 
 clock_t start,end; 
 char tom[5][3],jerry[5][3];
 int i;
 testGenerator();
 FILE *fp;
 fp = fopen("inputs.txt","r");
 start = clock();
 while(1){
 for(i=0;i<5;i++)
  fscanf(fp,"%s",&tom[i]);
 for(i=0;i<5;i++)
  fscanf(fp,"%s",&jerry[i]);
  
 if(feof(fp))
   break; 

 poker(tom,jerry);
} 
end = clock();
printf("\n Total execution time is %f seconds", (double) ((end-start)/CLOCKS_PER_SEC));
fclose(fp);

}

