

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"methods.h" 
int main()
{
   FILE *fp;
   int n,i,*A;
   srand(time(NULL));
   
   printf("Enter the no. of test-cases  to be generated: ");
   scanf("%d",&n);
   
   fp =fopen("inputs.txt","w+");
   for(i=0;i<n;i++)
     fprintf(fp,"%d\t",rand()%20+1);
   fclose(fp);
   
   fp = fopen("inputs.txt","r");
   A = (int *) malloc(n*sizeof(int));
   for(i=0;i<n;i++)
     fscanf(fp,"%d",&A[i]);
	 
  printf("Length of the largest strictly increasing monotone is %d\n", sequence(A,n) );
  return 0;
}