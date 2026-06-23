#include <bits/stdc++.h>
using namespace std;

void dirGraph(vector<vector<int>>& prerequestites, vector<vector<int>>& graph) {
    for (auto& edge : prerequestites) {
        int u = edge[0];
        int v = edge[1];
        graph[u].push_back(v);
    }
}

bool dfs(vector<vector<int>>&graph,int src , vector<bool>&vis,vector<bool>&rec){
    vis[src]=true;
    rec[src]=true;
    for(int v:graph[src]){
        if(!vis[v]){
            if(dfs(graph,v,vis,rec)){
                return true;
            }else{
                if(rec[v]){
                    return true;
                }
            }
        }
        
    }
    return false;
}

bool isCycle(vector<vector<int>>graph,int V){
    vector<bool>vis(V,false);
    vector<bool>rec(V,false);
    for(int i = 0;i<V;i++){
        if(!vis[i]){
            if(dfs(graph,i,vis,rec)){//Cycle Exist
                return false;
            }
        }
    }
    return true;
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites){
    int V = numCourses ;
    vector<vector<int>> graph(numCourses);
    dirGraph(prerequisites, graph);
    if (isCycle(graph, numCourses)) {//Cycle Exist
        return false;
    }
    return true;
}


int main(){
    int numCourses = 2;
    vector<vector<int>>courses={{1,0}};
    cout << canFinish(numCourses,courses);
}