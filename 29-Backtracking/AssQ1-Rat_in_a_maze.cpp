#include<bits/stdc++.h>
using namespace std;
// Version 1
void path(vector<vector<int>>&maze,int row ,int col ,int n, string ans){
    if(row>=n||col>=n||row<0||col<0||maze[row][col]==0||maze[row][col]==-1){
        return ;
    }
    if(row==n-1&&col==n-1){
        cout << ans << "\n";
        return ;
    }
    maze[row][col]=-1;
    path(maze,row-1,col,n,ans+"U");
    path(maze,row+1,col,n,ans+"D");
    path(maze,row,col-1,n,ans+"L");
    path(maze,row,col+1,n,ans+"R");
    maze[row][col]=1;
}
void mazeSolver(vector<vector<int>>&maze,int row , int col , int n ){
    string ans = "";
    path(maze,0,0,n,ans);
}


// Version 2
void solveMaze(vector<vector<int>>&maze,int r , int c , int n , string ans , vector<vector<bool>>&vis){
    if(r==n-1 && c==n-1 && maze[r][c]==1){
        cout << ans << "\n";
        return;
    }

    //Up
    if(r-1>=0 && !vis[r-1][c] && maze[r-1][c]==1){
        vis[r-1][c]=true;
        solveMaze(maze,r-1,c,n,ans+"U",vis);
        vis[r-1][c]=false;
    }

    //Down
    if(r+1<n && !vis[r+1][c] && maze[r+1][c]==1){
        vis[r+1][c]=true;
        solveMaze(maze,r+1,c,n,ans+"D",vis);
        vis[r+1][c]=false;
    }

    //Left
    if(c-1>=0 && !vis[r][c-1] && maze[r][c-1]==1){
        vis[r][c-1]=true;
        solveMaze(maze,r,c-1,n,ans+"L",vis);
        vis[r][c-1]=false;
    }

    //Right
    if(c+1<n && !vis[r][c+1] && maze[r][c+1]==1){
        vis[r][c+1]=true;
        solveMaze(maze,r,c+1,n,ans+"R",vis);
        vis[r][c+1]=false;
    }
}
void ratMaze(vector<vector<int>>&maze,int row ,int col,int n){
    string path ="";
    vector<vector<bool>>vis(n,(vector<bool>(n,false)));
    if(maze[row][col]==1){
        solveMaze(maze,0,0,maze.size(),path,vis);
    }
    
}


int main(){
     vector<vector<int>>maze = {{ 1, 0, 0, 0 },
                                { 1, 1, 0, 1 },
                                { 1, 1, 0, 0 },
                                { 0, 1, 1, 1 } };
    mazeSolver(maze,0,0,maze.size());
    cout << endl;
    ratMaze(maze,0,0,maze.size());
}
