#include<bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     bool helper(vector<vector<int>>&graph,int src){
//         if(graph[src].size()==0){
//             return true;
//         }
//         for(int v:graph[src]){
//             if(graph[v].size()!=0){
//                 return false;
//             }
//         }
//         return true;
//     }
//     vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
//         vector<int>ans;
//         for(int i = 0;i<graph.size();i++){
//             if(helper(graph,i)){
//                 ans.push_back(i);
//             }
//         }
//         return ans;
//     }
// };


class Solution {
public:
    void dfs(vector<vector<int>>&graph,int src , vector<int>&outdegree,vector<bool>&vis,vector<int>&ans){
        if(outdegree[src]==0){
            ans.push_back(src);
            return ;
        }
        vis[src]=true;
        for(int v:graph[src]){
            if(outdegree[v]==0){
                outdegree[src]--;
            }
        }
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int>outdegree;
        vector<bool>vis(V,false);
        vector<int>ans;
        for(int i =0;i<V;i++){
            outdegree.push_back(graph[i].size());
        }
        for(int i =0;i<V;i++){
            if(!vis[i]){
                dfs(graph,i,outdegree,vis,ans);
            }
        }
        return ans;
    }
};