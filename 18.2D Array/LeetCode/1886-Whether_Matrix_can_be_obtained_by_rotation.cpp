#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> rotate(vector<vector<int>>& mat){
        for(int i = 0 ; i < mat.size();i++){
            for(int j = i+1 ; j < mat[0].size();j++){
                swap(mat[i][j],mat[j][i]);
            }
        }
        for(int i = 0 ; i < mat.size();i++){
            reverse(mat[i].begin(),mat[i].end());
        }
        return mat;
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        for(int i = 0 ; i < 4 ;i++){
        if(mat==target){
            return true;
        }
        mat = rotate(mat);
    }
    return false;
}
};
class Solution {//Wrong Approach
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        vector<int>v1,v2;
        int sr1=0,sr2=0,sc1=0,sc2=0,er1=mat.size()-1,er2=target.size()-1,ec1=mat[0].size()-1,ec2=target.size()-1;
        while(sr1<=er1&&sc1<=ec1){
            for(int j = sc1;j<=ec1;j++){
                v1.push_back(mat[sr1][j]);
            }
            for(int i = sr1+1;i<=er1;i++){
                v1.push_back(mat[i][ec1]);
            }
            for(int j = ec1-1;j>=sc1;j--){
                if(sr1==er1){
                    break;
                }
                v1.push_back(mat[er1][j]);
            }
            for(int i = er1-1;i>sr1;i--){
                if(ec1==sc1){
                    break;
                }
                v1.push_back(mat[i][sc1]);
            }
            sr1++,sc1++,ec1--,er1--;
        }
        while(sr2<=er2&&sc2<=ec2){
            for(int j = sc2;j<=ec2;j++){
                v2.push_back(target[sr2][j]);
            }
            for(int i = sr2+1;i<=er2;i++){
                v2.push_back(target[i][ec2]);
            }
            for(int j = ec2-1;j>=sc2;j--){
                if(sr2==er2){
                    break;
                }
                v2.push_back(target[er2][j]);
            }
            for(int i = er2-1;i>sr2;i--){
                if(ec2==sc2){
                    break;
                }
                v2.push_back(target[i][sc2]);
            }
            sr2++,sc2++,er2--,ec2--;
        }
        for(int i=0;i<v1.size();i++){
            if(v1[i]!=v2[i]){
                return false;
            }
        }
        return true;
    }
};