#include<iostream>
#include<string>
#include<vector>
using namespace std ;
class Solution {
public:
    bool detectCapitalUse(string word) {
        vector<char>uppercase , lowercase;
        for(int i = 0 ; i < word.length(); i++){
            if(word[i]>='A'&&word[i]<='Z'){
                uppercase.push_back(word[i]);
            }
            if(word[i]>='a'&&word[i]<='z'){
                lowercase.push_back(word[i]);
            }
        }
        if(uppercase.size()==word.length()){
            return true;
        }
        if(lowercase.size()==word.length()){
            return true;
        }
        if(word[0]>='A'&&word[0]<='Z'){
                for(int i = 1 ; i <word.length();i++){
                    if(!(word[i]>='a'&&word[i]<='z')){
                        return false;
                    }
                }
                return true ;
            }
            return false ;
    }
};
//More Cleaner Approach both these methods have same time complexity 
class Solution {
public:
    bool detectCapitalUse(string word) {
        int upper = 0;

        for (char c : word) {
            if (c >= 'A' && c <= 'Z') {
                upper++;
            }
        }

        if (upper == word.length()) return true;                  // ALL CAPS
        if (upper == 0) return true;                              // all lowercase
        if (upper == 1 && word[0] >= 'A' && word[0] <= 'Z') return true; // First capital only

        return false;
    }
};
