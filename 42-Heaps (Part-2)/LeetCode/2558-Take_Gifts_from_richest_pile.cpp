#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int>pq(gifts.begin(),gifts.end());
        long long ans= 0;
        for(int i =0;i<k;i++){
            int gifts = sqrt(pq.top());
            pq.pop();
            pq.push(gifts);
        }
        while(!pq.empty()){
            ans+=pq.top();
            pq.pop();
        }
        return ans;
    }
};