#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dirGraph(vector<vector<int>>& prerequestites,
                  vector<vector<int>>& graph) {
        for (auto& edge : prerequestites) {
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
        }
    }
    bool dfs(vector<vector<int>>& graph, int src, vector<bool>& vis,
             vector<bool>& recPath) {
        vis[src] = true;
        recPath[src] = true;
        for (int v : graph[src]) {
            if (!vis[v]) {
                if (dfs(graph, v, vis, recPath)) {
                    return true;
                }
            } else {
                if (recPath[v]) {
                    return true;
                }
            }
        }
        recPath[src] = false;
        return false;
    }
    bool isCycle(vector<vector<int>>& graph, int V) {
        vector<bool> vis(V, false);
        vector<bool> recPath(V, false);
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (dfs(graph, i, vis, recPath)) {
                    return true;
                }
            }
        }
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        dirGraph(prerequisites, graph);
        if (isCycle(graph, numCourses)) {//Cycle Exist
            return false;
        }
        return true;
    }
};