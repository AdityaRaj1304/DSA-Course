#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        int maxm = *max_element(nums.begin(),nums.end());
        vector<int>sum(maxm+1,0);
        for(int num:nums){
            sum[num]+=num;
        }
        vector<int>dp(maxm+1,0);
        dp[0]=0;
        dp[1]=sum[1];
        int ans = 0;
        for(int i =2;i<=maxm;i++){
            dp[i]=max(dp[i-1],dp[i-2]+sum[i]);
        }
        return dp[maxm];
    }
};