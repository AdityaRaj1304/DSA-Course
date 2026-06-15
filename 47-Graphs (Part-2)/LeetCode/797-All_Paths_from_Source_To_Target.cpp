#include <bits/stdc++.h>
using namespace std;


class Solution { //Solution for this question since the graph given is Acyclic
public:
    void dfs(vector<vector<int>>&graph,int src,int dest,vector<int>&path,vector<vector<int>>&ans){
        if(src==dest){
            ans.push_back(path);
            return;
        }
        for(int v:graph[src]){
            path.push_back(v);
            dfs(graph,v,dest,path,ans);
            path.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>>ans;
        vector<int>path;
        path.push_back(0);
        dfs(graph,0,n-1,path,ans);
        return ans;
    }
};




class Solution { //General Solution for Any Graph 
public:
    void dfs(vector<vector<int>>&graph,int src,int dest,vector<bool>&vis,vector<int>&path,vector<vector<int>>&ans){
        vis[src]=true;
        path.push_back(src);
        if(src==dest){
            ans.push_back(path);
        }
        for(int v:graph[src]){
            if(!vis[v]){
                dfs(graph,v,dest,vis,path,ans);
            }
        }
        path.pop_back();
        vis[src]=false;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>>ans;
        vector<int>path;
        vector<bool>vis(n,0);
        dfs(graph,0,n-1,vis,path,ans);
        return ans;
    }
};




