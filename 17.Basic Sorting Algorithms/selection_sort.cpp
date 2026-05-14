#include<iostream>
using namespace std ;

void display(int *arr, int size){
    for(int i = 0 ; i < size ; i++){
        cout << arr[i];
        if(i < size - 1) cout << ", ";
    }
    cout << endl;
}

void selection_sort_des(int *arr , int n){
    for(int i = 0 ; i < n-1 ; i++){
        int minindex = i;
        for(int j = i+1 ; j<n ; j++){
            if(arr[j]>arr[minindex]){
                minindex=j;
            }
        }
        swap(arr[i],arr[minindex]);
    }
    display(arr,n);
}
void selection_sort_asc(int *arr , int n){
    for(int i = 0 ; i < n-1 ; i++){
        int minindex = i;
        for(int j = i+1 ; j<n ; j++){
            if(arr[j]<arr[minindex]){
                minindex=j;
            }
        }
        swap(arr[i],arr[minindex]);
    }
    display(arr,n);
}
int main(){
    int arr[5]={4,2,9,1,8};
    int size = sizeof(arr)/sizeof(int);
    selection_sort_des(arr,size);
    selection_sort_asc(arr,size);
    return 0 ;
}