#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dirGraph(vector<vector<int>>& relations,vector<vector<int>>& graph) {
        for (auto& edge : relations) {
            int u = edge[0]-1;
            int v = edge[1]-1;
            graph[u].push_back(v);
        }
    }
    void calcIndegree(vector<vector<int>>&graph,vector<int>&inDeg){
        int V = graph.size();
        for(int u =0;u<V;u++){
            for(int v:graph[u]){
                inDeg[v]++;
            }
        }
    }
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>>graph(n);
        dirGraph(relations,graph);
        vector<int>inDeg(n,0);
        calcIndegree(graph,inDeg);
        vector<int>course(n,0);
        queue<int>q;
        for(int i =0;i<n;i++){
            if(inDeg[i]==0){
                q.push(i);
            }
            course[i]=time[i];
        }

        int ans =0;
        while(q.size()>0){
            int curr = q.front();
            q.pop();
            for(int v:graph[curr]){
                inDeg[v]--;
                course[v]=max(course[v],course[curr]+time[v]);
                if(inDeg[v]==0){
                    q.push(v);
                }
            }
        }
        return *max_element(course.begin(),course.end());
    }
};