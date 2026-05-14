#include<iostream>
#include<vector>
using namespace std ;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int>num;
        int ans = 0 ;
        for(int i = 0 ; i < nums.size()-1 ; i++){
            for(int j = i+1 ; j<nums.size();j++){
                if(nums[i]&nums[j]==nums[i]){
                    num.push_back(nums[i]);
                }
            }
        }
    }
};