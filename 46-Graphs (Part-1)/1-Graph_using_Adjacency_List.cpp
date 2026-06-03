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
};


class DirectedGraph{
    int V;
    list<int>* l;
public:
    DirectedGraph(int V){
        this->V=V;
        l = new list<int>[V];
    }

    void addEdge(int u, int v){ //(u---v)
        l[u].push_back(v);
    }

    void print(){
        for(int u = 0;u<V;u++){
            list<int>neighbours = l[u];
            cout << u <<": " ;
            for(int& v:neighbours){
                cout << v << " ";
            }
            cout << endl;
        }
    }
};

class WeightedGraph{
    int V;
    list<pair<int,int>>* l;
public:
    WeightedGraph(int V){
        this->V=V;
        l = new list<pair<int,int>>[V];
    }

    void addEdge(int u, int v,int w){ //(u--w--v)
        l[u].push_back({v,w});
        l[v].push_back({u,w});
    }

    void print(){
        for(int u = 0;u<V;u++){
            list<pair<int,int>>neighbours = l[u];
            cout << u <<": " ;
            for(auto &v:neighbours){
                cout << "(" << v.first << "," << v.second << ")";
            }
            cout << endl;
        }
    }
};

int main(){
    UndirectedGraph graph(5);
    graph.addEdge(0,1);
    graph.addEdge(1,2);
    graph.addEdge(2,3);
    graph.addEdge(1,3);
    graph.addEdge(2,4);
    graph.print();
    cout << endl;
    DirectedGraph graph2(4);
    graph2.addEdge(0,1);
    graph2.addEdge(1,0);
    graph2.addEdge(1,2);
    graph2.addEdge(2,3);
    graph2.addEdge(3,1);
    graph2.print();
    cout << endl;
    WeightedGraph graph3(5);
    graph3.addEdge(0,1,5);
    graph3.addEdge(1,2,1);
    graph3.addEdge(2,4,2);
    graph3.addEdge(2,3,1);
    graph3.addEdge(1,3,3);
    graph3.print();
    return 0;
}