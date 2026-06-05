#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        queue<int>q;
        vector<bool>vis(n,false);
        q.push(0);
        vis[0]=true;
        while(q.size()>0){
            int u = q.front();
            q.pop();
            for(int v:rooms[u]){
                if(!vis[v]){
                    vis[v]=true;
                    q.push(v);
                }
            }
        }
        for(bool i:vis){
            if(!i){
                return false;
            }
        }
        return true;
    }
};