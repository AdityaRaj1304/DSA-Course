#include<bits/stdc++.h>
using namespace std;

//Method-1
class Solution { //Topo Sort Apporach 
public:
    void calcIndegree(vector<vector<int>>&graph,vector<int>&inDeg){
        int V = graph.size();
        for(int u =0;u<V;u++){
            for(int v:graph[u]){
                inDeg[v]++;
            }
        }
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<vector<int>>revGraph(V);
        for(int u=0;u<V;u++){
            for(int v:graph[u]){
                revGraph[v].push_back(u);
            }
        }
        vector<int>inDeg(V,0);
        calcIndegree(revGraph,inDeg);
        queue<int>q;
        for(int i = 0;i<V;i++){
            if(inDeg[i]==0){
                q.push(i);
            }
        }
        vector<bool>safe(V,false);
        while(q.size()>0){
            int curr = q.front();
            q.pop();
            safe[curr]=true;
            for(int v :revGraph[curr]){
                inDeg[v]--;
                if(inDeg[v]==0){
                    q.push(v);
                }
            }
        }
        vector<int>ans;
        for(int i =0;i<V;i++){
            if(safe[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};

//Method-2[DFS Approach - Start from each node and check if any path reaches a cycle]
class Solution {
public:
    bool dfs(vector<vector<int>>&graph,int src,vector<bool>&vis,vector<bool>&rec,vector<bool>&safe){
        vis[src]=true;
        rec[src]=true;
        for(int v:graph[src]){
            if(!vis[v]){
                if(!dfs(graph,v,vis,rec,safe)){
                    return false;
                }
            }else if(rec[v]){
                return false;
            }else if(!safe[v]){
                return false;
            }
        }
        rec[src]=false;
        safe[src]=true;
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<bool>vis(V,false);
        vector<bool>rec(V,false);
        vector<bool>safe(V,false);
        vector<int>ans;
        for(int i =0;i<V;i++){
            if(dfs(graph,i,vis,rec,safe)){
                ans.push_back(i);
            }
        }
        return ans;
    }
};


//Method-2[DFS Approach - Start from each node and check if any path reaches a cycle]->Same Approach with One single vector
class Solution {
public:
    bool dfs(vector<vector<int>>&graph,int src,vector<int>&state){
        if(state[src]==1){
            return false;
        }
        if(state[src]==2){
            return true;
        }
        state[src]=1;
        for(int v:graph[src]){
            if(!dfs(graph,v,state)){
                return false;
            }
        }
        state[src]=2;
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int>state(V,0);
        vector<int>ans;
        for(int i =0;i<V;i++){
            if(dfs(graph,i,state)){
                ans.push_back(i);
            }
        }
        return ans;
    }
};

