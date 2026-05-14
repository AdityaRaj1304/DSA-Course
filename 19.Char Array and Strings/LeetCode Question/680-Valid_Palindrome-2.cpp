#include<iostream>
#include<string>
using namespace std ;
class Solution {
public:
    bool pal(string s , int st , int end){
        while(st < end){
            if(s[st++]!=s[end--]){
                return false ;
            }
        }
        return true ;
    }
    bool validPalindrome(string s) {
        int start = 0 , end = s.length()-1;
        while(start < end){
            if(s[start]!=s[end]){
                return pal(s , start+1 , end) || pal(s,start,end-1);
            }
            start++;
            end--;
        }
        return true ;
    }
};