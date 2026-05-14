#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>>vec(m,vector<int>(n));
        if(m*n !=original.size()){
            return {};
        }
        int idx=0;
            for(int i = 0;i<m;i++){
                for(int j = 0 ; j < n;j++){
                    vec[i][j]=original[idx++];
                }
            }
        return vec;
    }
};