#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class Solution {
public:
    int bfs(vector<vector<int>>& graph, int n, int src) {
        vector<int> dist(n, -1);
        queue<pair<int, int>> q;
        q.push({src, -1});
        dist[src]=0;
        int len = INT_MAX;
        while (q.size() > 0) {
            auto [u, par] = q.front();
            q.pop();
            for (int v : graph[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push({v, u});
                } else if (v != par) {
                    len = min(len, dist[v] + dist[u] + 1);
                }
            }
        }
        return len;
    }
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        vector<int> dist(n, 0);
        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            int cycleLength = bfs(graph, n, i);
            if (cycleLength != INT_MAX) {
                ans = min(ans, cycleLength);
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};


