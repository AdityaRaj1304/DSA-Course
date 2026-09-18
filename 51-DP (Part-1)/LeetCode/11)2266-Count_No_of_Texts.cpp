#include <bits/stdc++.h>
using namespace std;
using ll = long long;


//Memoization
class Solution {
public:
    int MOD = 1e9+7;
    int solve(string& pressedKeys, int i , vector<int>&dp){
        int n = pressedKeys.size();
        if(i>=n){
            return 1;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int limit = (pressedKeys[i]=='7'||pressedKeys[i]=='9')? 4:3;
        int ways = 0;
        for(int j =1;j<=limit;j++){
            if(i+j-1<n&&pressedKeys[i]==pressedKeys[i+j-1]){
                ways=(ways+solve(pressedKeys,i+j,dp))%MOD;
            }else{
                break;
            }
        }
        cout << i << " : " << ways << "\n";
        return dp[i]=ways;
    }
    int countTexts(string pressedKeys) {
        int n = pressedKeys.size();
        vector<int>dp(n,-1);
        return solve(pressedKeys,0,dp);
    }
};


//Tabulation
class Solution {
public:
    int MOD = 1e9+7;
    int countTexts(string pressedKeys) {
        int n = pressedKeys.size();
        vector<int>dp(n+1,0);
        dp[0]=1;
        for(int i =1;i<=n;i++){
            int limit = (pressedKeys[i-1]=='7'||pressedKeys[i-1]=='9')? 4:3;
            for(int j=1;j<=limit;j++){
                if(i-j<0){
                    break;
                }
                if(pressedKeys[i-1]==pressedKeys[i-j]){
                    dp[i]=(dp[i]+dp[i-j])%MOD;
                    // cout << dp[i] << " ";
                }else{
                    break;
                }
            }
        }
        return dp[n];
    }
};

//Space Optimization 
class Solution {
public:
    int MOD = 1e9 + 7;
    
    int countTexts(string pressedKeys) {
        int n = pressedKeys.size();
        
        // A fixed-size array of 4 to hold our rolling states
        vector<int> dp(4, 0);
        
        // Base case: 1 way to decode an empty prefix at index 0
        dp[0] = 1; 
        
        for (int i = 1; i <= n; i++) {
            int limit = (pressedKeys[i - 1] == '7' || pressedKeys[i - 1] == '9') ? 4 : 3;
            
            // Reset the current position before accumulating new ways
            dp[i % 4] = 0;
            
            // Look backward up to `limit` steps
            for (int j = 1; j <= limit; j++) {
                if (i - j < 0) {
                    break;
                }
                
                // If the character matches, add the ways from (i - j) using modulo math
                if (pressedKeys[i - 1] == pressedKeys[i - j]) {
                    dp[i % 4] = (dp[i % 4] + dp[(i - j) % 4]) % MOD;
                } else {
                    break;
                }
            }
        }
        
        // The final answer resides at n % 4
        return dp[n % 4];
    }
};
