#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct Compare{
        bool operator () (const pair<char,int>& a , const pair<char,int>& b) const{
            return a.second<b.second;
        }
    };
    string frequencySort(string s) {
        string ans = "";
        unordered_map<char,int>freq;
        for(char&ch:s){
            freq[ch]++;
        }
        priority_queue<pair<char,int>,vector<pair<char,int>>,Compare>pq;
        for(auto&m :freq){
            char ch = m.first;
            int count = m.second;
            pq.push({ch,count});
        }
        while(!pq.empty()){
            string temp(pq.top().second,pq.top().first);
            ans+=temp;
            pq.pop();
        }
        return ans;
    }
};