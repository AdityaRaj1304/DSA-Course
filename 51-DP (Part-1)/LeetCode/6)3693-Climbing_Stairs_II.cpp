#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        for(int i =0;i<n;i++){
            if(i>=3){
                costs[i]+=min({costs[i-3]+9,costs[i-2]+4,costs[i-1]+1});
            }else{
                if(i==0){
                    costs[i]+=1;
                }else if(i==1){
                    costs[i]+=min(costs[i-1]+1,4);
                }else{
                    costs[i]+=min({costs[i-2]+4,costs[i-1]+1,9});
                }
            }
        }
        return costs[n-1];
    }
};