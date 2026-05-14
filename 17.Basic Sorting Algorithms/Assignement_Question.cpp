#include<iostream>
using namespace std;
void display(int *arr , int size){
    if(size == 0) {
        cout << endl;
        return;
    }

    cout << arr[0]; // safe only when size > 0
    for(int i = 1 ; i < size ; i++){
        cout << "," << arr[i];
    }
    cout << endl;
}
void bubble_sort_des(int *arr , int n){
    for(int i = 0 ; i < n-1; i++){
        for(int j = 0 ; j < n-i-1 ; j++){
            if(arr[j]<arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
    display(arr,n);
}
void selection_sort_des(int *arr,int n){
    for(int i = 0 ; i < n ; i++){
        int maxidx = i;
        for(int j = i+1 ; j < n ; j++){
            if(arr[j]>arr[maxidx]){
                maxidx=j;
            }
            swap(arr[maxidx],arr[i]);
        }
    }
    display(arr,n);
}
void insertion_sort_desc(int *arr , int n){
    for(int i = 1 ; i < n ; i++){
        int curr = arr[i];
        int prev = i-1;
        while(prev>=0 && arr[prev]<curr){
            swap(arr[prev],arr[prev+1]);
            prev--;
        }
        arr[prev+1]=curr;
    }
    display(arr,n);
}
void count_sort(int *arr , int n){
    int frequency[100000];
    int min_val=INT_MAX;
    int max_val=INT_MIN;
    for(int i = 0 ; i < n;i++){
        frequency[arr[i]]++;
        min_val=min(arr[i],min_val);
        max_val=max(max_val,arr[i]);
    }
    for(int i = max_val,j=0;i>=min_val;i--){
        while(frequency[i]>0){
            arr[j++]=i;
            frequency[i]--;
        }
    }
    display(arr,n);
}
int main (){
    int arr[10] = {3,6,2,1,8,7,4,5,3,1};
    int n = sizeof(arr)/sizeof(int);
    bubble_sort_des(arr,n);
    selection_sort_des(arr,n);
    insertion_sort_desc(arr,n);
    count_sort(arr,n);
}