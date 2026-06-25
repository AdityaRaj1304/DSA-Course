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

    void calcIndegree(vector<int>&inDeg){
        for(int u=0;u<V;u++){
            for(int v:l[u]){
                inDeg[v]++;
            }
        }
    }

    void topoSort(){//Kahn's Algo
        vector<int>inDeg(V,0);
        calcIndegree(inDeg);
        queue<int>q;
        //Push Nodes with Indegree=0
        for(int i =0;i<V;i++){
            if(inDeg[i]==0){
                q.push(i);
            }
        }
        
        while(q.size()>0){
            int curr = q.front();
            q.pop();
            cout << curr << " ";
            for(int v:l[curr]){
                inDeg[v]--;
                if(inDeg[v]==0){//No pending dependencies
                    q.push(v);
                }
            }
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