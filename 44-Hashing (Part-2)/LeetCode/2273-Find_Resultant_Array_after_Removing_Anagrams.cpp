#include<bits/stdc++.h>
using namespace std;

//Hash Map
class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string>ans;
        vector<unordered_map<char,int>>freq;
        for(int i = 0 ;i<words.size();i++){
            for(char ch:words[i]){
                freq[i][ch]++;
            }
        }
        ans.push_back(words[0]);
        for(int i = 1;i<freq.size();i++){
            if(freq[i]!=freq[i-1]){
                ans.push_back(words[i]);
            }
        }
        return ans;
    }
};

//Optimal Solution - Sorting 
class Solution {
public:
    bool anagram(string a , string b){
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        return a==b;
    }
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string>ans;
        ans.push_back(words[0]);
        for(int i =1;i<words.size();i++){
            if(!anagram(words[i],words[i-1])){
                ans.push_back(words[i]);
            }
        }
        return ans;
    }
};



