#include<iostream>
using namespace std;

void display(int *arr, int size){
    for(int i = 0 ; i < size ; i++){
        cout << arr[i];
        if(i < size - 1) cout << ", ";
    }
    cout << endl;
}
void bubble_sort_asc(int *arr, int size){
    cout << "Ascending Order\n";
    for(int i = 0 ; i < size - 1 ; i++){
        for(int j = 0 ; j < size - i - 1 ; j++){
            if(arr[j] > arr[j+1]){  
                swap(arr[j], arr[j+1]);
            }
        }
    }
    display(arr,size);
}

void bubble_sort_des(int *arr, int size){
    cout << "Descending Order\n";
    for(int i = 0 ; i < size - 1 ; i++){
        for(int j = 0 ; j < size - i - 1 ; j++){
            if(arr[j] < arr[j+1]){  
                swap(arr[j], arr[j+1]);
            }
        }
    }
    display(arr,size);
}

void bubble_sort_asc_optimised(int *arr, int size){
    cout << "Descending Order\n";
    for(int i = 0 ; i < size - 1 ; i++){
        bool isSwap = false ;
        for(int j = 0 ; j < size - i - 1 ; j++){
            if(arr[j] > arr[j+1]){  
                swap(arr[j], arr[j+1]);
                isSwap = true;
            }
        }
        if(!isSwap ){
            cout << "Array is already sorted.\n";
            return;
        }
    }
    display(arr,size);
}

int main (){
    int arr[5] = {4, 6, 12, 1, 2};
    int size = sizeof(arr)/sizeof(int);
    bubble_sort_asc(arr, size);
    bubble_sort_des(arr,size);
    int a[3]={1,2,3};
    int n = sizeof(a)/sizeof(int);
    bubble_sort_asc_optimised(a,n);
    return 0;
}
