#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        int ans =0;
        sort(nums.begin(),nums.end(),[](auto &a ,auto&b){
            return a[0]<b[0];
        });
        int currStart=nums[0][0];
        int currEnd=nums[0][1];
        for(int i =1 ;i<nums.size();i++){
            if(currEnd>=nums[i][0]){
                currEnd=max(currEnd,nums[i][1]);
            }else{
                ans+=(currEnd-currStart)+1;
                currStart=nums[i][0];
                currEnd=nums[i][1];
            }
        }
        ans+=currEnd-currStart+1;
        return ans;
    }
};