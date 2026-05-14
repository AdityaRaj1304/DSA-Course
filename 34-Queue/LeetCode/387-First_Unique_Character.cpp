#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        queue<int>q;
        int freq[26]={0};
        int ans = 0;
        for(int i=0 ; i<s.size();i++){
            q.push(i);
            freq[s[i]-'a']++;
            while(!q.empty() && freq[s[q.front()]-'a']>1){
                q.pop();
            }
            if(q.empty()){
                ans = -1;
            }else{
                ans = q.front();
            }
        }
        return ans;
    }
};


