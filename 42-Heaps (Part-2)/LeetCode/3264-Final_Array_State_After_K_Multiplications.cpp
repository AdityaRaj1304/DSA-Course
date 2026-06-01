#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    struct Compare{
        bool operator () (const pair<int,int>&a , const pair<int,int>&b) const{
            if(a.first==b.first){
                return a.second>b.second;
            }
            return a.first>b.first;
        }
    };
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,Compare>pq;
        int n = nums.size();
        for(int i =0;i<n;i++){
            pq.push({nums[i],i});
        }
        for(int i = 0; i<k;i++){
            auto temp = pq.top();
            pq.pop();
            temp.first*=multiplier;
            pq.push(temp);
        }
        while(!pq.empty()){
            nums[pq.top().second]=pq.top().first;
            pq.pop();
        }
        return nums;
    }
};