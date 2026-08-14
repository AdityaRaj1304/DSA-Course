#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class Solution {
public:
    void bfs(vector<vector<char>>&grid,int r , int c){
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>>q;
        q.push({r,c});
        grid[r][c]='2';
        vector<int>dx={-1,1,0,0};
        vector<int>dy={0,0,-1,1};
        while(q.size()>0){
            auto[r,c]=q.front();
            q.pop();
            for(int i =0;i<4;i++){
                int nr = r+dx[i];
                int nc = c+dy[i];
                if(nr>=0&&nr<m&&nc>=0&&nc<n&&grid[nr][nc]=='1'){
                    grid[nr][nc]='2';
                    q.push({nr,nc});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans =0;
        int m = grid.size();
        int n = grid[0].size();
        for(int i =0;i<m;i++){
            for(int j =0;j<n;j++){
                if(grid[i][j]=='1'){
                    ans++;
                    bfs(grid,i,j);
                }
            }
        }
        return ans;
    }
};


class Solution {
public:
    int slidingWindow(vector<int>&nums,int goal){
        int ans =0;
        int left = 0;
        int sum =0;
        for(int right = 0;right<nums.size();right++){
            sum+=nums[right];
            while(sum>goal){
                sum-=nums[left];
                left++;
            }
            ans+=right-left+1;
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return slidingWindow(nums,goal)-slidingWindow(nums,goal-1);
    }
};