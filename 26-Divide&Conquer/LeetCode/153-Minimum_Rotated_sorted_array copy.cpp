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
class Solution { // Simple & Effective
public:
    int findMin(vector<int>& nums) {
        int st = 0, end = nums.size() - 1;

        while (st < end) {
            // If already sorted
            if (nums[st] <= nums[end]) {
                return nums[st];
            }

            int mid = st + (end - st) / 2;

            // Minimum lies to the right
            if (nums[mid] > nums[end]) {
                st = mid + 1;
            }
            // Minimum lies to the left (including mid)
            else {
                end = mid;
            }
        }
        return nums[st];
    }
};
