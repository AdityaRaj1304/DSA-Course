#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class Solution {
public:  
    void dfs(int r , int c, int m , int n , vector<vector<int>>&image, vector<vector<bool>>&vis, int newColor, int orgColor){
        if(r<0 || r>=m || c<0 || c>=n || vis[r][c] || image[r][c]!=orgColor){
            return;
        }
        vis[r][c]=true;
        image[r][c]=newColor;
        dfs(r-1,c,m,n,image,vis,newColor,orgColor);
        dfs(r+1,c,m,n,image,vis,newColor,orgColor);
        dfs(r,c-1,m,n,image,vis,newColor,orgColor);
        dfs(r,c+1,m,n,image,vis,newColor,orgColor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        dfs(sr,sc,m,n,image,vis,color,image[sr][sc]);
        return image;
    }
};