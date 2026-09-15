#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    vector<int>dp(n);
    dp[0]=0;
    dp[1]=abs(nums[1]-nums[0]);
    for(int i=2;i<n;i++){
        dp[i]=min(abs(nums[i]-nums[i-1])+dp[i-1],abs(nums[i]-nums[i-2])+dp[i-2]);
    }
    cout << dp[n-1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}