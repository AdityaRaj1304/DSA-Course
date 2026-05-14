#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string decodeMessage(string key, string message) {
        char mapping[26]={0};
        char temp = 'a';
        string ans;
        for(char ch :key){
            if(ch != ' ' && mapping[ch-'a']==0){
                mapping[ch-'a']=temp;
                temp++;
            }
        }
        for(char ch :message){
            if(ch != ' '){
                ans+=mapping[ch-'a'];
            }else{
                ans+=' ';
            }
        }
        return ans;
    }
};