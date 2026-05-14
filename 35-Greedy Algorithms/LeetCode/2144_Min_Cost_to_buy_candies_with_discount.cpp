#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end(),greater<int>());
        int ans = cost[0];
        for(int i = 1 ; i<cost.size();i++){
            if((i+1)%3==0){
                continue;
            }else{
                ans+=cost[i];
            }
        }
        return ans;
    }
};