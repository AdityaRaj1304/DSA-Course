#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    char findTheDifference(string s, string t) {
        int freq1[26]={0} , freq2[26]={0};
        for(char ch:s){
            freq1[ch-'a']++;
        }
        for(char ch:t){
            freq2[ch-'a']++;
            if(freq2[ch-'a']>freq1[ch-'a']){
                return ch;
            }
        }
    }
};