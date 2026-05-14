#include<bits.\stdc++.h>
using namespace std;
class Solution {
public:
    int totalNQueens(int n) {
        vector<string>board(n,string(n,'.'));
        int ans = nQueens(board,0);
        return ans;

    }
    int nQueens(vector<string>&board,int row){
        int n =board.size();
        int count = 0;
        if(row==n){
            return 1;
        }
        for(int j = 0 ; j<n;j++){
            if(isSafe(board,row,j)){
                board[row][j]='Q';
                count+=nQueens(board,row+1);
                board[row][j]='.';
            }
        }
        return count;
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