#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        sort(intervals.begin(),intervals.end(),[](auto &a , auto&b){
            return a[0]<b[0]
        });
        int currStart=intervals[0][0];
        int currEnd = intervals[0][1];
        for(int i  = 1;i<intervals.size();i++){
            if(currEnd>=intervals[i][0]){
                currEnd=max(currEnd,intervals[i][1]);
            }else{
                ans.push_back({currStart,currEnd});
                currStart=intervals[i][0];
                currEnd=intervals[i][1];
            }
        }
        ans.push_back({currStart,currEnd});
        return ans;
    }
};