#include<bits/stdc++.h>
using namespace std;

int largestSumwith0Sum(vector<int>arr){
    unordered_map<int,int>m; //sum,idx
    int sum = 0;
    int ans = 0;
    for(int j = 0;j<arr.size();j++){
        sum+=arr[j];
        if(m.count(sum)){
            int currLen = j-m[sum]; // j-idx
            ans = max(ans,currLen);
        }else{
            m[sum]=j;
        }
    }
    return ans;
}

int main(){
    vector<int>arr={15,-2,2,-8,1,7,10};
    cout << "Largest Subarray with 0 Sum: " <<largestSumwith0Sum(arr);
    return 0;
}