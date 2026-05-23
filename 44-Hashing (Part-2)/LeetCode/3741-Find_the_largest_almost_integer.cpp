#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = -1;
        if(k==n){
            ans=*max_element(nums.begin(),nums.end());
            return ans;
        }else{
            unordered_map<int,int>freq;
            for(int num:nums){
                freq[num]++;
            }
            if(k==1){
                for(auto it:freq){
                    if(it.second==1){
                        ans=max(ans,it.first);
                    }
                }
            }else{
                if(freq[nums[0]]==1){
                    ans=nums[0];
                }
                if(freq[nums[n-1]]==1){
                    ans=max(ans,nums[n-1]);
                }
            }
        }
        return ans;
    }
};