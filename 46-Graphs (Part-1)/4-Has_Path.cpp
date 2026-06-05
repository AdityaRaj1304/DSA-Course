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


    bool hasPath_bfs(int src , int dest){
        queue<int>q;
        vector<bool>vis(V,false);
        vis[src]=true;
        q.push(src);
        while(q.size()>0){
            int u = q.front();
            if(u==dest){
                return true;
            }
            q.pop();
            list<int>neighbours = l[u];
            for(int v:neighbours){
                if(!vis[v]){
                    vis[v]=true;
                    q.push(v);
                }
            }
        }
        return false;
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
    //graph.print();
    cout << graph.hasPath_bfs(0,5);
    return 0;
}