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

    void pathHelper(int src , int dest , vector<bool>&vis , string& path){
        if(src == dest){
            cout << path << dest << "\n";
        }
        vis[src] = true;
        path += to_string(src);
        for(int v:l[src]){
            if(!vis[v]){
                pathHelper(v,dest,vis,path);
            }
        }
        path.pop_back();
        vis[src]=false;
    }

    void printAllPaths(int src ,int dest){
        vector<bool>vis(V,false);
        string path = "";
        pathHelper(src,dest,vis,path);
    }
};

int main(){
    Graph graph(6);
    graph.addEdge(5,0);
    graph.addEdge(5,2);
    graph.addEdge(4,0);
    graph.addEdge(0,3);
    graph.addEdge(4,1);
    graph.addEdge(2,3);
    graph.addEdge(3,1);
    graph.printAllPaths(5,1);
    return 0;
}