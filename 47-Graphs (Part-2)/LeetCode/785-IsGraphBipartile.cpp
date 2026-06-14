#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool graphColoring(vector<vector<int>>& graph, int u, vector<int>& color) {
        queue<int> q;
        q.push(u);
        color[u] = 0;
        while (q.size() > 0) {
            int curr = q.front();
            q.pop();
            for (int v : graph[curr]) {
                if (color[v] == -1) {
                    color[v] = !color[curr];
                    q.push(v);
                } else {
                    if (color[v] == color[curr]) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> color(V, -1);
        for (int i = 0; i < V; i++) {
            if (color[i] == -1) {
                if (!graphColoring(graph, i, color)) {
                    return false;
                }
            }
        }
        return true;
    }
};