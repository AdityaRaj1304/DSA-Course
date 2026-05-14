#include<bits./stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans; 
        vector<string> board(n, string(n, '.'));
        nQueens(ans,board,0);
        return ans;
    }
    void nQueens(vector<vector<string>>&ans,vector<string>&board,int row ){
    int n = board.size();
    if(row==n){
        ans.push_back(board);
        return;
    }
    for(int j = 0 ; j<n;j++){//cols
        if(isSafe(board,row,j)){
            board[row][j]='Q';
            nQueens(ans,board,row+1);
            board[row][j]='.';
        }
    }
}
    bool isSafe(vector<string>&board,int row , int col){
    int n  = board.size();
    for(int j = 0 ; j<n;j++){//Horizontal
        if(board[row][j]=='Q'){
            return false;
        }
    }
    for(int i =0 ; i< row;i++){//Vertical
        if(board[i][col]=='Q'){
            return false;
        }
    }
    for(int i = row , j = col ; i>=0 &&j>=0 ;i-- ,j--){//Diagonal Left
        if(board[i][j]=='Q'){
            return false;
        }
    }
    for(int i = row , j = col ; i>=0 &&j<n ;i-- ,j++){//Diagonal Right
        if(board[i][j]=='Q'){
            return false;
        }
    }
    return true; 
}
};
