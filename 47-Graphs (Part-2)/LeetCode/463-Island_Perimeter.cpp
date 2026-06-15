#include<bits/stdc++.h>
using namespace std;


class Solution { //Slightly Optimized - 2 less fxn calls
public:
    bool helper(vector<vector<int>>& grid, int row, int col) {
        int m = grid.size();
        int n = grid[0].size();
        if (row < 0 || col < 0 || row >= m || col >= n || grid[row][col] == 0) {
            return false;
        }
        return true;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if(grid[i][j]==1){
                    ans+=4;
                    if(i>0 && helper(grid,i-1,j)){
                        ans-=2;
                    }
                    if(j>0 && helper(grid,i,j-1)){
                        ans-=2;
                    }
                }
            }
        }
        return ans;
    }
};


class Solution {
public:
    bool helper(vector<vector<int>>& grid, int row, int col) {
        int m = grid.size();
        int n = grid[0].size();
        if (row < 0 || col < 0 || row >= m || col >= n || grid[row][col] == 0) {
            return false;
        }
        return true;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if(grid[i][j]==1){
                    ans+=4;
                    if(helper(grid,i+1,j)){
                        ans--;
                    }
                    if(helper(grid,i-1,j)){
                        ans--;
                    }
                    if(helper(grid,i,j+1)){
                        ans--;
                    }
                    if(helper(grid,i,j-1)){
                        ans--;
                    }
                }
            }
        }
        return ans;
    }
};