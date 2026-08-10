#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class DisjointSet{
public:
    int n;
    vector<int>par,rank;

    DisjointSet(int n){
        this->n=n;
        rank.assign(n+1,0); //Better Way
        for(int i =0;i<=n;i++){
            par.push_back(i);
            //rank.push_back(0);
        }
    }

    int find(int x){
        if(par[x]==x){
            return x;
        }
        return par[x]=find(par[x]); //Path Compression
    }

    void unionByRank(int a, int b){
        int parA = find(a);
        int parB = find(b);
        if(rank[parA]==rank[parB]){
            par[parB]=parA;
            rank[parA]++;
        }else if(rank[parA]>rank[parB]){
            par[parB]=parA;
        }else{
            par[parA]=parB;
        }
    }
};


class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DisjointSet ds(n);
        for(auto&edge:edges){
            int u = edge[0];
            int v = edge[1];
            int parU = ds.find(u);
            int parV=ds.find(v);
            if(parU==parV){
                return {u,v};
            }else{
                ds.unionByRank(parU,parV);
            }
        }
        return {};
    }
};