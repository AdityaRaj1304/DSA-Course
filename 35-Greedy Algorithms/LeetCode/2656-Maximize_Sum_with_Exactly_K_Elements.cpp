#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int ans = (k*(2*(nums[n-1])+k-1))/2;
        return ans;
    }
};