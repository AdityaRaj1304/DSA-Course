#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class Solution {
public:
    vector<int> findCoins(vector<int>& numWays) {
        int n = numWays.size();
        vector<int>ans;
        for(int i=1;i<=n;i++){
            if(numWays[i-1]==1){
                ans.push_back(i);
                numWays[i-1]=0;
                for(int j=n;j>i;j--){
                    numWays[j-1]-=numWays[j-i-1];
                }
            }
        }
        for(int ways:numWays){
            if(ways!=0){
                return {};
            }
        }
        return ans;
    }
};