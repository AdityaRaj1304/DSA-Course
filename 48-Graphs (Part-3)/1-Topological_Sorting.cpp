#include<bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    list<int>*l;
    bool isUndir;
public:
    Graph(int V, bool isUndir){
        this->V=V;
        l=new list<int>[V];
        this->isUndir=isUndir;
    }
    
    void addEdge(int u ,int v){
        l[u].push_back(v);
        if(isUndir){
            l[v].push_back(u);
        }
    }

    void topoHelper(int src , vector<bool>&vis , stack<int>&st){
        vis[src]=true;
        for(int v:l[src]){
            if(!vis[v]){
                topoHelper(v,vis,st);
            }
        }
        st.push(src);
    }

    void topoSort(){
        vector<bool>vis(V,false);
        stack<int>st;
        for(int i = 0;i<V;i++){
            if(!vis[i]){
                topoHelper(i,vis,st);
            }
        }
        while(!st.empty()){
            cout << st.top() << ",";
            st.pop();
        }
    }
};

int main(){
    Graph graph(6,false);
    graph.addEdge(5,0);
    graph.addEdge(4,0);
    graph.addEdge(5,2);
    graph.addEdge(4,1);
    graph.addEdge(2,3);
    graph.addEdge(3,1);
    graph.topoSort();
    return 0;
}