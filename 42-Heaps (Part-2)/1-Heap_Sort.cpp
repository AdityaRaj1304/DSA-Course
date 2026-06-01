#include<bits/stdc++.h>
using namespace std;

void heapify(int i , vector<int>& arr , int n){
    if(i>=n){
        return;
    }
    int leftChild = 2*i+1;
    int rightChild = 2*i+2;
    int maxIdx = i;
    
    if(leftChild<n && arr[leftChild]>arr[maxIdx]){
        maxIdx=leftChild;
    }
    if(rightChild<n && arr[rightChild]>arr[maxIdx]){
        maxIdx = rightChild;
    }
    if(maxIdx!=i){
        swap(arr[maxIdx],arr[i]);
        heapify(maxIdx,arr,n-1);
    }
}

void heapSort(vector<int>&arr){
    int n = arr.size();

    //Step 1: Building Heap
    for(int i=n/2 - 1; i>=0; i--){
        heapify(i,arr,n);
    }

    for(int i = n-1;i>=0;i--){
        swap(arr[0],arr[i]);
        heapify(0,arr,i);
    }
}

int main(){
    vector<int>arr={1,4,2,5,3};
    heapSort(arr);

    for(int i = 0;i<arr.size();i++){ 
        cout << arr[i] << " ";
    }
    return 0;
}