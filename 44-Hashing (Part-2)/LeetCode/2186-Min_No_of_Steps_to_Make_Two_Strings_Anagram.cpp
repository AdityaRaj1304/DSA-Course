#include<bits/stdc++.h>
using namespace std;


//Hash Map
class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int>freq;
        int ans =0;
        for(char ch:s){
            if(freq.count(ch)){
                freq[ch]++;
            }else{
                freq[ch]=1;
            }
        }
        for(char ch:t){
            if(freq.count(ch)){
                freq[ch]--;
            }else{
                freq[ch]=-1;
            }
        }
        for(auto it:freq){
            if(it.second!=0){
                ans+=abs(it.second);
            }
        }
        return ans;
    }
};

//Optimal Solution - Using simple char array

class Solution {
public:
    int minSteps(string s, string t) {
        vector<int>freq(26,0);
        int ans =0;
        for(char ch:s){
            freq[ch-'a']++;
        }
        for(char ch:t){
            freq[ch-'a']--;
        }
        for(int num:freq){
            if(num!=0){
                ans+=abs(num);
            }
        }
        return ans;
    }
};