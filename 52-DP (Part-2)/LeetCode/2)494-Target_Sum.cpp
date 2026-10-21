#include <bits/stdc++.h>
using namespace std;
using ll = long long;


class Solution {
public:
    int mem(vector<int>&nums,int target,int idx ,int sum,vector<vector<int>>&dp,int total){
        if(idx==nums.size()){
          if(sum==target){
            return 1;
          }
          return 0;
        }
        if(dp[idx][sum+total]!=-1){
            return dp[idx][sum+total];
        }
        int add = mem(nums,target,idx+1,sum+nums[idx],dp,total);
        int subtract = mem(nums,target,idx+1,sum-nums[idx],dp,total);
        return dp[idx][sum+total]=add+subtract;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int total = accumulate(nums.begin(),nums.end(),0);
        vector<vector<int>>dp(n+1,vector<int>(2*total+1,-1));
        return mem(nums,target,0,0,dp,total);
    }
};


class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int total = accumulate(nums.begin(),nums.end(),0);
        vector<vector<int>>dp(n+1,vector<int>(2*total+1,0));
        if (abs(target) > total) {
            return 0;
        }
        dp[0][total]=1;
        for(int i =1;i<=n;i++){
            for(int j =-total;j<=total;j++){
                if(dp[i-1][j+total]==0){
                    continue;
                }
                dp[i][j+total+nums[i-1]]+=dp[i-1][j+total];
                dp[i][j+total-nums[i-1]]+=dp[i-1][j+total];
            }
        }
        return dp[n][target+total];
    }
};


