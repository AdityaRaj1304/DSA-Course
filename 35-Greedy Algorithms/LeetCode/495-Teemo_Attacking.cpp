#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int ans = duration;
        int prev = timeSeries[0]+duration-1;
        for(int i = 1 ;i<timeSeries.size();i++){
            int curr = timeSeries[i]+duration-1;
            if(prev>=timeSeries[i]){
                ans+=curr-prev;
            }else{
                ans+=duration;
            }
            prev=curr;
        }
        return ans;
    }
};