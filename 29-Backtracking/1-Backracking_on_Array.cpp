#include<iostream>
#include<vector>
using namespace std;

void printarr(int *arr , int n){
    for(int i = 0 ; i < n ;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
void changeArr(int *arr , int n , int i){
    if(i==n){
        printarr(arr,n);
        return;
    }
    arr[i]=i+1;
    changeArr(arr,n,i+1);
    arr[i]-=2;
}
int main(){
    int arr[5]={0};
    changeArr(arr,5,0);
    printarr(arr,5);
    return 0 ;
}