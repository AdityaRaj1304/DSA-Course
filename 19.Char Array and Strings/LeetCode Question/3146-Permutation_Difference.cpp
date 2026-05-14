#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findPermutationDifference(string s, string t) {
        int idx[26]={0};
        int ans = 0;
        for(int i = 0 ;i<s.size();i++){
            idx[s[i]-'a']=i;
        }
        for(int i = 0 ;i<t.size();i++){
            ans+=abs(i-idx[t[i]-'a']);
        }
        return ans;
    }
};