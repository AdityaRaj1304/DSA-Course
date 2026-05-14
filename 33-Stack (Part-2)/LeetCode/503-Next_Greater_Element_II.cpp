#include<bits/stdc++.h>
using namespace std; 

// Method - 1 
class Solution { 
public:
    vector<int> nextGreaterElements(vector<int>& nums) { // Not the Most Optimal Solution 
        stack<int>s;
        int n = nums.size();
        vector<int>ans(n,0);
        for(int i = n-1;i>=0;i--){
            int curr = nums[i];
            while(!s.empty()&&curr>=s.top()){
                s.pop();
            }
            s.push(curr);
        }
        for(int i = n-1;i>=0;i--){
            int curr = nums[i];
            while(!s.empty()&&curr>=s.top()){
                s.pop();
            }
            if(s.empty()){
                ans[i]=-1;
            }else{
                ans[i]=s.top();
            }
            s.push(curr);
        }
        return ans;
    }
};

// Method-2

class Solution { // Interview Standard Approach 
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> s;  // will store values

        for(int i = 2*n - 1; i >= 0; i--) {
            int curr = nums[i % n];

            while(!s.empty() && s.top() <= curr) {
                s.pop();
            }

            if(i < n) {  // only fill answer in first pass
                if(!s.empty()) {
                    ans[i] = s.top();
                }
            }

            s.push(curr);
        }

        return ans;
    }
};