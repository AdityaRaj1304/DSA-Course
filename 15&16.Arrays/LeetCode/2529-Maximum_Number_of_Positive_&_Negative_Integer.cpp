#include<iostream>
#include<vector>
using namespace std ;
class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int pos = 0 , neg = 0 , ans = 0;
        int st = 0 , end = nums.size()-1 , n = nums.size();
        while(st<=end){
            int mid = st + (end-st)/2;
            if(nums[mid]>0){
                if(mid==0||nums[mid-1]<=0){
                    pos=n-mid;
                    break;
                }else{
                    end=mid-1;
                }
            }else{
                st = mid+1;
            }
        }
        int st_neg=0 , end_neg=n-1;
        while(st_neg<=end_neg){
            int mid = st_neg + (end_neg-st_neg)/2;
            if(nums[mid]<0){
                if(mid == n-1 || nums[mid+1]>=0){
                    neg=mid+1;
                    break;
                }else{
                    st_neg=mid+1;
                }
            }else{
                end_neg=mid-1;
            }
        }
        return max(pos,neg);
    }
};