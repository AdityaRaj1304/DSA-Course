#include<bits/stdc++.h>
using namespace std;

void pairSum(vector<int>arr,int target){
    unordered_map<int,int>mp;
    for(int i =0 ;i<arr.size();i++){
        int comp = target-arr[i];
        if(mp.count(comp)){
            cout << "Ans: " << i <<"," << mp[comp];
            break;
        }
        mp[arr[i]]=i;
    }
}

int main(){
    vector<int>arr={1,2,7,11,15,5,9};
    int target = 9;
    pairSum(arr,target);
    return 0;
}