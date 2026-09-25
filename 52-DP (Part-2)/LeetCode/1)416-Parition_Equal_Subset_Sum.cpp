#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// class Solution { //Recursion Approach 
// public:
//     bool helperRec(vector<int>&nums,int idx, int sum ,int target){
//         if(sum>target || idx==nums.size()){
//             return false;
//         }
//         if(sum==target){
//             return true;
//         }
//         return helperRec(nums,idx+1,sum+nums[idx],target) || helperRec(nums,idx+1,sum,target);
//     }
//     bool canPartition(vector<int>& nums) {
//         int total = accumulate(nums.begin(),nums.end(),0);
//         if(total%2!=0){
//             return false;
//         }
//         return helperRec(nums,0,0,total/2);
//     }
// };


class Solution {
public:
    bool mem(vector<int>&nums,int idx, int sum ,int target,vector<vector<int>>&dp){
        if(sum>target || idx==nums.size()){
            return false;
        }
        if(sum==target){
            return true;
        }
        if(dp[idx][sum]!=-1){
            return dp[idx][sum];
        }
        return dp[idx][sum]=mem(nums,idx+1,sum+nums[idx],target,dp) || mem(nums,idx+1,sum,target,dp);
    }
    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(),nums.end(),0);
        if(total%2!=0){
            return false;
        }
        int target = total/2;
        vector<vector<int>>dp(nums.size(),vector<int>(target+1,-1));
        return mem(nums,0,0,target,dp);
    }
};