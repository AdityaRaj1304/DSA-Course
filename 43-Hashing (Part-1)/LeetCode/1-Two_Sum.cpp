#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        vector<int>ans;
        for(int i = 0;i<nums.size();i++){
            int comp= target-nums[i];
            if(mp.count(comp)){
                ans.push_back(i);
                ans.push_back(mp[comp]);
                break;
            }
            mp[nums[i]]=i;
        }
        return ans;
    }
};