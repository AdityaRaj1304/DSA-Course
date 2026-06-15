#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void adjacencyList(vector<vector<int>>& edges, vector<vector<int>>& graph) {
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
    }
    void dfs(vector<vector<int>>& graph, int src, vector<bool>& vis,
             int& vertice, int& degree) {
        vis[src] = true;
        vertice++;
        degree += graph[src].size();
        for (int v : graph[src]) {
            if (!vis[v]) {
                dfs(graph, v, vis, vertice, degree);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        int ans = 0;
        vector<vector<int>> graph(n);
        adjacencyList(edges, graph);
        vector<bool> vis(n, false);
        for (int i = 0; i < n; i++) {
            int degree = 0, vertice = 0;
            if (!vis[i]) {
                dfs(graph, i, vis, vertice, degree);
                int edges = degree / 2;
                if (edges == (vertice * (vertice - 1)) / 2) {
                    ans++;
                }
            }
        }
        return ans;
    }
};




// class Solution { // Wrong Approach -> Connected Components are not related to Cycles
// public:
//     void adjacencyList(vector<vector<int>>&edges,vector<vector<int>>&graph){
//         for(auto& edge :edges){
//             int u = edge[0];
//             int v = edge[1];
//             graph[u].push_back(v);
//             graph[v].push_back(u);
//         }
//     }
//     bool cycleHelperUndirected(vector<vector<int>>graph,int src , int parent , vector<bool>&vis,vector<int>&ans){
//         vis[src]=true;
//         for(int v : graph[src]){
//             if(!vis[v]){
//                 if(cycleHelperUndirected(graph,v,src,vis,ans)){
//                     return true;
//                 }
//             }else{
//                 if(v!=parent){
//                     ans.push_back(src);
//                     ans.push_back(true);
//                     return true;
//                 }
//             }
//         }
//         return false;
//     }
//     vector<int> findRedundantConnection(vector<vector<int>>& edges) {
//         int n = edges.size();
//         vector<vector<int>>graph(n+1);
//         vector<bool>vis(n+1,false);
//         adjacencyList(edges,graph);
//         vector<int>ans;
//         cycleHelperUndirected(graph,1,-1,vis,ans);
//         return ans;
//     }
// };