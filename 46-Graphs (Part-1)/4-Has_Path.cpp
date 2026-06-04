#include<bits/stdc++.h>
using namespace std;

class UndirectedGraph{
    int V;
    list<int>* l;
public:
    UndirectedGraph(int V){
        this->V=V;
        l = new list<int>[V];
    }

    void addEdge(int u, int v){ //(u---v)
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

    bool hasPathHelper(int src , int dest , vector<int>&vis){
        if(src == dest){
            return true;
        }
        vis[src]=true;
        list<int>neighbours = l[src];
        for(int v:neighbours){
            if(!vis[v]){
                if(hasPathHelper(v,dest,vis)){
                    return true;
                }
            }
        }
        return false;
    }

    bool hasPath(int src , int dest){
        vector<int>vis(V,false);
        return hasPathHelper(src,dest,vis);
    }
};

int main(){
    UndirectedGraph graph(7);
    graph.addEdge(0,1);
    graph.addEdge(0,2);
    graph.addEdge(1,3);
    graph.addEdge(2,4);
    graph.addEdge(3,5);
    graph.addEdge(4,5);
    graph.addEdge(5,6);
    graph.print();
    cout << graph.hasPath(0,6);
    return 0;
}