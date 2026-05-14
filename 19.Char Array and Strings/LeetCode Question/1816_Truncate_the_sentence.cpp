#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string truncateSentence(string s, int k) {
        string ans ;
        int count = 0;
        for(char ch:s){
            if(count==k){
                ans.pop_back();
                return ans;
            }
            if(ch==' '){
                count++;
                ans.push_back(ch);
            }else{
                ans.push_back(ch);
            }
        }
        return ans;
    }
};