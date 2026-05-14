#include<iostream>
#include<vector>
using namespace std;
void merge_asc(int *arr, int st ,int end, int mid){
    vector<int>temp;
    int i = st;
    int j = mid+1;
    while(i<=mid && j<=end){
        if(arr[i]<=arr[j]){
            temp.push_back(arr[i++]);
        }else{
            temp.push_back(arr[j++]);
        }
    }
    while(i<=mid){
        temp.push_back(arr[i++]);
    }while(j<=end){
        temp.push_back(arr[j++]);
    }
    for(int idx = st,x=0 ; idx<=end;idx++){
        arr[idx]=temp[x++];
    }
}
void mergeSort_asc(int *arr , int st , int end){
    if(st>=end){
        return;
    }
    int mid = st + (end-st)/2;
    mergeSort_asc(arr,st,mid);
    mergeSort_asc(arr,mid+1,end);
    merge_asc(arr,st,end,mid);
}
void merge_dsc(int *arr, int st ,int end, int mid){
    vector<int>temp;
    int i = st;
    int j = mid+1;
    while(i<=mid && j<=end){
        if(arr[i]>=arr[j]){
            temp.push_back(arr[i++]);
        }else{
            temp.push_back(arr[j++]);
        }
    }
    while(i<=mid){
        temp.push_back(arr[i++]);
    }while(j<=end){
        temp.push_back(arr[j++]);
    }
    for(int idx = st,x=0 ; idx<=end;idx++){
        arr[idx]=temp[x++];
    }
}
void mergeSort_dsc(int *arr , int st , int end){
    if(st>=end){
        return;
    }
    int mid = st + (end-st)/2;
    mergeSort_dsc(arr,st,mid);
    mergeSort_dsc(arr,mid+1,end);
    merge_dsc(arr,st,end,mid);
}
void printArr(int *arr ,int n){
    for(int i = 0 ; i<n;i++){
        cout << arr[i] << " "; 
    }
}
int main(){
    int arr[5]={8,2,-3,24,12};
    int n=sizeof(arr)/sizeof(arr[0]);
    mergeSort_dsc(arr,0,n-1);
    printArr(arr,n);
    cout << endl;
    mergeSort_asc(arr,0,n-1);
    printArr(arr,n);
    return 0;
}
