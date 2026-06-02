#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int fillCups(vector<int>& amount) {
        priority_queue<int>pq(amount.begin(),amount.end());
        int ans = 0;
        while(pq.top()){
            ans++;
            int first = pq.top();
            first--;
            pq.pop();
            if(pq.top()){
                int second = pq.top();
                pq.pop();
                second--;
                pq.push(first);
                pq.push(second);
            }else{
                return ans + first;
            }
        }
        return ans;
    }
};