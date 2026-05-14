#include<iostream>
#include<vector>
using namespace std;
class Solution { // Not Opitmial T.C. = O(n^2)
public:
    int maxProduct(vector<int>& nums) {
        int max_product = INT_MIN ;
        for(int st = 0 ; st < nums.size();st++){
            int curr_product = 1;
            for(int end = st ; end < nums.size() ; end++){
                curr_product *= nums[end];
                max_product=max(max_product,curr_product);
            }
        }
        return max_product;
    }
};
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
    }
};