#include<iostream>
using namespace std;
bool brute_force(int mat[][4],int m , int n,int key){//T.C.=O(n^2)
    for(int i = 0 ; i < m;i++){
        for(int j = 0 ; j<n;j++){
            if(mat[i][j]==key){
                return true;
            }
        }
    }
    return false;
}
bool binary_search(int mat[][4],int m , int n,int key){//T.C.=O(m*log n)
    for(int i = 0 ; i < m ; i++){
        int start = 0 , end = n-1;
        while(start<=end){
            int mid = start +(end-start)/2;
            if(mat[i][mid]==key){
                return true;
            }else if (mat[i][mid]>key){
                end = mid-1;
            }else{
                start=mid+1;
            }
        }
    }
    return false;
}
bool staircase(int mat[][4],int m , int n,int key){//T.C.=O(n+m)
    int row = 0 , col= n-1;//Top-Right Cell
    while(row<m && col >=0){
        if(mat[row][col]==key){
            return true;
        }else if (mat[row][col]>key){
            col--;//left
        }else{
            row++;
        }
    }
    return false;
}
int main (){
    int arr[4][4]={{10,20,30,40},{15,25,35,45},{27,29,37,48},{32,33,39,50}};
    cout << binary_search(arr,4,4,11)<< endl;
    cout << brute_force(arr,4,4,27)<< endl;
    cout << staircase(arr,4,4,31);
    return 0 ;
}