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

    bool dfs(int src , int par , vector<int>&depth){
        for(int v :l[src]){
            if(depth[v]==-1){
                depth[v]=depth[src]+1;
                if(!dfs(v,src,depth)){
                    return false;
                }
            }
            else if(v!=par){
                int length = abs(depth[src]-depth[v])+1;
                if(length%2==1){ //Odd length Cycle
                    return false;
                }
            }
        }
        return true;
    }
    
    bool isBipartile(){
        vector<int>depth(V,-1);
        for(int i = 0;i<V;i++){
            if(depth[i]==-1){
                depth[i]=0;
                if(!dfs(i,-1,depth)){
                    return false;
                }
            }
        }
        return true;
    }
};

int main(){
    Graph graph1(4);
    Graph graph2(5);
    graph1.addEdge(0,1);
    graph1.addEdge(0,2);
    graph1.addEdge(1,3);
    graph1.addEdge(2,3);
    cout << graph1.isBipartile() <<endl;
    graph2.addEdge(0,1);
    graph2.addEdge(0,2);
    graph2.addEdge(1,3);
    graph2.addEdge(2,4);
    graph2.addEdge(3,4);
    cout << graph2.isBipartile() <<endl;
    return 0;
}