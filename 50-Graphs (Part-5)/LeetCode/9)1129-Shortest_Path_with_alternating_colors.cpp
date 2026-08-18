#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<pair<int,int>>>graph;
        for(auto&edge:redEdges){
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back({v,0});
        }
        for(auto&edge:blueEdges){
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back({v,1});
        }
        vector<int>ans(n,-1);
        ans[0]=0;
        queue<pair<int,int>>q;
        vector<vector<bool>>vis(n,vector<bool>(2,false));
        q.push({0,0});
        q.push({0,1});
        vis[0][0]=true;
        vis[0][1]=true;
        int dist =0;
        while(q.size()>0){
            int size = q.size();
            while(size--){
                auto[u,prevColor]=q.front();
                q.pop();
                if(ans[u]==-1){
                    ans[u]=dist;
                } 
                for(auto node:graph[u]){
                    int v = node.first;
                    int color = node.second;
                    if(color==prevColor){
                        continue;
                    }
                    if(!vis[v][color]){
                        vis[v][color]=true;
                        q.push({v,color});
                    }
                }
            }
            dist++;
        }
        return ans;
    }
};