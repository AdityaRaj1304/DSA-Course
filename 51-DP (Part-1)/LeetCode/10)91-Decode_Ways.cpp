#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if(s[0]=='0'){
            return 0;
        }
        vector<int>dp(n+1,0);
        dp[0]=1;
        dp[1]=1;
        for(int i =2;i<=n;i++){
            int digit = s[i-1]-'0';
            int twoDigits = stoi(s.substr(i-2,2));
            if(digit!=0){
                dp[i]+=dp[i-1];
            }
            if(twoDigits>=10 && twoDigits<=26){
                dp[i]+=dp[i-2];
            }
        }
        return dp[n];
    }
};


