#include<bits/stdc++.h>
using namespace std;
// class Solution { // Wrong Approach(Edge Cases Failed)
// public:
//     vector<vector<int>> subsetsWithDup(vector<int>& nums) {
//         vector<vector<int>>ans;
//         vector<int>subset;
//         printSubsets(nums,0,ans,subset);
//         sort(ans.begin(),ans.end());
//         vector<int>indices;
//         for(int i = 1 ; i < ans.size();i++){
//             if(ans[i]==ans[i-1]){
//                 indices.push_back(i);
//             }1
//         }
//         for(int i =0 ; i<indices.size();i++){
//             ans.erase(ans.begin()+i+indices[i]);
//         }
//         return ans;
//     }
//     void printSubsets(vector<int>&nums , int idx , vector<vector<int>>&ans , vector<int>&subset){
//         if(idx==nums.size()){
//             ans.push_back(subset);
//             return;
//         }
//         int n = nums[idx];
//         subset.push_back(n);
//         printSubsets(nums,idx+1,ans,subset);
//         subset.pop_back();
//         printSubsets(nums,idx+1,ans,subset);
//     }
// };
int main(){
    return 0 ;
}