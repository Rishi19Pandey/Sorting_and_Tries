//                                      MergeSort.cpp

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void merge(int A[] , int low , int mid , int high){
    int i = low , j = mid+1 , k = low;
    int B[high+1];
    while(i<= mid && j <= high){
        if(A[i] <= A[j]){
            B[k++] = A[i++];
        }
        else{
            B[k++] = A[j++];
        }
    }
    while(i <= mid){
        B[k++] = A[i++];
    }
    while(j <= high){
        B[k++] = A[j++];
    }

    for(i = low ; i < k ; i++){
        A[i] = B[i];
    }
}

void mergeSort(int A[] , int low , int high){
    if(low < high){
        int mid = (low + high) / 2;
        mergeSort(A,low,mid);
        mergeSort(A,mid+1,high);
        merge(A,low,mid,high);
    }
}

int main(){
   int A[] ={15,36,28,10,2,9,5,36,58,7,1};
   int size = sizeof(A)/sizeof(A[0]);
   mergeSort(A,0,size-1);
   for(int i = 0 ; i < size ; i++){
    cout<<A[i] <<" ";
   }
   return 0;
}