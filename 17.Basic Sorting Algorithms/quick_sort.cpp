#include<iostream>
#include<vector>
using namespace std ;

int partition (int *arr , int start , int end ){
    int i = start - 1;
    int pivot = arr[end];
    for(int j = start ; j < end ; j++){
        if(arr[j]<=pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    i++;
    swap(arr[i],arr[end]);
    return i ;
}
 
void quick_sort(int *arr , int start , int end){
    if(start>=end){
        return ;
    }
    int pivotIdx = partition(arr , start , end);
    quick_sort(arr,start,pivotIdx-1); // left half
    quick_sort(arr,pivotIdx+1,end); // right half
}

void display(int *arr, int size){
    for(int i = 0 ; i < size ; i++){
        cout << arr[i];
        if(i < size - 1) cout << ", ";
    }
    cout << endl;
}

int main (){
    int arr[5]={4,2,9,1,8};
    int size = sizeof(arr)/sizeof(int);
    quick_sort(arr,0,size-1);
    display(arr,size);
}