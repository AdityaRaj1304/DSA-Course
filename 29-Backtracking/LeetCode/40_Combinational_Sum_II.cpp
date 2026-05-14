#include<bits/stdc++.h>
using namespace std; 
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>comb;
        vector<vector<int>>ans;
        sort(candidates.begin(),candidates.end());
        solution(candidates,target,0,0,comb,ans);
        return ans;
    }
    void solution(vector<int>&candidates,int target,int idx , int sum , vector<int>&comb,vector<vector<int>>&ans){
        if(sum==target){
            ans.push_back(comb);
            return;
        }
        if(sum>target){
            return;
        }
        for(int i  = idx ;i<candidates.size();i++){
            if(i>idx && candidates[i]==candidates[i-1]){
                continue;
            }
        int num = candidates[i];
        comb.push_back(num);
        sum+=num;
        solution(candidates,target,i+1,sum,comb,ans);
        comb.pop_back();
        sum-=num;
        }
}
};
