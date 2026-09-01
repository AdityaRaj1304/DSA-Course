#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class Solution {
public:
    int mem(int n , vector<int>&cost,vector<int>&dp){
        if(n==0||n==1){
            return cost[n];
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        return dp[n]=cost[n]+min(mem(n-1,cost,dp),mem(n-2,cost,dp));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n,-1);
        return min(mem(n-1,cost,dp),mem(n-2,cost,dp));
    }
};


class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n,-1);
        dp[0]=cost[0];
        dp[1]=cost[1];
        for(int i =2;i<n;i++){
            dp[i]=cost[i]+min(dp[i-1],dp[i-2]);
        }
        return min(dp[n-1],dp[n-2]);
    }
};

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int first = cost[0];
        int second = cost[1];
        for(int i =2;i<n;i++){
            int curr =cost[i]+min(first,second);
            first=second;
            second=curr;
        }
        return min(first,second);
    }
};

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        for(int i =2;i<n;i++){
            cost[i]+=min(cost[i-1],cost[i-2]);
        }
        return min(cost[n-1],cost[n-2]);
    }
};