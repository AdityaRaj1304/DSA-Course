#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct comparePair{
        bool operator () (const pair<int,vector<int>>&p1,const pair<int,vector<int>>&p2) const {
            return p1.first>p2.first;
        }
    };
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,vector<int>>,vector<pair<int,vector<int>>>,comparePair>pq;
        vector<vector<int>>ans;
        for(auto &v:points){
            int x = v[0] , y = v[1];
            int distSq = (x*x) + (y*y);
            pq.push(make_pair(distSq,v));
        }
        for(int i = 0;i<k;i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};


//Optimal Solution - Using Max Heap - SC= O(k) instead of O(n)
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,vector<int>>>pq;
        vector<vector<int>>ans;
        for(auto&v:points){
            int x = v[0] , y = v[1];
            int distSq = (x*x) + (y*y);
            pq.push({distSq,v});
            if(pq.size()>k){
                pq.pop();
            }
        }
        for(int i = 0;i<k;i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
