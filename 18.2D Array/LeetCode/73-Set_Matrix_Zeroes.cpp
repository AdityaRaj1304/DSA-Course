#include<iostream>
#include<vector>
using namespace std ;
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int>row(200,0),col(200,0);
        for(int i = 0 ; i < matrix.size();i++){
            for(int j = 0 ; j < matrix[0].size();j++){
                if(matrix[i][j]==0){
                    row[i]++;
                    col[j]++;
                }
            }
        }
        for(int i = 0 ; i < matrix.size();i++){
            if(row[i]!=0){
                fill(matrix[i].begin(),matrix[i].end(),0);
            }
        }
        for(int j = 0 ; j < matrix[0].size();j++){
            if(col[j]!=0){
                for(int i = 0 ; i < matrix.size();i++){
                    matrix[i][j]=0;
                }
            }
        }
    }
};