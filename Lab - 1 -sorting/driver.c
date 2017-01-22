#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
#include"sort.h"

void merge(int *A,int start,int mid,int end)
{

    int i, j, k;
    int left = start - mid + 1;
    int right =  end - mid;

    int * Arr1 = (int *) malloc((sizeof(int)*left));
    int * Arr2 = (int *) malloc((sizeof(int)*right));

    for(i = 0; i < left; i++)
        Arr1[i] = A[left + i];
    for(j = 0; j <right; j++)
        Arr2[j] = A[mid + 1+ j];

    i = 0;
    j = 0;
    k = start;
    while (i < left && j < right)
    {
        if (Arr1[i] <= Arr2[j])
        {
            A[k] = Arr1[i];
            i++;
        }
        else
        {
            A[k] = Arr2[j];
            j++;
        }
        k++;
    }

    while (i < left)
    {
        A[k] = Arr1[i];
        i++;
        k++;
    }

    while (j < right)
    {
        A[k] = Arr2[j];
        j++;
        k++;
    }
}

void mergeSort(int *A,int start, int end)
{
    if(start<end)
    {
    	int mid = (start+end)/2;
    	mergeSort(A,start,mid);
    	mergeSort(A,mid+1,end);
    	merge(A,start,mid,end);
    }

}

void main()
{

long time_start,time_end;
 struct timeval tv;
 srand(time(NULL));

 int i,r;
 int *A;
 unsigned int n;
 char ch = 's';

 FILE *fp;
 FILE *times;
 times = fopen("runtime.txt","a+");
 fp = fopen("num.txt","w+");
 do{
 printf("Enter the number of inputs:\n");
 scanf("%u",&n);

 for(i=0;i<n;i++)
 {
   fprintf(fp,"%d\t",rand());
 }

 fclose(fp);

 A = (int *) malloc(sizeof(int)*n);

fp = fopen("num.txt","r");

while(!feof(fp))
 {
 	fscanf(fp,"%d",&A[i]);
 }

 gettimeofday(&tv,NULL);
 time_start = (tv.tv_sec*1e+6) + tv.tv_usec;
 mergeSort(A,0,n);
 gettimeofday(&tv,NULL);
 time_end = (tv.tv_sec*1e+6) + tv.tv_usec;

 fprintf(times,"Execution time: %.6ld for %u inputs\n",time_end-time_start,n);
mergeSort(A,0,n-1);

 printf("sorted numbers are:\n");
 for (i=0;i<n;i++)
 	printf("%d\n",A[i]);


 fclose(times);
 printf("Do you want to continue?\n");
 scanf("%c",&ch);

  }while(ch!='N'||ch!='n');

}
