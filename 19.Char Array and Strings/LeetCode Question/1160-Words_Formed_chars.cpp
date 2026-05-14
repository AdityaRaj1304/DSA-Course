#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int freq[26]={0};
        int ans =0;
        for(char ch:chars){
            freq[ch-'a']++;
        }
        for(string s:words){
            int f[26]={0};
            bool count = true;
            for(char ch : s){
                f[ch-'a']++;
                if(f[ch-'a']>freq[ch-'a']){
                    count = false;
                    break;
                }
            }
            if(count){
                ans+=s.size();
            }
        }
        return ans;
    }
};