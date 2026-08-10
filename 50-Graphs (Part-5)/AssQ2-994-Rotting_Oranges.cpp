#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>q;
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        int fresh =0;
        for(int i =0;i<m;i++){
            for(int j =0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                    vis[i][j]=true;
                }else if(grid[i][j]==1){
                    fresh++;
                }
            }
        }
        if(fresh==0){
            return 0;
        }
        vector<int>dx={-1,1,0,0};
        vector<int>dy={0,0,-1,1};
        int rotten =0;
        int ans =0;
        while(q.size()>0){
            int sz = q.size();
            while(size--){
                auto[x,y]=q.front();
                q.pop();
                for(int i=0;i<4;i++){
                    x=x+dx[i];
                    y=y+dy[i];
                    if(x>=0&&&x<m&&y>=0&&y<n&&!vis[x][y]&&grid[x][y]==1){
                        vis[x][y]=true;
                        rotten++;
                        q.push({x,y});
                    }
                }
            }
            ans++;
        }
        return rotten==fresh ? ans:-1;
    }
};