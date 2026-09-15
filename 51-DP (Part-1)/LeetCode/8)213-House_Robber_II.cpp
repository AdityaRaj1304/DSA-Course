#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class Solution { //Best Solution TC=O(n) , SC = O(1)
public:
    int helper(vector<int>&nums,int st , int end){
        int prev2=0;
        int prev1=0;
        for(int i =st;i<end;i++){
            int curr = max(prev1,prev2+nums[i]);
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        return max(helper(nums,0,n-1),helper(nums,1,n));
    }
};
