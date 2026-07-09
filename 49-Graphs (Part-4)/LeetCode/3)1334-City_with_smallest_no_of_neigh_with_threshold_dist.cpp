#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dijkstra(vector<vector<pair<int,int>>>&graph,int src,vector<int>&dist){
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,src});
        dist[src]=0;
        while(pq.size()>0){
            auto[d,u] = pq.top();
            pq.pop();
            if(d>dist[u]){
                continue;
            }
            for(auto&[v,wt]:graph[u]){
                if(dist[v]>dist[u]+wt){
                    dist[v]=dist[u]+wt;
                    pq.push({dist[v],v});
                }
            }
        }
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int ans =0;
        int nodes = INT_MAX;
        vector<vector<pair<int,int>>>graph(n);
        for(auto&edge:edges){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            graph[u].push_back({v,wt});
            graph[v].push_back({u,wt});
        }
        for(int src=0;src<n;src++){
            int count =0;
            vector<int>dist(n,INT_MAX);
            dijkstra(graph,src,dist);
            for(int i=0;i<n;i++){
                if(dist[i]<=distanceThreshold){
                    count++;
                }
            }
            if(count<nodes){
                ans=src;
                nodes=count;
            }else if(count == nodes && src>ans){
                ans=src;
            }
        }
        return ans;
    }
};