#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dfs(vector<vector<int>>& grid, int row, int col,
            vector<vector<bool>>& vis) {
        int m = grid.size();
        int n = grid[0].size();
        if (row < 0 || col < 0 || row >= m || col >= n || vis[row][col] ||
            grid[row][col] == 0) {
            return 0;
        }
        vis[row][col] = true;
        return 1 + dfs(grid, row + 1, col, vis) + dfs(grid, row - 1, col, vis) +
               dfs(grid, row, col + 1, vis) + dfs(grid, row, col - 1, vis);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    int area = dfs(grid, i, j, vis);
                    ans = max(ans, area);
                }
            }
        }
        return ans;
    }
};