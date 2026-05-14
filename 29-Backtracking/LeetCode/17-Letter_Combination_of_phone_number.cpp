#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        string str ="";
        vector<string>ans;
        vector<vector<char>> letters = {
        {'a','b','c'}, {'d','e','f'}, {'g','h','i'},
        {'j','k','l'}, {'m','n','o'},
        {'p','q','r','s'}, {'t','u','v'},
        {'w','x','y','z'}
    };
        solution(digits,str,0,ans,letters);
        return ans;
    }
    void solution(string &digits,string &comb, int pos , vector<string>&ans,vector<vector<char>>&letter){
        if(pos==digits.length()){
            ans.push_back(comb);
            return;
        }
        int idx = digits[pos]-'2';
        for(int j = 0 ; j<letter[idx].size();j++){
            comb.push_back(letter[idx][j]);
            solution(digits,comb,pos+1,ans,letter);
            comb.pop_back();
        }
    }
};