#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dirGraph(vector<vector<int>>& prerequestites,
                  vector<vector<int>>& graph) {
        for (auto& edge : prerequestites) {
            int u = edge[0];
            int v = edge[1];
            graph[v].push_back(u);
        }
    }
    bool isCycle(vector<vector<int>>& graph, int src, vector<bool>& vis,
                    vector<bool>& recPath, stack<int>& s) {
        vis[src] = true;
        recPath[src] = true;
        for (int v : graph[src]) {
            if (!vis[v]) {
                if (isCycle(graph, v, vis, recPath, s)) {
                    return true;
                }
            } else {
                if (recPath[v]) {
                    return true;
                }
            }
        }
        recPath[src] = false;
        s.push(src);
        return false;
    }
    bool topoSort(vector<vector<int>>& graph, int V, stack<int>& s) {
        vector<bool> vis(V, false);
        vector<bool> recPath(V, false);
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (isCycle(graph, i, vis, recPath, s)) { //Cyle Exist
                    return true;
                }
            }
        }
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        dirGraph(prerequisites, graph);
        stack<int> s;
        if (topoSort(graph, numCourses, s)) { //Cyle Exist
            return {};
        }
        vector<int> ans;
        while (!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};