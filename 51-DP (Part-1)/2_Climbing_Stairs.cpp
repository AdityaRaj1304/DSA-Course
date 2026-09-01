#include<bits/stdc++.h>
using namespace std;

int countWaysRec(int n){
    if(n==0 || n ==1){
        return 1;
    }
    return countWaysRec(n-1)+countWaysRec(n-2);
}

int countWaysMem(int n ,vector<int>&dp){
    if(n==0 || n ==1){
        return 1;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    return countWaysMem(n-1,dp) + countWaysMem(n-2,dp);
}

int countWaysTab(int n){
    vector<int>dp(n+1,0);
    dp[0]=dp[1]=1;
    for(int i =2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}

int countWaysOpt(int n){
    if(n<3){
        return n;
    }
    int prev = 1;
    int curr = 2;
    for(int i =3;i<=n;i++){
        curr+=prev;
        prev=curr-prev;
    }
    return curr;
}

int main(){
    int n = 5;
    cout << countWaysRec(5) << endl;
    vector<int>dp(n+1,-1);
    cout << countWaysMem(n,dp) << endl;
    cout << countWaysTab(n) << endl;
    cout << countWaysOpt(n);
    return 0;
}