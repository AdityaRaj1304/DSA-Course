#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string>ans;
        unordered_map<string,int>freq;
        string temp ="";
        for(char ch:s1){
            if(ch == ' '){
                freq[temp]++;
                temp="";
            }else{
                temp+=ch;
            }
        }
        freq[temp]++;
        temp="";
        for(char ch:s2){
            if(ch == ' '){
                freq[temp]++;
                temp="";
            }else{
                temp+=ch;
            }
        }
        freq[temp]++;
        for(auto it:freq){
            if(it.second==1){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};