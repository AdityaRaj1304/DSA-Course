#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int knapsackRec(vector<int>&val,vector<int>&wt,int W,int n){
    if(W==0||n==0){
        return 0;
    }
    int itemVal = val[n-1];
    int itemWt = wt[n-1];
    if(itemWt<=W){
        int include = knapsackRec(val,wt,W-itemWt,n-1)+itemVal;
        int exclude = knapsackRec(val,wt,W,n-1);
        return max(include,exclude);
    }else{
        return knapsackRec(val,wt,W,n-1);
    }
}

int knapsackMem(vector<int>&val,vector<int>&wt,int W,int n,vector<vector<int>>&dp){
    if(W==0||n==0){
        return 0;
    }
    if(dp[n][W]!=-1){
        return dp[n][W];
    }
    int itemVal = val[n-1];
    int itemWt = wt[n-1];
    if(itemWt<=W){
        int include = knapsackMem(val,wt,W-itemWt,n-1,dp)+itemVal;
        int exclude = knapsackMem(val,wt,W,n-1,dp);
        return dp[n][W]=max(include,exclude);
    }else{
        return dp[n][W]=knapsackMem(val,wt,W,n-1,dp);
    }
}

int knapsackTab(vector<int>&val,vector<int>&wt,int W){
    int n = val.size();
    vector<vector<int>>dp(n+1,vector<int>(W+1,0));
    for(int i =1;i<=n;i++){
        for(int j =1;j<=W;j++){
            int itemVal=val[i-1];
            int itemWt = wt[i-1];
            if(itemWt<=W){
                dp[i][j]=max(itemVal+dp[i-1][j-itemWt],dp[i-1][j]);
            }else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    for(int i=0;i<=n;i++){
        for(int j =0;j<=W;j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return dp[n][W];
}

int main(){
    vector<int>val={15,14,10,45,30};
    vector<int>wt={2,5,1,3,4};
    int W = 7;
    int n = 5;
    vector<vector<int>>dp(n+1,vector<int>(W+1,-1));
    cout << knapsackRec(val,wt,W,n) << endl;
    cout << knapsackMem(val,wt,W,n,dp) << endl;
    for(int i=0;i<=n;i++){
        for(int j =0;j<=W;j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << knapsackTab(val,wt,W);
    return 0;
}
