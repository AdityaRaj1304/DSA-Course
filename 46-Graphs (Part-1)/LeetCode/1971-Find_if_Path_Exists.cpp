#include<bits/stdc++.h>
using namespace std;


//DFS Based Code
class Solution {
public:
    void adjacencyList(vector<vector<int>>&edges,vector<vector<int>>&graph){
        for(auto& edge :edges){
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
    }
    bool pathHelper(int src , int dest, vector<vector<int>>&edges , vector<bool>&vis){
        if(src == dest){
            return true;
        }
        vis[src]=true;
        for(int v : edges[src]){
            if(!vis[v]){
                if(pathHelper(v,dest,edges,vis)){
                    return true;
                }
            }
        }
        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>graph(n);
        vector<bool>vis(n,false);
        adjacencyList(edges,graph);
        return pathHelper(source,destination,graph,vis);
    }
};



// BFS Based Code
class Solution {
public:
    void adjacencyList(vector<vector<int>>&edges ,vector<list<int>>&graph){
        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<list<int>>graph(n);
        adjacencyList(edges,graph);
        queue<int>q;
        vector<bool>vis(n,false);
        q.push(source);
        vis[source]=true;
        while(q.size()>0){
            int u = q.front();
            if(u==destination){
                return true;
            }
            q.pop();
            for(int v : graph[u]){
                if(!vis[v]){
                    vis[v]=true;
                    q.push(v);
                }
            }
        }
        return false;
    }
};