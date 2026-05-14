#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>s;
        int n = nums2.size();
        vector<int>temp(n,0);
        int idx = n-1;
        temp[idx]=-1;
        s.push(nums2[idx]);
        for(idx=idx-1;idx>=0;idx--){
            int curr = nums2[idx];
            while(!s.empty()&&curr>=s.top()){
                s.pop();
            }
            if(s.empty()){
                temp[idx]=-1;
            }else{
                temp[idx]=s.top();
            }
            s.push(curr);
        }
        vector<int>ans;
        for(int i  = 0 ; i<nums1.size();i++){
            for(int j = 0 ;j<nums2.size();j++){
                if(nums1[i]==nums2[j]){
                    ans.push_back(temp[j]);
                }
            }
        }
        return ans;
    }
};