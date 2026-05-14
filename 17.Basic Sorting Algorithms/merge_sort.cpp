#include <iostream>
#include<vector>
using namespace std ;

void merge(int *arr , int start , int end , int mid){
    vector<int>temp;
    int i = start ;
    int j = mid + 1;
    while (i<=mid && j<=end){
        if(arr[i]<=arr[j]){ // for decreasing order just reverse the sign
            temp.push_back(arr[i++]);
        }else{
            temp.push_back(arr[j++]);
        }
    }
    while(i<=mid){
        temp.push_back(arr[i++]);
    }
    while(j<=end){
        temp.push_back(arr[j++]);
    }
    for(int idx = start , x =0 ; idx <= end ; idx++){
        arr[idx]=temp[x++];
    }
}

void merge_sort(int *arr , int start , int end){
    if(start>=end){
        return ;
    }else{
        int mid = start +(end-start)/2;
        merge_sort(arr,start,mid); //left half
        merge_sort(arr,mid+1,end); // right half
        merge(arr,start,end,mid);
    }
}

void display(int *arr, int size){
    for(int i = 0 ; i < size ; i++){
        cout << arr[i];
        if(i < size - 1) cout << ", ";
    }
    cout << endl;
}

int main (){
    int arr[5]={4,-2,9,1,8};
    int size = sizeof(arr)/sizeof(int);
    merge_sort(arr,0,size-1);
    display(arr,size);
    return 0 ;
}