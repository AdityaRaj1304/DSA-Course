#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class Solution {
public:
    int ans = 0;
    void mem(vector<int>&nums,int target,int idx ,int sum,vector<vector<int>>&dp){
        if(idx==nums.size()){
          if(sum==target){
            ans++;
          }
          return;
        }
        if(dp[idx][sum]!=-1){
            return dp[idx][sum];
        }
        rec(nums,target,idx+1,sum+nums[idx]);
        rec(nums,target,idx+1,sum-nums[idx]);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int total = accumulate(nums.begin(),nums.end(),0);
        vector<vector<int>>dp(n+1,vector<int>(2*total+1,0));
        rec(nums,target,0,0);
        return ans;
    }
};