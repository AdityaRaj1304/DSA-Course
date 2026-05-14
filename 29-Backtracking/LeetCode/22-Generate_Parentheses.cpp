#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string s ;
        helper(n,0,0,s,ans);
        return ans;
    }
    void helper(int n , int left , int right , string s,vector<string>&ans){
        if(s.size()==2*n){
            ans.push_back(s);
            return;
        }
        if(left < n){
            helper(n,left+1,right,s+'(',ans);
        }
        if(right<left){
            helper(n,left,right+1,s+')',ans);
        }
    }
};
