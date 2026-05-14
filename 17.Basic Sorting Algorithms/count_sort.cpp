#include<iostream>
using namespace std ;

void display(int *arr, int size){
    for(int i = 0 ; i < size ; i++){
        cout << arr[i];
        if(i < size - 1) cout << ", ";
    }
    cout << endl;
}
void count_sort(int*arr , int size){
    int freq[100000];
    int min_val = INT_MAX;
    int max_val = INT_MIN;
    //1st Step [T.C. =O(n)]
    for(int i = 0 ; i < size ; i++){
        freq[arr[i]]++;
        min_val=min(min_val,arr[i]);
        max_val=max(max_val,arr[i]);
    }
    //2nd Step [T.C. = O(range) = max-min]
    for(int i = min_val , j = 0 ; i<=max_val ; i++){
        while(freq[i]>0){
            arr[j++]=i;
            freq[i]--;
        }
    }
    display(arr,size);
}
int main(){
    int arr[8] = {4,6,1,2,6,7,4,5};
    int n = sizeof(arr)/sizeof(int);
    count_sort(arr,n);
}