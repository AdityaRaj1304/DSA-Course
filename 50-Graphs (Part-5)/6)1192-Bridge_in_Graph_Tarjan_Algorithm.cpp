#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class Solution {
public:
    vector<int>dt,low;
    int time = 0;
    void dfs(vector<vector<int>>&graph,int u, int par, vector<vector<int>>&bridges){
        dt[u]=low[u]=time++;
        for(int v:graph[u]){
            if(dt[u]==-1){
                dfs(graph,v,u,bridges);
                low[u]=min(low[u],low[v]);
                if(low[v]>dt[u]){ // BRIDGE
                    bridges.push_back({u,v});
                }
            }else{
                low[u]=min(low[u],dt[v]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>>graph(n);
        vector<vector<int>>bridges;
        for(auto &edge:connections){
            int u =edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        dt.resize(n,-1);
        low.resize(n,0);
        for(int i =0;i<n;i++){
            if(dt[i]==-1){
                dfs(graph,i,-1,bridges);
            }
        }
        return bridges;
    }
};