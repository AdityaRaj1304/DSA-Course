#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
    int V;
    vector<vector<pair<int,int>>> adj;

    Graph(int n) : V(n), adj(n) {}

    void addEdge(int u, int v, int wt = 1, bool undirected = true) {
        adj[u].push_back({v, wt});
        if (undirected)
            adj[v].push_back({u, wt});
    }
};


vector<int> bellmanFord(vector<vector<int>>&edges,int src, int V){
    vector<int>dist(V,INT_MAX);
    dist[src]=0;
    for(int i =0;i<V-1;i++){
        for(auto &edge:edges){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            if(dist[u]!=INT_MAX && dist[u]+wt<dist[v]){
                dist[v]=dist[u]+wt;
            }
        }
    }

    //Check for negative cycle
    for(auto &edge:edges){
        int u =edge[0];
        int v = edge[1];
        int wt = edge[2];
            if(dist[u]!=INT_MAX && dist[u]+wt<dist[v]){
                return {-1};
            }
    }
    for(int d:dist){
        cout << d << " ";
    }
    cout << endl;
    return dist;
}


vector<int> bellmanFordAdj(vector<vector<pair<int,int>>>&graph,int src , int V){
    vector<int>dist(V,INT_MAX);
    dist[src]=0;
    for(int i =0;i<V-1;i++){
        for(int u=0;u<V;u++){
            if(dist[u]==INT_MAX){
                continue;
            }
            for(auto&[v,wt]:graph[u]){
                if(dist[u]+wt<dist[v]){
                    dist[v]=dist[u]+wt;
                }
            }
        }
    }

    //One Extra Cycle to detect negative weight
    for(int u=0;u<V;u++){
        if(dist[u]==INT_MAX){
            continue;
        }
        for(auto&[v,wt]:graph[u]){
            if(dist[u]+wt<dist[v]){
                return {-1};
            }
        }
    }
    for(int d:dist){
        cout << d << " ";
    }
    return dist;
}

int main(){
    int V = 5;

    vector<vector<int>> edges = {
        {0, 1, 6},
        {0, 2, 7},
        {1, 2, 8},
        {1, 3, 5},
        {1, 4, -4},
        {2, 3, -3},
        {2, 4, 9},
        {3, 1, -2},
        {4, 0, 2},
        {4, 3, 7}
    };
    bellmanFord(edges,0,5);

    vector<vector<pair<int,int>>> graph(V);
    graph[0].push_back({1, 6});
    graph[0].push_back({2, 7});

    graph[1].push_back({2, 8});
    graph[1].push_back({3, 5});
    graph[1].push_back({4, -4});

    graph[2].push_back({3, -3});
    graph[2].push_back({4, 9});

    graph[3].push_back({1, -2});

    graph[4].push_back({0, 2});
    graph[4].push_back({3, 7});

    bellmanFordAdj(graph,0,5);
    return 0;
}