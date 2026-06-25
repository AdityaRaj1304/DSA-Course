#include<bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    list<int>*l;
    bool isUndir ;
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

    void calcIndegree(vector<int>&inDeg){
        for(int u =0;u<V;u++){
            for(int v:l[u]){
                inDeg[v]++;
            }
        }
    }

    int isCyleHelper(){
        vector<int>inDeg(V,0);
        calcIndegree(inDeg);
        queue<int>q;
        for(int i =0;i<V;i++){
            if(inDeg[i]==0){
                q.push(i);
            }
        }
        int nodes = 0;
        while(q.size()>0){
            int curr = q.front();
            q.pop();
            nodes++;
            for(int v:l[curr]){
                inDeg[v]--;
                if(inDeg[v]==0){
                    q.push(v);
                }
            }
        }
        return nodes;
    }

    void isCycle(){
        int nodes =isCyleHelper();
        if(nodes==V){
            cout<<"Acyclic Graph\n";
        }else{
            cout << "Cyclic Graph\n";
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
    graph.isCycle();
    Graph graph2(5,false);
    graph2.addEdge(1,0);
    graph2.addEdge(0,2);
    graph2.addEdge(2,3);
    graph2.addEdge(3,0); 
    graph2.isCycle();
    return 0;
}