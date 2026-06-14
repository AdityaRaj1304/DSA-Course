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

    bool cycleHelperDirected(int src , vector<bool>&vis,vector<bool>&recPath){
        vis[src]=true;
        recPath[src]=true;
        for(int v : l[src]){
            if(!vis[v]){
                if(cycleHelperDirected(v,vis,recPath)){
                    return true;
                }
            }else{
                if(recPath[v]){
                    return true;
                }
            }
        }
        recPath[src]=false;
        return false;
    }

    bool isCycleDirected(){
        vector<bool>vis(V,false);
        vector<bool>recPath(V,false);
        for(int i = 0;i<V;i++){
            if(!vis[i]){
                if(cycleHelperDirected(i,vis,recPath)){
                    return true;
                }
            }
        }
        return false;
    }
};

int main(){
    Graph graph(5);
    graph.addEdge(1,0);
    graph.addEdge(0,2);
    graph.addEdge(2,3);
    //graph.print();
    cout << graph.isCycleDirected() << endl;
    graph.addEdge(3,0); // Back Edge
    cout << graph.isCycleDirected();
    return 0;
}
