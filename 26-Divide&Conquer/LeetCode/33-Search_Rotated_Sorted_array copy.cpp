#include<iostream>
#include<vector>
using namespace std;
class Solution { // My Approach(Quite Complex)
public:
    int search(vector<int>&arr , int st , int end){
        if(arr[st]<arr[end]){
            return st;
        }
        int mid = st+(end-st)/2;
        if(mid==st || mid ==end){
            if(arr[st]<arr[end]){
                return st;
            }else{
                return end;
            }
        }
        if(arr[mid]<arr[mid-1]&&arr[mid]<arr[mid+1]){
            return mid;
        }
        if(arr[mid-1]<=arr[mid]&&arr[mid+1]<arr[mid]){
            return mid+1;
        }
        if(arr[mid]>arr[st]){
            return search(arr,mid+1,end);
        }else{
            return search(arr,st,mid-1);
        }

    }
    int findMin(vector<int>& nums) {
        int idx= search(nums,0,nums.size()-1);
        return nums[idx];
    }
};
class Solution {//Simple & Effective Approach
public:
    int search(vector<int>&arr , int st , int end){
        int st = 0 , end =arr.size()-1;
        while(st<end){
            if(arr[st]<=arr[end]){
                return arr[st];
            }
            int mid = st + (end-st)/2;
            if(arr[mid]>arr[end]){
                st=mid+1;
            }else{
                end=mid;
            }
        }
        return arr[st];
        }
};