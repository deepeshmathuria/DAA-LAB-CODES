#include<stdio.h>
#include<stdlib.h>
#include"methods.h"

int sequence(int *A,int n){
//   int arr[n][10];
   int k=0,index=0,p;
   int *lengths, i, j, max = 0;
   for(i=0;i<n;i++)
     printf("%d  ",A[i]);
   printf("\n");

   lengths = (int*) malloc ( sizeof(int) * n );
   for(i=0;i<n;i++){
      lengths[i] = 1;
    }
   for(i=1;i<n;i++){
      for(j=0;j<i;j++ ){
         if (A[i] >A[j] && lengths[i] < lengths[j] + 1){                                   
               lengths[i] = lengths[j] + 1;
      //         for(p=0;p<lengths[j];p++)
        //         arr[j][p+lengths[j]-1] = A[i]; 
             }
           }
       }
   for(i=0;i<n;i++)
      if(max<lengths[i]){
         max = lengths[i];
    //     index = i;
      }
  // for(i=0)
   free(lengths);
   return max;
}