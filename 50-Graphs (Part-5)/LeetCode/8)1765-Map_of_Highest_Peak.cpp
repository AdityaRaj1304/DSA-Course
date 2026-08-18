#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();
        vector<vector<int>>ans(m,vector<int>(n,-1));
        queue<pair<int,int>>q;
        for(int i =0;i<m;i++){
            for(int j =0;j<n;j++){
                if(isWater[i][j]==1){
                    q.push({i,j});
                    ans[i][j]=0;
                }
            }
        }
        while(q.size()>0){
            auto[r,c]=q.front();
            q.pop();
            if(r-1>=0 && ans[r-1][c]==-1){
                ans[r-1][c]=ans[r][c]+1;
                q.push({r-1,c});
            }
            if(r+1<m && ans[r+1][c]==-1){
                ans[r+1][c]=ans[r][c]+1;
                q.push({r+1,c});
            }
            if(c-1>=0 && ans[r][c-1]==-1){
                ans[r][c-1]=ans[r][c]+1;
                q.push({r,c-1});
            }
            if(c+1<n && ans[r][c+1]==-1){
                ans[r][c+1]=ans[r][c]+1;
                q.push({r,c+1});
            }
        }
        return ans;
    }
};


class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid.size();
        int ans = 0;
        queue<vector<int>>q;
        for(int i =0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]){
                    q.push({i,j,0});
                }
            }
        }
        vector<int>dx={-1,1,0,0};
        vector<int>dy={0,0,-1,1};
        while(q.size()>0){
            auto node =q.front();
            int r = node[0];
            int c = node[1];
            int dist = node[2];
            q.pop();
            for(int i =0;i<4;i++){
                int nr = r+dx[i];
                int nc = c+dy[i];
                if(nr>=0&&nr<m&&nc>=0&&nc<=n&&grid[nr][nc]==0){
                    q.push({r,c,dist+1});
                    grid[i][j]=1;
                }
            }
            ans=max(ans,dist);
        }
        return ans;
    }
};


