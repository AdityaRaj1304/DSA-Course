#include<bits.\stdc++.h>
using namespace std;
class Solution { // Time Limit Exceeded on LeetCode since it needed to be solved using DP
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(),n=obstacleGrid[0].size();
        int ans = ways(obstacleGrid,0,0,m,n);
        return ans;
    }
    int ways(vector<vector<int>>grid,int r , int c , int m , int n){
        if(r>=m||c>=n){
            return 0;
        }
        if(grid[r][c]==1){
            return 0;
        }
        if(r==m-1&&c==n-1){
            return 1;
        }
        int val1=ways(grid,r,c+1,m,n);
        int val2=ways(grid,r+1,c,m,n);
        return val1+val2;
    }
};