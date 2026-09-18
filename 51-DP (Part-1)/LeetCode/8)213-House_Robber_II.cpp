#include <bits/stdc++.h>
using namespace std;
using ll = long long;


class Solution {
public:
    int solve(vector<int>&nums,int idx, int end , vector<int>&dp){
        if(idx>=end){
            return 0;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        int rob = nums[idx]+solve(nums,idx+2,end,dp);
        int skip = solve(nums,idx+1,end,dp);
        return dp[idx]=max(rob,skip);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) {
            return nums[0];
        }
        vector<int>dp(n,-1);
        int robHouse1 = solve(nums,0,n-1,dp);
        fill(dp.begin(), dp.end(), -1);
        int robHouseN = solve(nums,1,n,dp);
        return max(robHouse1,robHouseN);
    }
};



class Solution { //Best Solution TC=O(n) , SC = O(1)
public:
    int helper(vector<int>&nums,int st , int end){
        int prev2=0;
        int prev1=0;
        for(int i =st;i<end;i++){
            int curr = max(prev1,prev2+nums[i]);
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            return nums[0];
        }
        return max(helper(nums,0,n-1),helper(nums,1,n));
    }
};
