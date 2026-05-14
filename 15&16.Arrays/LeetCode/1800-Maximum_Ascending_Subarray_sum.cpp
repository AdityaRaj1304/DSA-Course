#include<iostream>
#include<algorithm>
#include<vector>
using namespace std ;
class Solution {
public:
    int maxAscendingSum(vector<int>& nums) { // T.C. = O(n^2)
        int maxsum= INT_MIN, currsum = 0;
        int n = nums.size();
        for(int start = 0 ; start<n;start++){
            currsum = nums[start];
            for(int end = start+1; end < n ; end++){
                if(nums[end]<=nums[end-1]){
                    break;
                }
                currsum+=nums[end];
            }
            maxsum=max(maxsum,currsum);
        }
        return maxsum ;
    }
};
// Optimised Solution
class Solution {
public:
    int maxAscendingSum(vector<int>& nums) { // T.C. = O(n) 
        int maxsum = nums[0];
        int currsum = nums[0];
        
        for(int i = 1; i < nums.size(); ++i) {
            if(nums[i] > nums[i - 1]) {
                currsum += nums[i];
            } else {
                currsum = nums[i];  // restart sum from current element
            }
            maxsum = max(maxsum, currsum);
        }
        
        return maxsum;
    }
};
