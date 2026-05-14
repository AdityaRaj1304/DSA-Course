#include<bits\stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>comb;
        solution(n,k,1,ans,comb);
        return ans;
    }
    void solution(int n , int k , int num , vector<vector<int>>&ans,vector<int>&comb){
        if(comb.size()==k){
            ans.push_back(comb);
            return;
        }
        for(int i = num;i<=n;i++){
        comb.push_back(i);
        solution(n,k,i+1,ans,comb);
        comb.pop_back();
        }

    }
};