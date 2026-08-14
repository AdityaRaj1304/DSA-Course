#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>>q;
        int fresh =0;
        for(int i =0;i<m;i++){
            for(int j =0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
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
            bool valid = false;
            while(sz--){
                auto[u,v]=q.front();
                q.pop();
                for(int i=0;i<4;i++){
                    int x=u+dx[i];
                    int y=v+dy[i];
                    if(x>=0&&x<m&&y>=0&&y<n&&grid[x][y]==1){
                        grid[x][y]=2;
                        rotten++;
                        q.push({x,y});
                        valid=true;
                    }
                }
            }
            if(valid){
                ans++;
            }
        }
        return rotten==fresh ? ans:-1;
    }
};