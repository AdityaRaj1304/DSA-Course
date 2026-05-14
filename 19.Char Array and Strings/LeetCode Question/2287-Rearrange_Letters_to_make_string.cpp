#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int rearrangeCharacters(string s, string target) { // TC= n*m
        int freq[26]={0};
        int ans =0;
        for(char ch:s){
            freq[ch-'a']++;
        }
        bool valid=true;
        while(valid){
            for(char ch:target){
                freq[ch-'a']--;
                if(freq[ch-'a']<0){
                    valid=false;
                }
            }
            if(valid){
                ans++;
            }else{
                return ans;
            }
        }
        return ans;
    }
};


// Optimal Solution 
class Solution {
public:
    int rearrangeCharacters(string s, string target) { // TC = n+m

        int freqS[26] = {0};
        int freqT[26] = {0};

        for(char ch : s) freqS[ch-'a']++;
        for(char ch : target) freqT[ch-'a']++;

        int ans = INT_MAX;

        for(int i = 0; i < 26; i++){
            if(freqT[i] > 0){
                ans = min(ans, freqS[i] / freqT[i]);
            }
        }

        return ans;
    }
};