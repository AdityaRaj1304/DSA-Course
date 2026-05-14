#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isGood(vector<int>& nums) {
        int maxm = *max_element(nums.begin(),nums.end());
        int n = nums.size();
        if(n!=maxm+1){
            return false;
        }
        int freq[201]={0};
        for(int num:nums){
            freq[num]++;
            if(freq[num]==2 && num!=maxm){
                return false;
            }
        }
        if(freq[maxm]!=2){
            return false;
        }
        return true;
    }
};