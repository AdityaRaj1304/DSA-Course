#include<iostream>
#include<vector>
using namespace std ;
class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int total = 0;
        int ans = 0;
        for(int num :nums){
            total+=num;
        }
        int left = 0 , right =0;
        for(int i = 0 ;i<nums.size()-1;i++){
            left+=nums[i];
            right = total-left;
            if(abs(left-right)%2==0){
                ans++;
            }
        }
        return ans;
    }
};