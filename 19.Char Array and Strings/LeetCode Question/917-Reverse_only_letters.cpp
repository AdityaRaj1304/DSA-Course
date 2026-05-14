#include<iostream>
#include<string>
#include<vector>
using namespace std ;
class Solution {
public:
    string reverseOnlyLetters(string s) {
        int st = 0 , end = s.length()-1 ;
        while(st< end){
            bool stletter = ((s[st]>='a'&&s[st]<='z')||(s[st]>='A'&&s[st]<='Z'));
            bool endletter = ((s[end]>='a'&&s[end]<='z')||(s[end]>='A'&&s[end]<='Z'));
            if(stletter && endletter){
                swap(s[st++],s[end--]);
            }
            else if (!stletter){
                st++;
            }else{
                end--;
            }
        }
        return s ;
    }
};