#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int turns = piles.size()/3;
        int ans = 0;
        int n = piles.size();
        sort(piles.begin(),piles.end());
        int round = 0;
        int idx = n-2;
        while(round<turns){
            ans+=piles[idx];
            idx-=2;
            round++;
        }
        return ans;
    }
};

class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        int ans = 0;
        int n = piles.size();
        for(int i = n/3; i < n; i += 2){
            ans += piles[i];
        }
        return ans;
    }
};