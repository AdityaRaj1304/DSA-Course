#include<iostream>
#include<vector>
using namespace std;
int last_occ(vector<int>&arr,int target,int i){
    if(i==arr.size()){
        return -1;
    }
    int idx = last_occ(arr,target,i+1);
    if(idx==-1 && arr[i]==target){
        return i;
    }
    return idx;
}
int main(){
    vector<int>arr= {1,2,3,3,3,4};
    cout <<last_occ(arr,3,0);
    return 0 ;
}