#include<bits./stdc++.h>
using namespace std;

void printBoard(vector<vector<char>>&board , int n ){
    for(int i = 0 ; i<n;i++){
        for(int  j = 0 ; j<n;j++){
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "-----------------------\n";
}
bool isSafe(vector<vector<char>>&board,int row , int col){
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

int nQueens(vector<vector<char>>&board,int row ){
    int n = board.size();
    int count = 0;
    if(row==n){
        printBoard(board,n);
        return 1;
    }
    for(int j = 0 ; j<n;j++){//cols
        if(isSafe(board,row,j)){
            board[row][j]='Q';
            count+=nQueens(board,row+1);
            board[row][j]='.';
        }
    }
    return count;
}
int main(){
    int n  =1;
    vector<vector<char>>board;
    for(int i = 0 ; i< n;i++){
        vector<char>newRow;
        for(int j =0;j<n;j++){
            newRow.push_back('.');
        }
        board.push_back(newRow);
    }
    int count = nQueens(board,0);
    cout << "Count: " << count;
    return 0;
}