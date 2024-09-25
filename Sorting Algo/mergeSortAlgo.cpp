#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>& vec , int low , int mid , int high){
    vector<int> ans;
    int i = low , j = mid+1;
    while(i <= mid  && j <= high){
        if(vec[i] <= vec[j]){
            ans.push_back(vec[i]);
            i++;
        }
        else if(vec[i]>vec[j]){
            ans.push_back(vec[j]);
            j++;
        }
    }
    while(i <= mid){
        ans.push_back(vec[i]);
        i++;
    }

    while(j <= high){
        ans.push_back(vec[j]);
        j++;
    }

    for(int i = low ; i<= high ; i++){
        vec[i] = ans[i-low];
    }
}

void ms(vector<int> &vec , int low , int high){
    if(low == high){
        return;
    }
    int mid = (low + high)/2;
    ms(vec , low , mid);
    ms(vec , mid+1 , high);
    merge(vec , low , mid , high);
}

int main(){
   vector<int> vec;
   int sizeOfVector , i=0 , value;
   cout<<" enter the size of Vector => ";
   cin>>sizeOfVector;
   cout<<"Enter Data => ";
   for(i= 0 ; i<sizeOfVector ; i++){
    cin>>value;
    vec.push_back(value);
   }
   ms(vec , 0 , sizeOfVector-1);
   cout<<" Vector is  => ";
   for(i= 0 ; i<sizeOfVector ; i++){
    cout<<vec[i]<< " ";
   }
   return 0;
}