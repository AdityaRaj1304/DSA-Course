#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class DisjointSet{
public:
    int n ;
    vector<int>par,rank;

    DisjointSet(int n){
        this->n=n;
        rank.assign(n,0);
        for(int i=0;i<n;i++){
            par.push_back(i);
        }
    }

    int find(int x){
        if(par[x]==x){
            return x;
        }
        return par[x]=find(par[x]);
    }
    
    void unionByRank(int u, int v){
        int parU = find(u);
        int parV = find(v);
        if(rank[parU]==rank[parV]){
            par[parV]=parU;
            rank[parU]++;
        }else if(rank[parU]>rank[parV]){
            par[parV]=parU;
        }else{
            par[parU]=parV;
        }
    }
};

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        DisjointSet dsu(26);
        for(string eq:equations){
            char u = eq[0];
            char v = eq[3];
            if(eq[1]=='='){
                if(dsu.find(u)!=dsu.find(v)){
                    return false;
                }else{
                    dsu.unionByRank(u,v);
                }
            }else{
                if(dsu.find(u)==dsu.find(v)){
                    return false;
                }else{
                    dsu.unionByRank(u,v);
                }
            }
        }
        return true;
    }
};
















