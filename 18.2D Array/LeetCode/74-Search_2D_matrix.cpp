#include<iostream>
#include<vector>
using namespace std ;
class Solution { // (T.C. = O(n+m)
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size(),col = matrix[0].size();
        int i = row-1 , j = 0;
        while(i>=0 && j<col){
            if(matrix[i][j]==target){
                return true;
            }else if(matrix[i][j]>target){
                i--;
            }else{
                j++;
            }
        }
        return false;
    }
};
class Solution { //More Optimal Solution(T.C. = O(log(n*m))
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        int left = 0;
        int right = rows * cols - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            // Convert 1D index to 2D
            int row = mid / cols;
            int col = mid % cols;
            
            if (matrix[row][col] == target) {
                return true;
            } else if (matrix[row][col] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return false;
    }
};
