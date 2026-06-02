#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>freq;
        for(char ch:tasks){
            freq[ch]++;
        }
        priority_queue<int>pq;
        for(auto it:freq){
            pq.push(it.second);
        }
        int ans = 0;
        while(!pq.empty()){
            vector<int>time;
            int cycle = n+1;
            while(!pq.empty() && cycle){
                int task = pq.top();
                pq.pop();
                if(task){
                    ans++;
                    time.push_back(task-1);
                }else{
                    ans+=cycle;
                    break;
                }
                cycle--;
            }
            for(int count:time){
                if(count){
                    pq.push(count);
                }
            }
            if(!pq.empty()){
                ans+=cycle;
            }
        }
        return ans;
    }
};