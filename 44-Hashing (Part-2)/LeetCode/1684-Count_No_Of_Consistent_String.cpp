#include<bits/stdc++.h>
using namespace std;

//Unordered Map
class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_map<char,int>freq;
        int ans =0;
        for(char ch:allowed){
            freq[ch]++;
        }
        bool temp =true;
        for(string s:words){
            for(char ch:s){
                temp=true;
                if(!freq.count(ch)){
                    temp=false;
                    break;
                }
            }
            if(temp){
                ans++;
            }
        }
        return ans;
    }
};


//Unordered Set
class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char>freq(allowed.begin(),allowed.end());
        int ans =0;
        for(string s:words){
            bool temp=true;
            for(char ch:s){
                if(!freq.count(ch)){
                    temp=false;
                    break;
                }
            }
            if(temp){
                ans++;
            }
        }
        return ans;
    }
};