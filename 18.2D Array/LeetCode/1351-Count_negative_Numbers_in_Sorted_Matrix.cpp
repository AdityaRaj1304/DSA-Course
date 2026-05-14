#include<iostream>
#include<vector>
using namespace std ;
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count = 0 , cols = grid[0].size();
        for(int i = 0 ; i < grid.size();i++){
            int st = 0 , end = cols-1;
            if(grid[i][0]<0){
                count+=cols;
                continue;
            }
            while(st<=end){
                int mid = st + (end-st)/2;
                if(grid[i][mid]<0){
                    if(mid==0||grid[i][mid-1]>=0){
                        count+=cols-mid;
                        break;
                    }else{
                        end=mid-1;
                    }
                }
                else if (grid[i][mid]>=0){
                        st= mid+1;
                }
        }}
        return count;
    }
};