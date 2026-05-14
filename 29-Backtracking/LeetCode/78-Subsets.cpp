#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>subset;
        printSubsets(nums,0,ans,subset);
        return ans;
    }
    void printSubsets(vector<int>&nums , int idx , vector<vector<int>>&ans , vector<int>&subset){
        if(idx==nums.size()){
            ans.push_back(subset);
            return;
        }
        int n = nums[idx];
        subset.push_back(n);
        printSubsets(nums,idx+1,ans,subset);
        subset.pop_back();
        printSubsets(nums,idx+1,ans,subset);
    }
};
int main(){
    vector<int>test={1,2,3};
    Solution s;
    vector<vector<int>> ans = s.subsets(test);
    for(int i = 0 ; i < ans.size();i++){
        for(int j = 0 ; j <ans[i].size();j++){
            cout << ans[i][j];
        }
        cout << endl;
    }
    return 0 ;
}