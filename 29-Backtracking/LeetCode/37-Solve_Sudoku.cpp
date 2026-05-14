#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        sudokuSolver(board,0,0);
    }
    bool sudokuSolver(vector<vector<char>>& board,int row ,int col){
        if(row==9){
            return true;
        }
        int nextRow=row;
        int nextCol=col+1;
        if(col+1==9){
            nextRow=row+1;
            nextCol=0;
        }
        if(board[row][col]!='.'){
            return sudokuSolver(board,nextRow,nextCol);
        }
        for(char digit =1 ; digit<=9;digit++){
            if(isSafe(board,row,col,digit)){
                board[row][col]=digit;
                if(sudokuSolver(board,nextRow,nextCol)){
                    return true;
                }
                board[row][col]='.';
            }
        }
        return false;
    }

    bool isSafe(vector<vector<char>>& board,int row , int col , char digit){
        for(int i = 0 ;i<9;i++){
            if(board[i][col]==digit){
                return false;
            }
        }
        for(int j = 0 ;j<9;j++){
            if(board[row][j]==digit){
                return false;
            }
        }
        int sR=(row/3)*3 , sC=(col/3)*3;
        for(int i = sR;i<sR+3;i++){
            for(int j = sC;j<sC+3;j++){
                if(board[i][j]==digit){
                    return false;
                }
            }
        }
        return true;
    }
};