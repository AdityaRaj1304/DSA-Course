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

    bool isBipartile(){ // Uses Two Vectors - vis and color
        queue<int>q;
        vector<bool>vis(V,false);
        vector<int>color(V,-1);
        q.push(0);
        color[0]=0;
        vis[0]=0;
        while(q.size()>0){
            int curr = q.front();
            q.pop();
            list<int>neigh = l[curr];
            for(int v:neigh){
                if(!vis[v]){
                    vis[v]=true;
                    color[v]= !color[curr];
                    q.push(v);
                }else{
                    if(color[v]==color[curr]){
                        return false;
                    }
                }
            }
        }
        return true;
    }

    bool Bipartile(){ // Use Single Vector - color
        queue<int>q;
        vector<int>color(V,-1);
        q.push(0);
        color[0]=0;
        while(q.size()>0){
            int curr = q.front();
            q.pop();
            for(int v:l[curr]){
                if(color[v]==-1){
                    color[v]= !color[curr];
                    q.push(v);
                }else{
                    if(color[v]==color[curr]){
                        return false;
                    }
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