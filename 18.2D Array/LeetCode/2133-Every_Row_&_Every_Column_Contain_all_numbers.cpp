#include<iostream>
#include<vector>
using namespace std ;
class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int>count(n);
        for(int i = 0 ; i < n ; i++){
            fill(count.begin(),count.end(),0);
            for(int j = 0 ; j < n ;j++){
                count[matrix[i][j]-1]++;
            }
            for(int k = 0 ; k<n;k++){
                if(count[k]==0){
                    return false;
                }
            }
        }
        for(int j = 0 ; j < n ; j++){
            fill(count.begin(),count.end(),0);
            for(int i = 0 ; i < n ;i++){
                count[matrix[i][j]-1]++;
            }
            for(int k = 0 ; k<n;k++){
                if(count[k]==0){
                    return false;
                }
            }
        }
        return true;
    }
};