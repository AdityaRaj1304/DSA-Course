#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.size();
        int idx=0;
        for(int i = 0 ;i<t.size();i++){
            if(s[idx]==t[i]){
                idx++;
            }
            if(idx==n){
                return true;
            }
        }
        return idx==n;
    }
};