#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int minCostConnect(vector<vector<int>>&points){
    int V =points.size();
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    vector<bool>mst(V,false);
    int src = 0;
    int ans = 0;
    pq.push({0,src});
    while(pq.size()>0){
        int u = pq.top().second;
        int cost = pq.top().first;
        pq.pop();
        if(!mst[u]){
            ans+=cost;
            mst[u]=true;
            for(int v=0;v<V;v++){
                if(u!=v && !mst[v]){
                    int wt = abs(points[u][0]-points[v][0])+abs(points[u][1]-points[v][1]);
                    pq.push({wt,v});
                }
            }
        }
    }
    return ans;
}

int main(){
    vector<vector<int>>points={{3,12},{-2,5},{-4,1}};
    cout << minCostConnect(points);
    return 0;
}