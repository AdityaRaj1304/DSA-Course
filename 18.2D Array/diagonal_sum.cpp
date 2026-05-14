#include<iostream>
using namespace std;
void brute_force(int arr[][4],int n){
    int sum = 0 ;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ;j++){
            if(i==j){
                sum+=arr[i][j];
            }else if (j==n-i-1){
                sum+=arr[i][j];
            }
        }
    }
    cout << "Diagonal Sum : "<< sum << endl;
}
void optimised(int arr[][4],int n){
    int sum = 0;
    for(int i = 0 ; i <n ;i++){
        sum+=arr[i][i];
        if(i!=n-i-1){
            sum+=arr[i][n-i-1];
        }
    }
    cout << "Diagonal Sum : "<< sum ;
}
int main (){
    int arr[4][4]={{10,20,30,40},{15,25,35,45},{27,29,37,48},{32,33,39,50}};
    brute_force(arr,4);
    optimised(arr,4);
}