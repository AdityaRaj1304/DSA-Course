#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<vector<int>>ans;
        vector<int>temp;
        for(int i = 0 ;i<n;i++){
            temp.push_back(nums[i]);
            if(temp.size()==3){
                if((temp[2]-temp[0])<=k){
                    ans.push_back(temp);
                    temp.clear();
                }else{
                    return {};
                }
            }
        }
        return ans;
    }
};