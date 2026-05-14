#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maximum=0,ans=0;
        for(int i :nums){
            maximum|=i;
        }
        subset(nums,0,maximum,0,ans);
        return ans;
    }
    void subset(vector<int>&nums,int idx , int maximum , int temp ,int&ans){
        if(idx==nums.size()){
            if(temp==maximum){
                ans++;
            }
            return;
        }
        subset(nums,idx+1,maximum,temp|nums[idx],ans);
        subset(nums,idx+1,maximum,temp,ans);
    }
};