#include<iostream>
#include<vector>
using namespace std ;
void printSubarray(vector <int> &arr , int n){
for(int start = 0 ; start < n ; start++){
    for(int end = start ; end < n ; end++){
        //Displaying Index of the elements
        //cout << "(" << start << "," << end << ") ";
        //Displaying Subarrays
        for(int i = start ; i<=end ; i++){
            cout << arr[i];
        }
        cout << ",";
    }
    cout << endl ;
}
}
int main (){
    int n ;
    cout << "Enter Number of Elements : ";
    cin >> n ; 
    vector<int>arr(n);
    for(int i = 0 ; i<n ; i++){
        cout << "Element " << i+1 << " : ";
        cin >> arr[i];
    }
    printSubarray(arr,n);
}