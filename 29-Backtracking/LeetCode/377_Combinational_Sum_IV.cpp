#include<bits/stdc++.h>
using namespace std;
class Solution { // TLE for backtracking need to use DP
public:
    int combinationSum4(vector<int>& nums, int target) {
        int ans  = 0;
        solution(nums,target,0,ans);
        return ans;
    }
    void solution(vector<int>&nums, int target ,int sum ,int &ans){
        if(sum==target){
            ans++;
        }
        if(sum>target){
            return ;
        }
        for(int i = 0 ; i<nums.size();i++){
            sum+=nums[i];
            solution(nums,target,sum,ans);
            sum-=nums[i];
        }
    }
};