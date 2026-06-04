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

    void dfshelper(int u , vector<bool>&vis){
        vis[u]=true;
        cout << u << " ";

        list<int>neighbours = l[u];
        for(int v: neighbours){
            if(!vis[v]){
                dfshelper(v,vis);
            }
        }
    }

    void dfs(){
        vector<bool>vis(V,0);
        dfshelper(0,vis);
        cout << endl;
    }

    void dfs_stack(){
        vector<bool>vis(V,false);
        stack<int>st;
        st.push(0);
        
        while(!st.empty()){
            int u =st.top();
            st.pop();

            if(vis[u]){
                continue;
            }

            vis[u]=true;
            cout << u << " ";

            list<int>neighbours = l[u];
            for(int& v:neighbours){
                if(!vis[v]){
                    st.push(v);
                }
            }
        }
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
    cout << "DFS(Recursion): ";
    graph.dfs();
    cout << "DFS(Stack): ";
    graph.dfs_stack();
    return 0;
}