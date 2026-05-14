#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int>s;
        int n = prices.size();
        vector<int>ans(n,0);
        for(int i = n-1;i>=0;i--){
            while(!s.empty()&&prices[i]<s.top()){
                s.pop();
            }
            if(!s.empty()){
                ans[i]=prices[i]-s.top();
            }else{
                ans[i]=prices[i];
            }
            s.push(prices[i]);
        }
        return ans;
    }
};