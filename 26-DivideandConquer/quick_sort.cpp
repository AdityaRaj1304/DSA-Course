#include<iostream>
#include<vector>
using namespace std;
int partition_asc(int *arr, int st , int end){
    int i = st-1 , pivot =arr[end];
    for(int j = st ; j < end ;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    i++;
    swap(arr[i],arr[end]);
    return i;
}
void quickSortasc(int*arr , int st , int end){
    if(st>=end){
        return;
    }
    int pivotIdx=partition_asc(arr,st,end);
    quickSortasc(arr,st,pivotIdx-1);//left side
    quickSortasc(arr,pivotIdx+1,end);//right side
}
int partition_dsc(int *arr, int st , int end){
    int i = st-1 , pivot =arr[end];
    for(int j = st ; j < end ;j++){
        if(arr[j]>pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    i++;
    swap(arr[i],arr[end]);
    return i;
}
void quickSortdsc(int*arr , int st , int end){
    if(st>=end){
        return;
    }
    int pivotIdx=partition_dsc(arr,st,end);
    quickSortdsc(arr,st,pivotIdx-1);//left side
    quickSortdsc(arr,pivotIdx+1,end);//right side
}
void printArr(int *arr ,int n){
    for(int i = 0 ; i<n;i++){
        cout << arr[i] << " "; 
    }
}
int main(){
    int arr[6]={6,3,7,5,2,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    quickSortdsc(arr,0,n-1);
    printArr(arr,n);
    quickSortasc(arr,0,n-1);
    cout << endl;
    printArr(arr,n);
    return 0;
}