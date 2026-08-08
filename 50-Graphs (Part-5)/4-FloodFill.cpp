#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class Solution {
public:
    void dfs(int row, int col, int m, int n, vector<vector<int>>&image,vector<vector<bool>>&vis,int newColor, int orgColor){
        vis[row][col]=true;
        image[row][col]=newColor;

        //UP
        if(row-1>=0 && !vis[row-1][col] && image[row-1][col]==orgColor){
            dfs(row-1,col,m,n,image,vis,newColor,orgColor);
        }
        //DOWN
        if(row+1<m && !vis[row+1][col] && image[row+1][col]==orgColor){
            dfs(row+1,col,m,n,image,vis,newColor,orgColor);
        }
        //LEFT
        if(col-1>=0 && !vis[row][col-1] && image[row][col-1]==orgColor){
            dfs(row,col-1,m,n,image,vis,newColor,orgColor);
        }
        //RIGHT
        if(col+1<n && !vis[row][col+1] && image[row][col+1]==orgColor){
            dfs(row,col+1,m,n,image,vis,newColor,orgColor);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        dfs(sr,sc,m,n,image,vis,color,image[sr][sc]);
        return image;
    }
};