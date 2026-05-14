#include<iostream>
using namespace std;

void display(int *arr, int size){
    for(int i = 0 ; i < size ; i++){
        cout << arr[i];
        if(i < size - 1) cout << ", ";
    }
    cout << endl;
}

void display(char *arr, int size){
    for(int i = 0 ; i < size ; i++){
        cout << arr[i];
        if(i < size - 1) cout << ", ";
    }
    cout << endl;
}

void insertion_sort_asc(int *arr , int n){
    for(int i =1 ; i < n ;i++){
        int curr = arr[i];
        int prev = i-1;
        while(prev >= 0 && arr[prev]>curr){
            swap(arr[prev],arr[prev+1]);
            prev--;
        }
        arr[prev+1]=curr;
    }
    display(arr,n);
}

void insertion_sort_des(int *arr , int n){
    for(int i =1 ; i < n ;i++){
        int curr = arr[i];
        int prev = i-1;
        while(prev >= 0 && arr[prev]<curr){
            swap(arr[prev],arr[prev+1]);
            prev--;
        }
        arr[prev+1]=curr;
    }
    display(arr,n);
}

void insertion_sort_des_char(char *arr , int n){
    for(int i =1 ; i < n ;i++){
        char curr = arr[i];
        char prev = i-1;
        while(prev >= 0 && arr[prev]<curr){
            swap(arr[prev],arr[prev+1]);
            prev--;
        }
        arr[prev+1]=curr;
    }
    display(arr,n);
}

int main(){
    int arr[5]={4,-2,9,1,8};
    int size = sizeof(arr)/sizeof(int);
    insertion_sort_asc(arr,size);
    insertion_sort_des(arr,size);
    char a[6]={'c','v','n','a','g','x'};
    int n = sizeof(a)/sizeof(char);
    insertion_sort_des_char(a,n);
    return 0 ;
}

