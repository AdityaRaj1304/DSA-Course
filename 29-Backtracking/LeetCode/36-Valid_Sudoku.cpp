#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool ans = true;
        for(int i =0 ;i<9;i++){
            for(int j =0;j<9;j++){
                if(board[i][j]!='.'){
                    char digit = board[i][j];
                    ans=isSafe(board,i,j,digit);
                }
                if(ans==false){
                    return false;
                }
            }
        }
        return ans;
    }
    bool isSafe(vector<vector<char>>&board,int row , int col,char digit){
        for(int i =0 ;i<9;i++){
            if(i!=row && board[i][col]==digit){
                return false;
            }
        }
        for(int j =0 ;j<9;j++){
            if(j!=col && board[row][j]==digit){
                return false;
            }
        }
        int startRow=(row/3)*3 , startCol=(col/3)*3;
        for(int i = startRow;i<startRow+3;i++){
            for(int j = startCol;j<startCol+3;j++){
                if((i!=row || j!=col) && board[i][j]==digit){
                    return false;
                }
            }
        }
        return true;
    }
};