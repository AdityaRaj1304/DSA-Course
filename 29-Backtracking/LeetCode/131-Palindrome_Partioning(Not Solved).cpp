#include<bits\stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>part;

        return ans;
    }
    bool palindrome(string s){
        int i = 0, j = s.length()-1;
        while(i<j){
            if(s[i++]!=s[j--]){
                return false;
            }
        }
        return true;
    }
    void permutations(string s , int pos , vector<string>str,vector<vector<string>>ans){
        if(pos==s.length()){
            ans.push_back(str);
            return ;
        }
        

    }
};