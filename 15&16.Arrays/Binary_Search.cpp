#include<iostream>
using namespace std;
void binary_search(int *arr , int n , int key){
    int start = 0 ;
    int end = n-1;
    while(start<=end){
        int mid = (start+end)/2;
        if(arr[mid]==key){
            cout << "Position : "<< mid+1 << endl ;
            return;
        }
        else if(arr[mid]>key){
            end=mid-1;
        }else{
            start=mid+1;
        }
    }
    cout << "Element not found.";
}
int main (){
    int n ; 
    cout << "Enter Number of Elements : ";
    cin >> n ;
    int *arr = new int[n];
    cout << "Enter Values for Sorted Array -\n";
    for(int i =0 ; i < n ; i++){
        cout << "Element " << i+1 << " : ";
        cin >> arr[i];
    }
    int key ; 
    cout << "Enter Element which you want to search : ";
    cin >> key ;
    binary_search(arr,n,key);
}
