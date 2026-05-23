#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,int>idxS,idxT;
        for(int i = 0 ;i<s.size();i++){
            if(!idxS.count(s[i])){
                idxS[s[i]]=i;
            }
            if(!idxT.count(t[i])){
                idxT[t[i]]=i;
            }
            if(idxS[s[i]]!=idxT[t[i]]){
                return false;
            }
        }
        return true;
    }
};