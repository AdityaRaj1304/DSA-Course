#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class Solution {
public:
    int numSquares(int n) {
        vector<int>sqnum;
        for(int i =1;i*i<=n;i++){
            sqnum.push_back(i*i);
        }
        if(sqnum.back()==n){
            return 1;
        }
        vector<int>dp(n+1,n+1);
        dp[0]=0;
        for(int i=1;i<=n;i++){
            for(int num:sqnum){
                if(num>i){
                    break;
                }
                dp[i]=min(1+dp[i-num],dp[i]);
            }
        }
        return dp[n];
    }
};