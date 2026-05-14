#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int>s;
        int n = temperatures.size();
        int idx = n-1;
        vector<int>ans(n,0);
        ans[idx]=0;
        s.push(idx);
        for(idx = idx-1;idx>=0;idx--){
            while(!s.empty()&&temperatures[idx]>=temperatures[s.top()]){
                s.pop();
            }
            if(s.empty()){
                ans[idx]=0;
            }else{
                ans[idx]=s.top()-idx;
            }
            s.push(idx);
        }
        return ans;
    }
};