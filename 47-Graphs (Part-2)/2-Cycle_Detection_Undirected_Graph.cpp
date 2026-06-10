#include<bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    list<int>*l;
public:
    Graph(int V){
        this->V=V;
        l = new list<int>[V];
    }

    void addEdge(int u , int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void print(){
        for(int u = 0;u<V;u++){
            list<int>neighbours = l[u];
            cout << u <<": " ;
            for(int&v:neighbours){
                cout << v << " ";
            }
            cout << endl;
        }
    }

    bool cycleHelperUndirected(int src , int parent , vector<bool>&vis){
        vis[src]=true;
        for(int v : l[src]){
            if(!vis[v]){
                if(cycleHelperUndirected(v,src,vis)){
                    return true;
                }
            }else{
                if(v!=parent){
                    return true;
                }
            }
        }
        return false;
    }

    bool isCycleUndirected(){
        vector<bool>vis(V,false);
        return cycleHelperUndirected(0,-1,vis);
    }
};

int main(){
    Graph graph(5);
    graph.addEdge(1,0);
    graph.addEdge(1,2);
    graph.addEdge(0,3);
    graph.addEdge(3,4);
    //graph.print();
    cout << graph.isCycleUndirected() << endl;
    graph.addEdge(0,2);
    cout << graph.isCycleUndirected() << endl;
    return 0;
}
