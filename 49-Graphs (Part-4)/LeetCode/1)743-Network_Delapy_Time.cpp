#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>graph(n+1);
        for(auto&edge:times){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            graph[u].push_back({v,wt});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>dist(n+1,INT_MAX);
        pq.push(make_pair(0,k));
        dist[k]=0;
        while(pq.size()>0){
            auto[d,u]=pq.top();
            pq.pop();
            if(d>dist[u]){
                continue;
            }
            for(auto&[v,wt]:graph[u]){
                if(dist[v]>dist[u]+wt){
                    dist[v]=dist[u]+wt;
                    pq.push(make_pair(dist[v],v));
                }
            }
        }
        int ans = 0;
        for(int i =1;i<dist.size();i++){
            if(dist[i]==INT_MAX){
                return -1;
            }else{
                ans =max(ans,dist[i]);
            }
        }
        return ans;
    }
};

