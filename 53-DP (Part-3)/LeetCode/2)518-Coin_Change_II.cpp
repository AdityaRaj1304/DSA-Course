#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<ll>>dp(n+1,vector<ll>(amount+1,0));
        for(int i=1;i<=n;i++){
            dp[i][0]=1;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=amount;j++){
                if(coins[i-1]<=j){
                    ll take = dp[i][j-coins[i-1]];
                    ll skip =dp[i-1][j];
                    dp[i][j]=min((ll)INT_MAX,take+skip);
                }else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][amount];
    }
};


class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<ll>dp(amount+1,0);
        dp[0]=1;
        for(int coin:coins){
            for(int i=coin;i<=amount;i++){
                ll take = dp[i-coin];
                ll skip = dp[i];
                if(take>INT_MAX-skip){
                    dp[i]=INT_MAX;
                }else{
                    dp[i]=take+skip;
                }
            }
        }
        return dp[amount];
    }
};
