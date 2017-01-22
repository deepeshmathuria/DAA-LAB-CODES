#include<stdio.h>
#include"matrix.h"

void main(){
  int row=5,col=5;
  int arr[5][5]={9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9};  
   printMatrix(arr,row,col);
   spiralize(arr,row,col);
   printMatrix(arr,row,col);
}