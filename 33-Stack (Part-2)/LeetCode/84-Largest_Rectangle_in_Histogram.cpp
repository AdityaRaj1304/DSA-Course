#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>s;
        int n = heights.size();
        vector<int>nsl(n,0) , nsr(n,0);
        
        for(int i = 0 ;i<n;i++){
            while(!s.empty() && heights[i]<=heights[s.top()]){
                s.pop();
            }
            if(!s.empty()){
                nsl[i]=s.top();
            }else{
                nsl[i]=-1;
            }
            s.push(i);
        }

        while(!s.empty()){
            s.pop();
        }

        for(int i = n-1 ;i>=0 ;i--){
            while(!s.empty() && heights[i]<=heights[s.top()]){
                s.pop();
            }
            if(!s.empty()){
                nsr[i]=s.top();
            }else{
                nsr[i]=n;
            }
            s.push(i);
        }
        int ans = 0;
        for(int i = 0 ;i<n;i++){
            int height = heights[i];
            int width = nsr[i] - nsl[i] -1;
            int area = height * width;
            ans = max(area, ans);
        }
        return ans;
    }
};