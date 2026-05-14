#include<iostream>
#include<string>
using namespace std ;
#include<vector>
class Solution {
public:
    string toLowerCase(string s) {
        for(int i = 0 ; i < s.size()-1 ; i++){
            if(s[i]>='A'&&s[i]<='Z'){
                s[i]=s[i]-'A'+'a';
            }
        }
        return s;
    }
};