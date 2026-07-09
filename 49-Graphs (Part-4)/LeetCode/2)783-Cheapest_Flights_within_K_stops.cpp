#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>graph(n);
        for(auto&edge:flights){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            graph[u].push_back({v,wt});
        }
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        vector<vector<int>>dist(n,vector<int>(k+2,INT_MAX));
        pq.push({0,src,0});
        dist[src][0]=0;
        while(pq.size()>0){
            auto v = pq.top();
            pq.pop();
            int cost = v[0];
            int u = v[1];
            int stops = v[2];
            if(u == dst){
                return cost;
            }
            if(stops>=k+1){
                continue;
            }
            if(cost>dist[u][stops]){
                continue;
            }
            for(auto&[v,wt]:graph[u]){
                if(dist[v][stops+1]>cost+wt){
                    dist[v][stops+1]=cost+wt;
                    pq.push({dist[v][stops+1],v,stops+1});
                }
            }
        }
        return -1;
    }
};


