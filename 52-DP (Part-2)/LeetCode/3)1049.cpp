#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class Solution {
public:
    int ans = INT_MAX;
    void helper(vector<int>&stones,int idx, int sum){
        if(idx==stones.size()){
            ans=min(ans,abs(sum));
            return;
        }
        helper(stones,idx+1,sum+stones[idx]);
        helper(stones,idx+1,sum-stones[idx]);
    }
    int lastStoneWeightII(vector<int>& stones) {
        helper(stones,0,0);
        return ans;
    }
};

class Solution {
public:
    int helper(vector<int>& stones, int idx, int sum,
               map<pair<int,int>, int>& dp) {
        if(idx == stones.size()){
            return abs(sum);
        }
        if(dp.count({idx, sum})){
            return dp[{idx, sum}];
        }
        int add = helper(stones, idx + 1, sum + stones[idx], dp);
        int sub = helper(stones, idx + 1, sum - stones[idx], dp);
        return dp[{idx, sum}] = min(add, sub);
    }

    int lastStoneWeightII(vector<int>& stones) {
        map<pair<int,int>, int> dp;
        return helper(stones, 0, 0, dp);
    }
};