#include<bits/stdc++.h>
using namespace std; 

//Version 1
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>comb;
        sort(candidates.begin(),candidates.end());
        solution(candidates,target,0,0,comb,ans);
        return ans;
    }
    void solution(vector<int>&candidates,int target,int pos , int sum , vector<int>&comb,vector<vector<int>>&ans){
        if(sum==target){
            ans.push_back(comb);
            return;
        }
        if(sum>target){
            return;
        }
        for(int i = pos ;i<candidates.size();i++){
        int num = candidates[i];
        if(sum+num>target){
            break;
        }
        comb.push_back(num);
        sum+=num;
        solution(candidates,target,i,sum,comb,ans);
        comb.pop_back();
        sum-=num;
        }

    }
};

//Version 2
class Solution {
public:
    set<vector<int>>s;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>comb;
        vector<vector<int>>ans;
        getAllCombinations(candidates,target,0,0,comb,ans);
        return ans;
    }
    void getAllCombinations(vector<int>&cand,int target, int idx , int sum ,vector<int>&comb, vector<vector<int>>&ans){
        if(idx==cand.size() || sum>target){
            return ;
        }
        if(sum==target){
            if(s.find(comb)==s.end()){
                ans.push_back(comb);
                s.insert(comb);
            }
            return;
        }
        comb.push_back(cand[idx]);
        sum+=cand[idx];
        //single
        getAllCombinations(cand,target,idx+1,sum,comb,ans);
        //multiple
        getAllCombinations(cand,target,idx,sum,comb,ans);
        sum-=cand[idx];
        comb.pop_back();
        //exclusion
        getAllCombinations(cand,target,idx+1,sum,comb,ans);
    }
};