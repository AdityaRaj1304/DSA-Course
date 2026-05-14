#include<iostream>
using namespace std ;
void print(int arr[] , int size){
    for(int i = 0 ; i<size ; i++){
        cout << arr[i] << " " ;
    }
    cout << endl ;
}
void reverse_array(int *arr , int n){
    int start = 0;
    int end = n-1;
    while(start<end){
        swap(arr[start++],arr[end--]);
    }
    print(arr,n);
}
int main (){
    int a[] = {1,2,3,4,5};
    int n = sizeof(a)/sizeof(int);
    print(a,n) ;
    int copyarr[5];
    for(int i = 0 ; i < n ; i++){
        int j = n - i - 1 ;
        copyarr[j] = a[i];
    }
    print(copyarr,n);
    reverse_array(a,n);
}