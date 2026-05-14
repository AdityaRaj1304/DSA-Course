#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int freq[26]={0};
        int temp[26]={0};
        int ans =INT_MAX;
        string s = "balloon";
        for(char ch :text){
            freq[ch-'a']++;
        }
        for(char ch :s){
            temp[ch-'a']++;
        }
        for(int i = 0 ;i<26;i++){
            if(temp[i]>0){
                ans = min(ans,freq[i]/temp[i]);
            }
        }
        return ans;
    }
};