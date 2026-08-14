#include <bits/stdc++.h>
using namespace std;
using ll = long long;


class Solution {
public:
    void bfs(vector<vector<int>>&grid,int r , int c){
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>>q;
        q.push({r,c});
        grid[r][c]=2;
        vector<int>dx={-1,1,0,0};
        vector<int>dy={0,0,-1,1};
        while(q.size()>0){
            auto[r,c]=q.front();
            q.pop();
            for(int i =0;i<4;i++){
                int nr = r+dx[i];
                int nc = c+dy[i];
                if(nr>=1&&nr<m-1&&nc>=1&&nc<n-1&&grid[nr][nc]==0){
                    grid[nr][nc]='2';
                    q.push({nr,nc});
                }
            }
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        int ans =0;
        int m = grid.size();
        int n = grid[0].size();
        for(int i =0;i<m;i++){
            for(int j =0;j<n;j++){
                if((i==0||i==m-1||j==0||j==n-1)&&grid[i][j]==0){
                    bfs(grid,i,j);
                }
            }
        }

        for(int i =1;i<m-1;i++){
            for(int j =1;j<n-1;j++){
                if(grid[i][j]==0){
                    ans++;
                    bfs(grid,i,j);
                }
            }
        }
        return ans;
    }
};


