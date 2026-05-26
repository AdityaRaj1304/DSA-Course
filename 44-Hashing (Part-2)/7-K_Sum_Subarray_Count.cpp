#include<bits/stdc++.h>
using namespace std;

int subArrayCountwithK(vector<int>arr, int k){//Prefix Sum
    unordered_map<int,int>m; //sum,count
    m[0]=1;
    int sum = 0,ans=0;
    for(int j = 0;j<arr.size();j++){
        sum+=arr[j];
        if(m.count(sum-k)){
            ans+=m[sum-k];
        }
        if(m.count(sum)){
            m[sum]++;
        }else{
            m[sum]=1;
        }
    }
    return ans;
}

int main(){
    vector<int>arr={10,2,-2,-20,10};
    int k =-10;
    cout << "Count of Subarray with Sum K: " << subArrayCountwithK(arr,k);
    return 0;
}