#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int>>pq;
        for(int i = 0;i<mat.size();i++){
            int count = 0;
            for(int j =0;j<mat[i].size() && mat[i][j]==1;j++){
                count++;
            }
            pq.push({count,i});
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<int>ans(pq.size(),0);
        int idx = pq.size()-1;
        while(!pq.empty()){
            ans[idx--]=pq.top().second;
            pq.pop();
        }
        return ans;
    }
};