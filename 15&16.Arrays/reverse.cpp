#include<iostream>
using namespace std ;
void reverse_array(int *arr, int n , int *copy_arr){
    for(int i = 0 ; i < n ; i++){
        copy_arr[i]=arr[n-i-1];
    }
}
void display (int *arr , int n){
    cout << "Array : ";
    for(int i = 0 ; i < n ; i++){
        cout << arr[i] << ",";
    }
    cout << endl;
}
int main (){
    int arr[5] , copy_arr[5];
    for(int i = 0 ; i<5; i++){
        cout << "Element " << i+1 << " : ";
        cin >> arr[i] ;
    }
    display(arr,5);
    //Method 1 : (Extra Array)
    reverse_array(arr,5,copy_arr);
    display(copy_arr,5);
    //Method 2 : (No Extra Array)
    int start = 0 ;
    int end = 4 ;
    while(start<end){
        int temp = arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
        start++;
        end--;
    }
    display(arr,5);
    //Swap Function
    int st = 0 , e = 4 ;
    while(st<e){
        swap(arr[st],arr[e]);
        st++;
        e--;
    }
    display(arr,5);
}