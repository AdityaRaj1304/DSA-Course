#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);
        while(low<high){
            int mid = low+(high-low)/2;
            if(possible(nums,k,mid)){
                high=mid;
            }else{
                low=mid+1;
            }
        }
        return low;
    }

    bool possible(vector<int>& nums,int k , int maxSum){
        int currSum = 0;
        int subarr = 1;
        for(int i = 0 ; i<nums.size();i++){
            if(currSum + nums[i] <= maxSum){
                currSum+=nums[i];
            }else{
                subarr++;
                currSum=nums[i];
            }
        }
        return subarr<=k;
    }
};