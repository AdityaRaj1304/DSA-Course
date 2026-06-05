#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void adjacencyList(vector<vector<int>>&mat,vector<vector<int>>&graph){
        int n = mat.size();
        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                if(mat[i][j]){
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
    }
    void dfs(vector<vector<int>>&graph,int u , vector<bool>&vis){
        vis[u]=true;
        for(int v: graph[u]){
            if(!vis[v]){
                dfs(graph,v,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>>graph(n);
        vector<bool>vis(n,0);
        int ans = 0;
        adjacencyList(isConnected,graph);
        for(int i = 0;i<n;i++){
            if(!vis[i]){
                ans++;
                dfs(graph,i,vis);
            }
        }
        return ans;
    }
};


//Optimal Solution - No Extra Adjaceny Matrix 
class Solution {
public:
    void dfs(int u, vector<vector<int>>& isConnected, vector<bool>& vis) {
        vis[u] = true;

        for(int v = 0; v < isConnected.size(); v++) {
            if(isConnected[u][v] == 1 && !vis[v]) {
                dfs(v, isConnected, vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> vis(n, false);

        int provinces = 0;

        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                provinces++;
                dfs(i, isConnected, vis);
            }
        }

        return provinces;
    }
};