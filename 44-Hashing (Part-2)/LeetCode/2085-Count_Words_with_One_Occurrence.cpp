#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        int ans =0;
        unordered_map<string,int>m1,m2;
        for(string s:words1){
            m1[s]++;
        }
        for(string s:words2){
            m2[s]++;
        }
        for(auto it:m1){
            if((it.second==1)&&(m2.count(it.first))&&(m2[it.first]==1)){
                ans++;
            }
        }
        return ans;
    }
};