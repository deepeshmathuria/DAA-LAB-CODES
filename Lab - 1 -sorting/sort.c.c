#include"sort.h"
#include<stdio.h>

void inSort(int *A,int k){

  int i,j,temp;

  for(i=1;i<k;i++){
         j= i;
      while(A[j]<A[j-1] && j>0)
    {
           temp = A[i];
           A[i] = A[j];
           A[j] = temp;
           j=j-1;
    }

  }

}

void selSort(int *A,int k){

  int i,j,temp,min;

  for(i=0;i<k;i++)
  {
  	min = A[i];
  	for(j=i;j<k;j++)
  	{
  		if(A[j]<min)
  		{
  			min = A[i];
  		}

  	    //swap A[i] and min
  	     temp= A[i];
  	     A[i] = min;
  	     min = temp;
  	}

  }
}

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

void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}


int makePartition (int *A, int start, int end)
{
    int x = A[end];
    int i = (start - 1);
    int j;
    for (j = start; j <= end- 1; j++)
    {

        if (A[j] <= x)
        {
            i++;
            swap(&A[i], &A[j]);
        }
    }
    swap(&A[i + 1], &A[end]);
    return (i + 1);
}


void quickSort(int *A, int start, int end)
{
    if (start < end)
    {
        int pIndex = makePartition(A, start,end); /* Partitioning index */
        quickSort(A, start, pIndex - 1);
        quickSort(A, pIndex + 1, end);
    }
}

void main()
{
}
