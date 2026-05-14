#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int s(vector<int>&arr,int st , int end, int tar){
        if(st>end){
            return -1;
        }
        int mid = st+(end-st)/2;
        if(arr[mid]==tar){
            return mid;
        }
        if(arr[st]<=arr[mid]){
            if(arr[st]<=tar && tar <= arr[mid]){
                return s(arr,st,mid-1,tar);
            }else{
                return s(arr,mid+1,end,tar);
            }
        }else{
            if(arr[mid]<=tar&& tar<=arr[end]){
                return s(arr,mid+1,end,tar);
            }else{
                return s(arr,st,mid-1,tar);
            }
        }
    }
    int search(vector<int>& nums, int target) {
        return s(nums,0,nums.size()-1,target);
    }
};