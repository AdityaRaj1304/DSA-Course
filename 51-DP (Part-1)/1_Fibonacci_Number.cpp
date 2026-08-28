#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int fibRec(int n){
    if(n==0||n==1){
        return n;
    }
    return fibRec(n-1)+fibRec(n-2);
}

int fibMem(int n , vector<int>& dp){
    if(n==0||n==1){
        return n;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    dp[n]=fibMem(n-1,dp)+fibMem(n-2,dp);
    return dp[n];
}

int fibTab(int n){
    vector<int>dp(n+1,0);
    dp[1]=1;
    for(int i =2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}

int main(){
    int n = 42;
    cout << fibRec(n)<< endl;
    vector<int>dp(n+1,-1);
    cout << fibMem(n,dp)<<endl;
    cout << fibTab(n);
    return 0;
}