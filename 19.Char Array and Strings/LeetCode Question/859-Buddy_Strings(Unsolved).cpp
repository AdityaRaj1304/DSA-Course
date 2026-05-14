#include<iostream>
#include<string>
#include<vector>
using namespace std ;
class Solution {
public:
    bool buddyStrings(string s, string goal) {//Unsolved
        if(s==goal){
            return false ;
        }
        if(s.length()!=goal.length()){
            return false ;
        }
        int count1[26] , count2[26];
        for(int i = 0 ; i < s.length();i++){
            int index1 = s[i]-'a';
            int index2 = goal[i]-'a';
            count1[index1]++;
            count2[index2]++;
        }
        for(int i = 0 ; i < 26 ; i++){
            if(count1[i]!=count2[i]){
                return false;
            }
        }
        return true ;
    }
};