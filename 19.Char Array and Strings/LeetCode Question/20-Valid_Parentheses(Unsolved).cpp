#include<iostream>
#include<string>
#include<vector>
using namespace std ;
class Solution {
public:
    bool isValid(string s) {
        int n = s.length();
        for(int i = 0 ; i < n ; i++){
            if(s[i]=='('){
                if(s[i+1]==')'){
                    continue ;
                }else{
                    return false;
                }
            }
            if(s[i]=='{'){
                if(s[i+1]=='}'){
                    continue ;
                }else{
                    return false;
                }
            }
            if(s[i]=='['){
                if(s[i+1]==']'){
                    continue ;
                }else{
                    return false;
                }
            }
        }
        return true ;
    }
};