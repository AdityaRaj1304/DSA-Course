#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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


class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(),courses.end(),[&](auto a ,auto b){
            if(a[1]==b[1]){
                return a[0]<b[0];
            }
            return a[1]<b[1];
        });
        int ans =0;
        int time =0;
        for(auto course:courses){
            time+=course[0];
            if(time>course[1]){
                return ans;
            }
            ans++;
        }
        return ans;
    }
};