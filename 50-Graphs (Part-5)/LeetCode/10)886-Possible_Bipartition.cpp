#include <bits/stdc++.h>
using namespace std;
using ll = long long;


//Approach 1 - Disjoint Set
class DisjointSet {
public:
    int n;
    vector<int> par, rank;

    DisjointSet(int n) {
        this->n = n;
        rank.assign(n, 0);
        for(int i = 0; i < n; i++) {
            par.push_back(i);
        }
    }

    int find(int x) {
        if(par[x] == x) {
            return x;
        }
        return par[x] = find(par[x]);
    }
    
    bool unionByRank(int u, int v) {
        int parU = find(u);
        int parV = find(v);
        
        if(parU == parV) {
            return false;
        }
        
        if(rank[parU] == rank[parV]) {
            par[parV] = parU;
            rank[parU]++;
        } else if(rank[parU] > rank[parV]) {
            par[parV] = parU;
        } else {
            par[parU] = parV;
        }
        return true;
    }
};


class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        DisjointSet dsu(n + 1);
        vector<vector<int>> graph(n + 1);
        
        for(auto& dislike : dislikes) {
            graph[dislike[0]].push_back(dislike[1]);
            graph[dislike[1]].push_back(dislike[0]);
        }
        
        for(int i = 1; i <= n; i++) {
            if(graph[i].size() == 0) {
                continue;
            }
            
            // First enemy acts as the representative for the opposite group
            int enemy = graph[i][0];
            
            // Group all other enemies together with the first enemy
            for(int j = 1; j < graph[i].size(); j++) {
                dsu.unionByRank(enemy, graph[i][j]);
            }
            
            // Check if the current person got grouped with their own enemy
            if(dsu.find(i) == dsu.find(enemy)) {
                return false;
            }
        }
        return true;
    }
};

//Approach 2- Graph Coloring

class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(n + 1);
        for (auto& dislike : dislikes) {
            graph[dislike[0]].push_back(dislike[1]);
            graph[dislike[1]].push_back(dislike[0]);
        }
        queue<int> q;
        vector<int> color(n + 1, -1);
        q.push(1);
        color[1] = 1;
        for (int i = 1; i <= n; i++) {
            if (color[i] == -1) {
                q.push(i);
                color[i] = 0;
            }
            while (q.size() > 0) {
                int u = q.front();
                q.pop();
                for (int v : graph[u]) {
                    if (color[v] == -1) {
                        color[v] = !color[u];
                        q.push(v);
                    } else {
                        if (color[v] == color[u]) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};





class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        DisjointSet dsu(n);
        for(auto edge:edges){
            dsu.unionByRank(edge[0],edge[1]);
        }
        vector<ll>count(n,0);
        for(int i=0;i<n;i++){
            count[dsu.find(i)]++;
        }
        ll ans =0;
        for(int i =0;i<n;i++){
            ans+=count[i]*(n-count[i]);
        }
        return ans/2;
    }
};

