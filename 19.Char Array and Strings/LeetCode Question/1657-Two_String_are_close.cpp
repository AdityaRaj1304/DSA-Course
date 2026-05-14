#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std ;
class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.length()!=word2.length()){
            return false;
        }
        int count1[26] = {0}, count2[26] = {0};
        bool check1[26] = {false} , check2[26] = {false} ;
        for(int i = 0 ; i < word1.length();i++){
            int index = word1[i]-'a';
            count1[index]++;
            check1[index]=true;
        }
        for(int i = 0 ; i < word2.length();i++){
            int index = word2[i]-'a';
            count2[index]++;
            check2[index]=true;
        }
        sort(count1,count1+26);
        sort(count2, count2+26);
        for(int i = 0 ; i < 26 ; i++){
            if(count1[i]!=count2[i] || check1[i]!=check2[i]){
                return false;
            }
        }
        return true ;
    }
};