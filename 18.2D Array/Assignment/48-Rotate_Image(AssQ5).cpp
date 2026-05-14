#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int st = 0 , end = matrix.size()-1;
        int rows = matrix.size(),cols=matrix[0].size();
        while(st<=end){
            for(int j = 0 ; j <cols;j++){
                swap(matrix[st][j],matrix[end][j]);
            }
            st++,end--;
        }
        for(int i = 0 ; i<rows;i++){
            for(int j = i;j<cols;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
    }
};
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int rows = matrix.size(),cols=matrix[0].size();
        for(int i = 0 ; i<rows;i++){
            for(int j = i+1;j<cols;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(int i = 0 ; i < rows;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};
