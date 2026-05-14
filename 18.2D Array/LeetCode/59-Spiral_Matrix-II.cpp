#include<iostream>
#include<vector>
using namespace std ;
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>ans(n,vector<int>(n,0));
        int srow= 0 , scol = 0 , erow = n-1 , ecol = n-1;
        int num = 1;
        while(srow<=erow && scol <=ecol){
            for(int j = scol ; j<=ecol ;j++){
                ans[srow][j]=num++;
            }
            for(int i = srow+1;i<=erow;i++){
                ans[i][ecol]=num++;
            }
            for(int j = ecol-1;j>=scol;j--){
                if(srow==erow){
                    break;
                }
                ans[erow][j]=num++;
            }
            for(int i = erow-1 ; i>srow;i--){
                if(ecol==scol){
                    break;
                }
                ans[i][scol]=num++;
            }
            srow++,scol++,erow--,ecol--;
        }
        return ans;
    }
};