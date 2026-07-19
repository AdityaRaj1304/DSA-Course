#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int,double>>>graph(n);
        int idx =0;
        for(auto&edge:edges){
            int u = edge[0];
            int v = edge[1];
            double wt = succProb[idx++];
            graph[u].push_back({v,wt});
            graph[v].push_back({u,wt});
        }
        priority_queue<pair<double,int>>pq;
        vector<double>prob(n,0.0);
        prob[start_node]=1.0;
        pq.push({1.0,start_node});
        while(!pq.empty()){
            auto[p,u] = pq.top();
            pq.pop();
            if(u==end_node){
                return p;
            }
            if(p<prob[u]){
                continue;
            }
            for(auto&[v,wt]:graph[u]){
                if(prob[v]<prob[u]*wt){
                    prob[v]=prob[u]*wt;
                    pq.push({prob[v],v});
                }
            }
        }
        return prob[end_node];
    }
};
