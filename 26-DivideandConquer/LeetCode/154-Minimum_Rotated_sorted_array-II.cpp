#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        int st = 0 , end = nums.size()-1;
        while(st<end){
            if(nums[st]<nums[end]){
                return nums[st];
            }
            int mid = st+(end-st)/2;
            if(nums[st]==nums[mid]&&nums[mid]==nums[end]){
                st++;
                end--;
                continue;
            }
            if(nums[mid]>nums[end]){
                st=mid+1;
            }else{
                end=mid;
            }
        }
        return nums[st];
    }
};
int main(){
    vector<int>nums={2,2,2,0,2,2};
    Solution s;
    cout << s.findMin(nums);
}