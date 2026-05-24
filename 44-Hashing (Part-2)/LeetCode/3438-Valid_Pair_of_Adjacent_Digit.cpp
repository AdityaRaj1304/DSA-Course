#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string findValidPair(string s) {
        unordered_map<char,int>freq;
        string ans ="";
        for(char ch:s){
            freq[ch]++;
        }
        for(int i = 1;i<s.size();i++){
            if(((s[i-1]-'0')==freq[s[i-1]])&&((s[i]-'0')==freq[s[i]])&&s[i-1]!=s[i]){
                ans+=s[i-1];
                ans+=s[i];
                break;
            }
        }
        return ans;
    }
};