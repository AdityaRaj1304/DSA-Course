#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    vis[i][j]=true;
                }
            }
        }
        q.push({0,0});
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j]){
                    int val = INT_MAX;
                    if(i-1>=0){
                        val=min(val,mat[i-1][j]);
                        if(!vis[i][j]){
                            
                        }
                    }
                }
            }
        }
    }
};