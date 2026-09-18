#include <bits/stdc++.h>
using namespace std;
using ll = long long;


class Solution {
public:
    int solve(vector<int>&nums,int idx , vector<int>&dp){
        if(idx>=nums.size()){
            return 0;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        int rob = nums[idx]+solve(nums,idx+2,dp);
        int skip = solve(nums,idx+1,dp);
        return dp[idx]=max(rob,skip);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        return solve(nums,0,dp);
    }
};

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            return nums[0];
        }
        vector<int>dp(n,0);
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<n;i++){
            dp[i]=max(dp[i-1],nums[i]+dp[i-2]);
        }
        return dp[n-1];
    }
};

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            return nums[0];
        }else if(n==2){
            return max(nums[0],nums[1]);
        }
        int prev = nums[0];
        nums[1]=max(nums[0],nums[1]);
        for(int i =2;i<n;i++){
            nums[i]=max(nums[i]+prev,nums[i-1]);
            prev=nums[i-1];
        }
        return nums[n-1];
    }
};

class Solution {
public:
    int rob(vector<int>& nums) {
        int prev2 = 0;
        int prev1 = 0;
        for(int num : nums) {
            int curr = max(prev1, num + prev2);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};