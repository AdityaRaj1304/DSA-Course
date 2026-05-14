#include<iostream>
#include<vector>
using namespace std ;
class Solution {
public:
    int xorBeauty(vector<int>& nums) {//Better Approach
        int ans = 0 ;
        for(int i = 0 ; i < nums.size() ; i++){
            ans = ans ^ nums[i];
        }
        return ans ;
    }
};
class Solution {
public:
    int xorBeauty(vector<int>& nums) {
        int a = 0 , b = 0;
        for(int i = 0 ; i < nums.size();i++){
            a = a | nums[i];
            b = b ^ nums[i];
        }
        return a & b;
    }
};