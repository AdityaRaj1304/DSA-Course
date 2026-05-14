#include<iostream>
using namespace std ;
void linear_search(int *arr , int n , int key){
    for(int i = 0 ; i < n ; i++){
        if(arr[i]==key){
            cout << key << " is element " << i+1 ;
            return;
        }
    }
    cout << "Not found \n";
}
int main (){
    int n , k ;
    cout << "Enter Number of Elements : ";
    cin >> n ;
    int *arr = new int [n];
    for(int i = 0 ; i < n ; i++){
        cout << "Enter element " << i+1 << " : ";
        cin >> arr[i];
    }
    cout << "Enter Key : ";
    cin >> k; 
    linear_search(arr,n,k);
    delete [] arr ;
}