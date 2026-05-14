#include<iostream>
#include<vector>
using namespace std;
int first_occ(vector<int>&arr, int target , int i){
    if(i==arr.size()){
        return -1;
    }
    if(arr[i]==target){
        return i;
    }
    return first_occ(arr,target,i+1);
}
int main (){
    vector<int>arr= {1,2,3,3,3,4};
    cout << first_occ(arr,3,0);
}