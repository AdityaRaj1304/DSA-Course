#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string>m;
        unordered_map<string,char>rev;
        int idx =-1;
        string temp ="";
        for(char ch:s){
            if(ch==' '){
                idx++;
                if(m.count(pattern[idx])){
                    if(idx >= pattern.size()) {
                        return false;
                    }   
                    if(temp!=m[pattern[idx]]){
                        return false;
                    }
                }else{
                    if(rev.count(temp)){
                        return false;
                    }
                    m[pattern[idx]]=temp;
                    rev[temp]=pattern[idx];
                }
                temp="";
            }else{
                temp+=ch;
            }
        }
        idx++;
        if(idx >= pattern.size()) {
            return false;
        }
        if(m.count(pattern[idx])) {
            if(temp != m[pattern[idx]]) {
                return false;
            }
        } 
        else {
            if(rev.count(temp)) {
                return false;
            }
            m[pattern[idx]] = temp;
            rev[temp] = pattern[idx];
        }
        return idx+1 == pattern.length();
    }
};