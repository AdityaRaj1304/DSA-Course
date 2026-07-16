#include <bits/stdc++.h>
using namespace std;

class Graph{
public:
    int V;
    vector<vector<pair<int,int>>>adj;

    Graph(int V){
        this->V=V;
        adj.resize(V);
    }

    void addEdge(int u , int v,int wt){
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }

    int primsAlgo(int src){
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>key(V,INT_MAX);
        vector<bool>mst(V,false);
        key[src]=0;
        int ans = 0;
        pq.push({0,src});
        while(pq.size()>0){
            int u = pq.top().second;
            int wt = pq.top().first;
            pq.pop();
            if(!mst[u]){
                ans+=wt;
                mst[u]=true;
                for(auto&[v,wt]:adj[u]){
                    if(!mst[v]&&wt<key[v]){
                        key[v]=wt;
                        pq.push({key[v],v});
                    }
                }
            }
        }
        return ans;
    }
};

int main(){
    Graph graph(4);
    graph.addEdge(0,1,10);
    graph.addEdge(0,2,15);
    graph.addEdge(0,3,30);
    graph.addEdge(1,3,40);
    graph.addEdge(2,3,50);
    
    cout << graph.primsAlgo(0);
    return 0;
}