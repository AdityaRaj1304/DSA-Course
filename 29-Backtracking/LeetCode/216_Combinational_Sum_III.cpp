#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>comb;
        solution(n,k,1,0,ans,comb);
        return ans;
    }
    void solution(int n , int k ,int num ,int sum , vector<vector<int>>&ans,vector<int>&comb){
        if(sum==n&&comb.size()==k){
            ans.push_back(comb);
            return;
        }
        if(sum>n||comb.size()>k){}
        for(int i = num ; i<=9;i++){
            sum+=i;
            comb.push_back(i);
            solution(n,k,i+1,sum,ans,comb);
            sum-=i;
            comb.pop_back();
        }
    }
};