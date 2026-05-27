#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSpecialChars(string word) {
        int ans = 0;
        vector<int>score(26,0);
        unordered_map<char,int>m;
        for(char ch:word){
            if(ch>='a' && ch<='z'){
                m[ch]++;
            }else{
                char temp = (ch-'A')+'a';
                if(m.count(temp)){
                    if(m[temp]>0 && score[ch-'A']!=1){
                        score[ch-'A']=2;
                        m[temp]--;
                        if(m[temp]==0){
                            m.erase(temp);
                        }
                    }else{
                        score[ch-'A']=1;
                    }
                }
            }
        }

        for(int num :score){
            if(num==2 && m[num+'a']==0){
                ans++;
            }
        }
        return ans;
    }
};


class Solution {
public:
    int numberOfSpecialChars(string word) {
        int ans =0;
        vector<int>score(26,0);
        unordered_set<char>lower,upper;
        for(char ch:word){
            if(ch>='a' && ch<='z'){
                if(upper.count((ch-'a')+'A')){
                    score[ch-'a']=1;
                }else{
                    lower.insert(ch);
                }
            }else{
                char temp = (ch-'A')+'a';
                upper.insert(ch);
                if(lower.count(temp)){
                    if(score[ch-'A']!=1){
                        score[ch-'A']=2;
                    }
                }else{
                    score[ch-'A']=1;
                }
            }
        }
        for(int num:score){
            if(num==2){
                ans++;
            }
        }
        return ans;
    }
};