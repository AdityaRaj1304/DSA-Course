#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>m;
        unordered_set<int>s;
        if(n<3){
            return nums;
        }
        int threshold = floor(n/3);
        for(int num:nums){
            if(s.count(num)){
                continue;
            }else{
                if(m.count(num)){
                    m[num]++;
                    if(m[num]>threshold){
                        s.insert(num);
                    }
                }else{
                    m[num]=1;
                }
            }
        }
        vector<int>ans(s.begin(),s.end());
        return ans;
    }
};
