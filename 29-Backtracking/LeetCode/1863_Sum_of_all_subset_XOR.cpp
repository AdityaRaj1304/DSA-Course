#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int ans = 0;
        subsets(nums,0,0,ans);
        return ans;
    }
    void subsets(vector<int>&nums , int idx , int sum , int&ans){
        if(idx==nums.size()){
            ans+=sum;
            return;
        }
        int n = nums[idx];
        sum^=nums[idx];
        subsets(nums,idx+1,sum,ans);
        sum^=nums[idx];
        subsets(nums,idx+1,sum,ans);
    }
};